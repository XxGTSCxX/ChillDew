#include "GTE_pch.h"
#include "GTE_Math.h"

namespace GTE
{

    inline bool FuzzyEqual(FLD lhs, FLD rhs, FLD epsilon)
    {
        return std::fabs(lhs - rhs) <= epsilon;
    }

    inline bool FuzzyEqual(FLD lhs, FLD rhs)
    {
        return FuzzyEqual(lhs, rhs, EPSIlON);
    }

}
