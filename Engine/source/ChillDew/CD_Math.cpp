#include "CD_pch.h"
#include "CD_Math.inl"

namespace CD
{

    bool Math::FuzzyEqual(Real lhs, Real rhs, Real epsilon)
    {
        return fabs(lhs - rhs) < epsilon;
    }

    bool Math::FuzzyEqual(Real lhs, Real rhs)
    {
        return FuzzyEqual(lhs, rhs, EPSILON);
    }

}
