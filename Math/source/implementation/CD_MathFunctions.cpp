#include "CD_MathFunctions.h"

namespace chilldew
{

    inline bool fuzzy_equal(real lhs, real rhs, real epsilon) noexcept
    {
        return fabs(lhs - rhs) < epsilon;
    }

    inline bool fuzzy_equal(real lhs, real rhs) noexcept
    {
        return fabs(lhs - rhs) < math::epsilon;
    }

}
