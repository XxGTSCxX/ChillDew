/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_radian.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in radians.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_radian.h"

namespace chilldew::math
{

    constexpr radian::radian(real rad_angle) noexcept
    : _angle{ rad_angle }
    {}

}
