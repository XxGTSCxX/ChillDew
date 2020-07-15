#pragma once

#include "cdu_core.h"

namespace chilldew::utility
{

    namespace detail
    {
        // This function is used to get the string literal for the templated
        // type. It can then be trimmed using string_view to get the type name.
        template <typename T>
        constexpr TCHAR const* function_signature()
        {
#if defined(__GNUC__) || defined(__clang__)
            return CD_STRING_W(__PRETTY_FUNCTION__);
#elif defined(_MSC_VER)
            return CD_STRING_W(__FUNCSIG__);
#else
            #error unsupported compiler (only GCC, clang and MSVC are supported)
#endif
        }
    }

    struct type
    {
        using id_t = std::size_t;

        template <typename T>
        static constexpr cd::string_view name() noexcept
        {
            static constexpr cd::string_view funcsig = detail::function_signature<T>();
            static constexpr std::size_t     start   = funcsig.find('<') + 1;
            static constexpr std::size_t     space   = funcsig.find(' ', start);

            // Checking if we can trim away the "struct" or "class" part of the
            // name.
            if constexpr (space != cd::string_view::npos)
                return funcsig.substr(space + 1, funcsig.find('>') - space - 1);
            else
                return funcsig.substr(start, funcsig.find('>') - start);
        }

        template <typename T>
        static constexpr id_t id() noexcept
        {
            static constexpr id_t p = static_cast<id_t>(31     );
            static constexpr id_t m = static_cast<id_t>(1e9 + 9);

            id_t hash_value = 0;
            id_t p_pow      = 1;

            for (TCHAR c : type::name<T>())
            {
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
                p_pow      = (p_pow * p) % m;
            }

            return hash_value;
        }
    };

}
