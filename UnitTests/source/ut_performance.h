#pragma once

#include "ut_core.h"
#include <functional> // std::function

namespace unit_tests
{

    struct performance final
    {
        static double time_test(std::function<void()> const& function, bool suppress_print = false);
        static void   test_division();
    };

}
