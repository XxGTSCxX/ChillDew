/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Radian.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Angles in radians.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

namespace GTE
{

    constexpr Radian::Radian(FLD rad_angle) noexcept
    : _angle{ rad_angle }
    {}

}
