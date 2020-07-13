/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cd_appstate.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Used to identify the current application state.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_core.h"
#include <cstdint> // std::uint8_t

namespace chilldew::engine
{

    enum class CD_API appstate : std::uint8_t
    {
          quit = std::numeric_limits<std::uint8_t>::max()
        , load = 0
        , init
        , run
    };

}
