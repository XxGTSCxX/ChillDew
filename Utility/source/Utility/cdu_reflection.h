#pragma once

#include "cdu_core.h"
#include "cdu_type.h"
#include "cdu_stlcontainers.h"
#include "cdu_singleton.inl"

#include <cstdint>
#include <variant>
#include <string>
#include <string_view>
#include <tuple>

namespace chilldew::utility::reflection
{

    namespace details
    {
        template <typename value_t> static inline bool type_is_reflected = false;
        template <typename value_t> static inline bool enum_is_reflected = false;

        template <typename ptr_to_mem_t>
        struct ptr_to_mem_info
        {
            using object_t = void;
            using member_t = void;
            using return_t = void;
            using param_ts = void;

            static constexpr type::id_t object_id       = type::invalid_id;
            static constexpr type::id_t member_id       = type::invalid_id;
            static constexpr type::id_t return_id       = type::invalid_id;
            static constexpr bool       is_ptr_to_mem   = false;
            static constexpr bool       is_mem_function = false;
        };

        template <typename obj_t, typename mem_t>
        struct ptr_to_mem_info<mem_t obj_t::*&>
        {
            using object_t = obj_t;
            using member_t = mem_t;
            using return_t = void;
            using param_ts = void;

            static constexpr type::id_t object_id       = type::id<obj_t>();
            static constexpr type::id_t member_id       = type::id<mem_t>();
            static constexpr type::id_t return_id       = type::invalid_id;
            static constexpr bool       is_ptr_to_mem   = true;
            static constexpr bool       is_mem_function = false;
        };

        template <typename obj_t, typename ret_t, typename ... param_ts>
        struct ptr_to_mem_info<ret_t (obj_t::*&)(param_ts...)>
        {
            using object_t = obj_t;
            using member_t = void;
            using return_t = ret_t;
            using param_ts = std::tuple<param_ts...>;

            static constexpr type::id_t object_id       = type::id<obj_t>();
            static constexpr type::id_t member_id       = type::invalid_id;
            static constexpr type::id_t return_id       = type::id<ret_t>();
            static constexpr bool       is_ptr_to_mem   = true;
            static constexpr bool       is_mem_function = true;
        };
    }

    template <typename ptr_to_mem_t> static constexpr bool is_ptm_v          = details::ptr_to_mem_info<ptr_to_mem_t>::is_ptr_to_mem;
    template <typename ptr_to_mem_t> static constexpr bool is_ptm_function_v = details::ptr_to_mem_info<ptr_to_mem_t>::is_mem_function;

    template <typename ptr_to_mem_t> using ptm_t                 = typename details::ptr_to_mem_info<ptr_to_mem_t>::member_t;
    template <typename ptr_to_mem_t> using ptm_function_return_t = typename details::ptr_to_mem_info<ptr_to_mem_t>::return_t;
    template <typename ptr_to_mem_t> using ptm_function_param_ts = typename details::ptr_to_mem_info<ptr_to_mem_t>::param_ts;

    // The very base types that are handled as a singluar entry that other types
    // will contain and reflect from.
    using data_t = std::variant
    <
          char
        , short
        , int
        , long
        , long long

        , unsigned char
        , unsigned short
        , unsigned int
        , unsigned long
        , unsigned long long

        , float
        , double
        , long double

        , std::string
    >;

    // The information per class that can be used to extract the actual data in
    // the object of the given class.
    template <typename value_t>
    struct blueprint : std::false_type
    {};

    // This is working on the assumption that the strings come from string
    // literals
    struct member_info
    {
        std::string_view m_path; // chilldew::object1::m_member_name1/chilldew::object2::m_member_name1
        cdu::type::id_t  m_type_id;
        data_t           m_data;
    };

    struct blueprint_base
    {
        cdu::type::id_t          m_type_id;
        cdu::vector<member_info> m_entries;

        template <typename ptr_to_mem_t>
        void register_member(std::string_view const& variable_name, ptr_to_mem_t&& ptr_to_mem)
        {
            static_assert(is_ptm_v<ptr_to_mem_t>, "registered variable has to be a pointer to member");

            if constexpr (!is_ptm_function_v<ptr_to_mem_t>)
            {
                // Ptr to function member
            }
            else
            {
                // Ptr to variable member
            }
        }
    };



}
