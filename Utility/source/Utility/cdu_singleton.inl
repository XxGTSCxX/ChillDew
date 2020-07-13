/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cdu_singleton.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Base class for any Singleton class to inherit from. Ensures that only one
    instance of an object exists at any one time.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cdu_singleton.h"

namespace chilldew::utility
{

    template <typename obj_t>
    inline singleton<obj_t>::singleton()
    {
        assert(!_instance && "Only one instance of a singleton should be instantiated at any one time!");
        _instance = static_cast<obj_t*>(this);
    }

    template<typename obj_t>
    inline singleton<obj_t>::~singleton()
    {
        _instance = nullptr;
    }

    template <typename obj_t>
    inline obj_t* singleton<obj_t>::get()
    {
        return _instance;
    }

}
