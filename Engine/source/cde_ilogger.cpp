/******************************************************************************/
/*!
  \project GTE
  \file    cde_ilogger.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all Logger classes.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cd_pch.h"
#include "cde_ilogger.h"

namespace chilldew::engine
{

    void ilogger::enable()
    {
        _is_enabled = true;
    }

    void ilogger::disable()
    {
        _is_enabled = false;
    }

    bool ilogger::is_enabled() const
    {
        return _is_enabled;
    }

}
