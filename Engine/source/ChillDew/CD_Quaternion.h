/******************************************************************************/
/*!
  \project Chilldew-Engine
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
#include "CD_Swizzle.inl" // CD::swizzle
#include "CD_Degree.inl"  // CD::Degree
#include <array>           // std::array

namespace chilldew
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

            swizzle<Quaternion, T, 4, 0, 1      > xy;
            swizzle<Quaternion, T, 4, 0, 2      > xz;
            swizzle<Quaternion, T, 4, 0, 3      > xw;
            swizzle<Quaternion, T, 4, 1, 0      > yx;
            swizzle<Quaternion, T, 4, 1, 2      > yz;
            swizzle<Quaternion, T, 4, 1, 3      > yw;
            swizzle<Quaternion, T, 4, 2, 0      > zx;
            swizzle<Quaternion, T, 4, 2, 1      > zy;
            swizzle<Quaternion, T, 4, 2, 3      > zw;
            swizzle<Quaternion, T, 4, 3, 0      > wx;
            swizzle<Quaternion, T, 4, 3, 1      > wy;
            swizzle<Quaternion, T, 4, 3, 2      > wz;
            swizzle<Quaternion, T, 4, 0, 1, 2   > xyz;
            swizzle<Quaternion, T, 4, 0, 1, 3   > xyw;
            swizzle<Quaternion, T, 4, 0, 2, 1   > xzy;
            swizzle<Quaternion, T, 4, 0, 2, 3   > xzw;
            swizzle<Quaternion, T, 4, 0, 3, 1   > xwy;
            swizzle<Quaternion, T, 4, 0, 3, 2   > xwz;
            swizzle<Quaternion, T, 4, 1, 0, 2   > yxz;
            swizzle<Quaternion, T, 4, 1, 0, 3   > yxw;
            swizzle<Quaternion, T, 4, 1, 2, 0   > yzx;
            swizzle<Quaternion, T, 4, 1, 2, 3   > yzw;
            swizzle<Quaternion, T, 4, 1, 3, 0   > ywx;
            swizzle<Quaternion, T, 4, 1, 3, 2   > ywz;
            swizzle<Quaternion, T, 4, 2, 0, 1   > zxy;
            swizzle<Quaternion, T, 4, 2, 0, 3   > zxw;
            swizzle<Quaternion, T, 4, 2, 1, 0   > zyx;
            swizzle<Quaternion, T, 4, 2, 1, 3   > zyw;
            swizzle<Quaternion, T, 4, 2, 3, 0   > zwx;
            swizzle<Quaternion, T, 4, 2, 3, 1   > zwy;
            swizzle<Quaternion, T, 4, 0, 1, 2, 3> xyzw;
            swizzle<Quaternion, T, 4, 0, 1, 3, 2> xywz;
            swizzle<Quaternion, T, 4, 0, 2, 1, 3> xzyw;
            swizzle<Quaternion, T, 4, 0, 2, 3, 1> xzwy;
            swizzle<Quaternion, T, 4, 0, 3, 1, 2> xwyz;
            swizzle<Quaternion, T, 4, 0, 3, 2, 1> xwzy;
            swizzle<Quaternion, T, 4, 1, 0, 2, 3> yxzw;
            swizzle<Quaternion, T, 4, 1, 0, 3, 2> yxwz;
            swizzle<Quaternion, T, 4, 1, 2, 0, 3> yzxw;
            swizzle<Quaternion, T, 4, 1, 2, 3, 0> yzwx;
            swizzle<Quaternion, T, 4, 1, 3, 0, 2> ywxz;
            swizzle<Quaternion, T, 4, 1, 3, 2, 0> ywzx;
            swizzle<Quaternion, T, 4, 2, 0, 1, 3> zxyw;
            swizzle<Quaternion, T, 4, 2, 0, 3, 1> zxwy;
            swizzle<Quaternion, T, 4, 2, 1, 0, 3> zyxw;
            swizzle<Quaternion, T, 4, 2, 1, 3, 0> zywx;
            swizzle<Quaternion, T, 4, 2, 3, 0, 1> zwxy;
            swizzle<Quaternion, T, 4, 2, 3, 1, 0> zwyx;
            swizzle<Quaternion, T, 4, 3, 0, 1, 2> wxyz;
            swizzle<Quaternion, T, 4, 3, 0, 2, 1> wxzy;
            swizzle<Quaternion, T, 4, 3, 1, 0, 2> wyxz;
            swizzle<Quaternion, T, 4, 3, 1, 2, 0> wyzx;
            swizzle<Quaternion, T, 4, 3, 2, 0, 1> wzxy;
            swizzle<Quaternion, T, 4, 3, 2, 1, 0> wzyx;
        };


    private:


    };

}
