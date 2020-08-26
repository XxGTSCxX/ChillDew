#pragma once

#include "ut_core.h"
#include <functional> // std::function

namespace unit_tests
{

    struct performance final
    {
        static void test_division_vs_multiplication();
        static void test_index_vs_ptr();
        static void test_conditional_vs_multiplication();
        static void test_if_vs_tenary();
        static void test_virtual_vs_static();

    private:

        static double time_test(std::function<void()> const& function, bool suppress_print = false);
    };

}
