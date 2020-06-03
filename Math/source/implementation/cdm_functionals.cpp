/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_functionals.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Math functions.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cdm_functionals.h"

namespace chilldew::math
{

    inline bool fuzzy_equal(real lhs, real rhs, real epsilon) noexcept
    {
        return fabs(lhs - rhs) < epsilon;
    }

    inline bool fuzzy_equal(real lhs, real rhs) noexcept
    {
        return fabs(lhs - rhs) < cdm::epsilon;
    }

}
