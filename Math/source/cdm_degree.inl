/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    cdm_degree.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in degrees.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdm_degree.h"

namespace chilldew::math
{

    constexpr degree::degree(real deg_angle) noexcept
    : _angle{ deg_angle }
    {}

}
