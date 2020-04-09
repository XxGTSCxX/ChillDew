/******************************************************************************/
/*!
  \project GTE
  \file    GTE_ILogger.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Interface for all Logger classes.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "GTE_pch.h"
#include "GTE_ILogger.h"

namespace GTE
{

    void ILogger::Enable()
    {
        _is_enabled = true;
    }

    void ILogger::Disable()
    {
        _is_enabled = false;
    }

    bool ILogger::IsEnabled() const
    {
        return _is_enabled;
    }

}
