/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Degree.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in degrees.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

namespace GTE
{

    constexpr Degree::Degree(Real deg_angle) noexcept
    : _angle{ deg_angle }
    {}

}
