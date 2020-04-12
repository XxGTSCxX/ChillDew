#include "GTE_pch.h"
#include "GTE_Math.inl"

namespace GTE
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
