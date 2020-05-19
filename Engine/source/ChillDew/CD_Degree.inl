/******************************************************************************/
/*!
  \project ChillDew-Engine
  \file    CD_Degree.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in degrees.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Degree.h"

namespace CD
{

    constexpr Degree::Degree(Real deg_angle) noexcept
    : _angle{ deg_angle }
    {}

}
