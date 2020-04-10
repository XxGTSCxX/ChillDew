#include "GTE_pch.h"
#include "GTE_Math.h"

namespace GTE
{

    bool FuzzyEqual(Real lhs, Real rhs, Real epsilon)
    {
        return std::fabs(lhs - rhs) <= epsilon;
    }

    bool FuzzyEqual(Real lhs, Real rhs)
    {
        return FuzzyEqual(lhs, rhs, EPSIlON);
    }

}
