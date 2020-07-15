#pragma once

#include <cstddef> // std::size_t

namespace unit_tests
{

  struct math final
  {
    template <std::size_t dimension_v>
    static void test_vec();

    template <> static void test_vec<2>();
    template <> static void test_vec<3>();
    template <> static void test_vec<4>();
  };

}
