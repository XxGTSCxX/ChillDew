/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_AppState.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Used to identify the current application state.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include <cstdint> // std::uint8_t

namespace chilldew
{

    enum class CD_API AppState : std::uint8_t
    {
          Quit = std::numeric_limits<std::uint8_t>::max()
        , Load = 0
        , Init
        , Run
    };

}
