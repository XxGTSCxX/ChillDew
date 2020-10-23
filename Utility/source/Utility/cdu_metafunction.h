#pragma once

#include <utility>
#include <array  >
#include <vector >

#if __cplusplus <= 201703L
namespace std
{
    template <typename T>
    using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
}
#endif

namespace chilldew::utility
{

    // -------------------------------------------------------------------------
    // is_std_array
    // -------------------------------------------------------------------------

    template <typename type_t>
    struct is_std_array : std::false_type
    {};

    template <typename elem_t, std::size_t size_v>
    struct is_std_array<std::array<elem_t, size_v>> : std::true_type
    {};

    template <typename type_t>
    static constexpr bool is_std_array_v = is_std_array::value;

    // -------------------------------------------------------------------------
    // is_array
    // -------------------------------------------------------------------------

    template <typename type_t>
    struct is_array
    {
        static constexpr bool value = std::is_array_v<type_t> || is_std_array_v<type_t>;
    };

    template <typename type_t>
    static constexpr bool is_array_v = is_array<type_t>::value;

    // -------------------------------------------------------------------------
    // is_vector
    // -------------------------------------------------------------------------

    template <typename type_t>
    struct is_vector : std::false_type
    {};

    template <typename elem_t>
    struct is_vector<std::vector<elem_t>> : std::true_type
    {};

    template <typename type_t>
    static constexpr bool is_vector_v = is_vector::value;

}
