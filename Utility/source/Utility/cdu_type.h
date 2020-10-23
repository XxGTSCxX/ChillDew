#pragma once

#include "cdu_core.h"
#include <limits>
#include <unordered_map>
#include <unordered_set>

#if (defined(__GNUC__) && GCC_VERSION >= 100000) || defined(_MSC_VER)
    #define SYNTAX_VER 1
#else
    #define SYNTAX_VER 0
#endif

namespace chilldew::utility
{

    namespace detail
    {
        // This function is used to get the string literal for the templated
        // type. It can then be trimmed using string_view to get the type name.
        template <typename type_t>
        constexpr TCHAR const* function_signature() noexcept
        {
#if defined(__GNUC__) || defined(__clang__)
            return CD_L_WRAPPER(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
            return CD_L_WRAPPER(__FUNCSIG__);
#else
            #error unsupported compiler (only GCC, clang and MSVC are supported)
#endif
        }

        static constexpr std::size_t hash_p = static_cast<std::size_t>(31     );
        static constexpr std::size_t hash_m = static_cast<std::size_t>(1e9 + 9);

        template <typename val_t>
        constexpr std::size_t hasher(val_t const* p_val, std::size_t num_values = 1, std::size_t curr = 0, std::size_t pow = 1) noexcept
        {
            if (num_values)
            {
                return hasher(p_val + 1, num_values - 1, (curr + (*p_val - 'a' + 1) * pow) % hash_m, (pow * hash_p) % hash_m);
            }

            return curr;
        }

        inline constexpr std::size_t find(cd::string_view const& view, TCHAR character, std::size_t offset = 0)
        {
#ifdef __clang__
            for (std::size_t pos = offset; pos < view.size(); ++pos)
                if (view[pos] == character)
                    return pos;
            return std::string_view::npos;
#else
            return view.find(character, offset);
#endif
        }
    }

    struct type
    {
        using id_t = std::size_t;

        static constexpr id_t            invalid_id   = 0;
        static constexpr cd::string_view invalid_name = CD_L("");

        template <typename type_t>
        static constexpr cd::string_view name() noexcept
        {
            constexpr cd::string_view funcsig = detail::function_signature<type_t>();

#if SYNTAX_VER == 0
            constexpr std::size_t start = detail::find(funcsig, CD_L('=')       ) + 2;
            constexpr std::size_t end   = detail::find(funcsig, CD_L(']'), start);
            return funcsig.substr(start, end - start);
#elif SYNTAX_VER == 1
            constexpr std::size_t t_start = detail::find(funcsig, CD_L('<')         ) + 1;
            constexpr std::size_t n_start = detail::find(funcsig, CD_L(' '), t_start);
            constexpr std::size_t end     = detail::find(funcsig, CD_L('>')         );

            if constexpr (n_start < end)
            {
#if _MSC_VER <= 1916 // Because for some reason in VS 2017 .find(' ') returns
                     // one character off.
                if constexpr (funcsig[t_start] == 's') return funcsig.substr(n_start + 2, end - n_start - 2);
                else                                   return funcsig.substr(n_start + 1, end - n_start - 1);
#else
                return funcsig.substr(n_start + 1, end - n_start - 1);
#endif
            }
            else
                return funcsig.substr(t_start, end - t_start);
#else
            #error unsupported function signature syntax
#endif
        }

        template <typename type_t>
        static constexpr id_t id() noexcept
        {
            constexpr cd::string_view name = type::name<type_t>();
            return detail::hasher(name.data(), name.size());
        }

        template <typename type_t>
        static bool register_type()
        {
            if (!type::is_registered<type_t>())
            {
                m_registered_types.emplace(type::id  <type_t>(), type::name<type_t>());
                m_name_list       .emplace(type::name<type_t>(), type::id  <type_t>());
            }
            return true;
        }

        template <typename base_t, typename derived_t>
        static bool register_parent()
        {
            static_assert(std::is_base_of_v<base_t, derived_t>, "derived_t must inherit from base_t");

            type::register_type<base_t   >();
            type::register_type<derived_t>();
            m_registered_types[type::id<derived_t>()].m_base_types.emplace(type::id<base_t>());

            return true;
        }

        template <typename type_t>
        static bool is_registered()
        {
            return type::is_registered(type::id<type_t>());
        }

        static bool            is_base_of   (id_t            base_id  , id_t derived_id);
        static bool            is_registered(id_t            type_id                   );
        static bool            is_registered(cd::string_view type_name                 );
        static cd::string_view name         (id_t            type_id                   );
        static id_t            id           (cd::string_view type_name                 );

    private:

        struct type_info;

        using base_types_t       = std::unordered_set<id_t                 >;
        using registered_types_t = std::unordered_map<id_t      , type_info>;
        using name_list_t        = std::unordered_map<cd::string, id_t     >;

        struct type_info
        {
            type_info() = default;
            type_info(cd::string_view name)
            : m_name{ name }
            {}

            cd::string   m_name      {};
            base_types_t m_base_types{};
        };

        static inline registered_types_t m_registered_types{};
        static inline name_list_t        m_name_list       {};
    };

    template <type::id_t type_id_v>
    struct get_type;

}

#define CD_MAKE_GET_TYPE(type_t)             \
    template <>                              \
    struct cdu::get_type<type::id<type_t>()> \
    {                                        \
        using type = type_t;                 \
    };

#undef SYNTAX_VER
