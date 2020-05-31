/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_MetaFunctions.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Attempting to mimic C++20's concepts. Referenced from Ivan Ho.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include <type_traits>
#include <utility>
#include <ostream>
#include <variant>

#define REQUIRES(x) typename = decltype(x)

// Defines the has_member meta function
// NOTE: This fails if there are more than one member with the same name
#define DEFINE_HAS_MEMBER(member)                                                \
    template <typename T>                                                        \
    class has_member_##member                                                    \
    {                                                                            \
    private:                                                                     \
                                                                                 \
        using RawType = std::remove_cvref_t<T>;                                  \
        using Yes     = std::uint8_t;                                            \
        using No      = std::uint16_t;                                           \
                                                                                 \
        template <typename C> static Yes& check(decltype(&C::member)) ;          \
        template <typename C> static No&  check(...);                            \
                                                                                 \
    public:                                                                      \
                                                                                 \
        static constexpr bool value = sizeof(check<RawType>(0)) == sizeof(Yes);  \
    };                                                                           \
                                                                                 \
    template <typename T>                                                        \
    static constexpr bool has_member_v_##member = has_member_##member<T>::value; \

#if __cplusplus <= 201703L
namespace std
{
    template <typename T>
    using remove_cvref_t = remove_cv_t<remove_reference_t<T>>;
}
#endif

namespace chilldew
{

    template<typename T, REQUIRES(std::declval<std::ostream&>() << std::declval<T&>())>
    constexpr bool is_printable_f()
    {
        return true;
    }

    template<typename T, typename ... Args>
    constexpr bool is_printable_f(Args...)
    {
        return false;
    }

    template<typename T, REQUIRES(std::declval<std::istream&>() >> std::declval<T&>())>
    constexpr bool is_readable_f()
    {
        return true;
    }

    template<typename T, typename ... Args>
    constexpr bool is_readable_f(Args...)
    {
        return false;
    }

    template<typename T>
    static constexpr bool is_printable_v = is_printable_f<T>();

    template<typename T>
    static constexpr bool is_readable_v = is_readable_f<T>();

    template<typename Container, typename Result = void, REQUIRES(std::declval<Container>().begin()), REQUIRES(std::declval<Container>().end())>
    using iterable = Result;

    template<typename Container>
    struct is_iterable
    {
    private:

        template<REQUIRES(std::declval<Container>().begin()), REQUIRES(std::declval<Container>().end())>
        static std::true_type test(Container const&);

        static std::false_type test(...);

    public:
        static constexpr bool value = decltype(is_iterable::test(std::declval<Container>()))::value;
    };

    template<typename T>
    constexpr bool is_iterable_v = is_iterable<T>::value;

    template<template<typename...> typename Base, typename Derived>
    struct is_template
    {
    private:
        template<class ...T>
        static decltype(static_cast<const Base<T...>&>(std::declval<Derived>()), std::true_type{})
            test(const Base<T...>&);

        static std::false_type test(...);
    public:
        static constexpr bool value = decltype(is_template::test(std::declval<Derived>()))::value;
    };

    template<template<typename...> typename Base, typename Derived>
    constexpr bool is_template_v = is_template<Base, Derived>::value;

    template<typename T, typename Result = void>
    using number = std::enable_if_t<std::is_arithmetic_v<T>, Result>;

    template <typename T, typename U>
    using is_not = std::enable_if_t<!std::is_same_v<std::decay_t<T>, std::decay_t<U>>>;

    template<typename ...T>
    struct all_arithmetic;

    template<typename Head, typename ... T>
    struct all_arithmetic<Head, T...>
    {
        static constexpr bool value = std::is_arithmetic_v<Head> && all_arithmetic<T...>::value;
    };

    template<>
    struct all_arithmetic<>
    {
        static constexpr bool value = true;
    };


    template<typename ... T>
    _INLINE_VAR constexpr bool all_arithmetic_v = all_arithmetic<T...>::value;

    template <typename T, typename ... Pack>
    struct is_in
    {
        static constexpr bool value = false;
    };

    template <typename T, typename U, typename ... Pack>
    struct is_in<T, U, Pack...>
    {
        static constexpr bool value = std::is_same_v<std::remove_cvref_t<T>, std::remove_cvref_t<U>> || is_in<T, Pack...>::value;
    };

    template <typename T, typename ... Pack>
    static constexpr bool is_in_v = is_in<T, Pack...>::value;

    template <size_t N, typename Type, typename ... List>
    struct index_of_aux
    {
        static constexpr size_t value = static_cast<size_t>(-1);
    };

    template <size_t N, typename Type1, typename Type2, typename ... Ts>
    struct index_of_aux<N, Type1, Type2, Ts...>
    {
        static constexpr size_t value = index_of_aux<N + 1, Type1, Ts...>::value;
    };

    template <size_t N, typename Type, typename ... Ts>
    struct index_of_aux<N, Type, Type, Ts...>
    {
        static constexpr size_t value = N;
    };

    template <typename Type, typename Tuple>
    struct index_of_type;

    template <typename Type, typename ... Ts>
    struct index_of_type<Type, std::tuple<Ts...>>
    {
        static constexpr size_t value = index_of_aux<0, Type, Ts...>::value;
    };

    template <typename T, typename VARIANT>
    struct is_in_variant; // Fails if VARIANT is not a variant

    template <typename T, typename ... V_Ts>
    struct is_in_variant<T, std::variant<V_Ts...>>
    {
        static constexpr bool value = is_in_v<T, V_Ts...>;
    };

    template <typename T, typename VARIANT>
    static constexpr bool is_in_variant_v = is_in_variant<T, VARIANT>::value;

    template <typename T, typename ... Ts>
    struct is_all_same
    {
        static constexpr bool value = std::conjunction_v<std::is_same<T, Ts>...>;
    };

    template <typename T, typename ... Ts>
    static constexpr bool is_all_same_v = is_all_same<T, Ts...>::value;

}
