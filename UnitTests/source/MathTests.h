#pragma once

#include <cstddef> // std::size_t

namespace Tests
{

    class MathTests final
    {
    public:

        template <std::size_t dimension_v>
        static void TestVector();

        template <>
        static void TestVector<2>();

    private:

    };

}
