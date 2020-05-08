/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Quaternion.h
  \author  Gabrielle Tan Suan Choo
  \brief
    General implementation of Quaternion class. Quaternions are used for
    rotations and orientations.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_Math.h"
#include "CD_Swizzle.inl" // CD::Swizzle
#include "CD_Degree.inl"  // CD::Degree
#include <array>           // std::array

namespace CD
{

    template <typename T>
    struct CD_API Quaternion final
    {
    public:

        union
        {
            std::array<T, 4> _array{};

            struct
            {
                T x;
                T y;
                T z;
                T w;
            };

            Swizzle<Quaternion, T, 4, 0, 1      > xy;
            Swizzle<Quaternion, T, 4, 0, 2      > xz;
            Swizzle<Quaternion, T, 4, 0, 3      > xw;
            Swizzle<Quaternion, T, 4, 1, 0      > yx;
            Swizzle<Quaternion, T, 4, 1, 2      > yz;
            Swizzle<Quaternion, T, 4, 1, 3      > yw;
            Swizzle<Quaternion, T, 4, 2, 0      > zx;
            Swizzle<Quaternion, T, 4, 2, 1      > zy;
            Swizzle<Quaternion, T, 4, 2, 3      > zw;
            Swizzle<Quaternion, T, 4, 3, 0      > wx;
            Swizzle<Quaternion, T, 4, 3, 1      > wy;
            Swizzle<Quaternion, T, 4, 3, 2      > wz;
            Swizzle<Quaternion, T, 4, 0, 1, 2   > xyz;
            Swizzle<Quaternion, T, 4, 0, 1, 3   > xyw;
            Swizzle<Quaternion, T, 4, 0, 2, 1   > xzy;
            Swizzle<Quaternion, T, 4, 0, 2, 3   > xzw;
            Swizzle<Quaternion, T, 4, 0, 3, 1   > xwy;
            Swizzle<Quaternion, T, 4, 0, 3, 2   > xwz;
            Swizzle<Quaternion, T, 4, 1, 0, 2   > yxz;
            Swizzle<Quaternion, T, 4, 1, 0, 3   > yxw;
            Swizzle<Quaternion, T, 4, 1, 2, 0   > yzx;
            Swizzle<Quaternion, T, 4, 1, 2, 3   > yzw;
            Swizzle<Quaternion, T, 4, 1, 3, 0   > ywx;
            Swizzle<Quaternion, T, 4, 1, 3, 2   > ywz;
            Swizzle<Quaternion, T, 4, 2, 0, 1   > zxy;
            Swizzle<Quaternion, T, 4, 2, 0, 3   > zxw;
            Swizzle<Quaternion, T, 4, 2, 1, 0   > zyx;
            Swizzle<Quaternion, T, 4, 2, 1, 3   > zyw;
            Swizzle<Quaternion, T, 4, 2, 3, 0   > zwx;
            Swizzle<Quaternion, T, 4, 2, 3, 1   > zwy;
            Swizzle<Quaternion, T, 4, 0, 1, 2, 3> xyzw;
            Swizzle<Quaternion, T, 4, 0, 1, 3, 2> xywz;
            Swizzle<Quaternion, T, 4, 0, 2, 1, 3> xzyw;
            Swizzle<Quaternion, T, 4, 0, 2, 3, 1> xzwy;
            Swizzle<Quaternion, T, 4, 0, 3, 1, 2> xwyz;
            Swizzle<Quaternion, T, 4, 0, 3, 2, 1> xwzy;
            Swizzle<Quaternion, T, 4, 1, 0, 2, 3> yxzw;
            Swizzle<Quaternion, T, 4, 1, 0, 3, 2> yxwz;
            Swizzle<Quaternion, T, 4, 1, 2, 0, 3> yzxw;
            Swizzle<Quaternion, T, 4, 1, 2, 3, 0> yzwx;
            Swizzle<Quaternion, T, 4, 1, 3, 0, 2> ywxz;
            Swizzle<Quaternion, T, 4, 1, 3, 2, 0> ywzx;
            Swizzle<Quaternion, T, 4, 2, 0, 1, 3> zxyw;
            Swizzle<Quaternion, T, 4, 2, 0, 3, 1> zxwy;
            Swizzle<Quaternion, T, 4, 2, 1, 0, 3> zyxw;
            Swizzle<Quaternion, T, 4, 2, 1, 3, 0> zywx;
            Swizzle<Quaternion, T, 4, 2, 3, 0, 1> zwxy;
            Swizzle<Quaternion, T, 4, 2, 3, 1, 0> zwyx;
            Swizzle<Quaternion, T, 4, 3, 0, 1, 2> wxyz;
            Swizzle<Quaternion, T, 4, 3, 0, 2, 1> wxzy;
            Swizzle<Quaternion, T, 4, 3, 1, 0, 2> wyxz;
            Swizzle<Quaternion, T, 4, 3, 1, 2, 0> wyzx;
            Swizzle<Quaternion, T, 4, 3, 2, 0, 1> wzxy;
            Swizzle<Quaternion, T, 4, 3, 2, 1, 0> wzyx;
        };


    private:


    };

}
