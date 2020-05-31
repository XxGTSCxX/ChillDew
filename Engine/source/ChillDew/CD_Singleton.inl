/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Singleton.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Base class for any Singleton class to inherit from. Ensures that only one
    instance of an object exists at any one time.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Singleton.h"

namespace chilldew
{

    template <typename T>
    inline Singleton<T>::Singleton()
    {
        assert(!_instance && "Only one instance of a singleton should be instantiated at any one time!");
        _instance = static_cast<T*>(this);
    }

    template<typename T>
    inline Singleton<T>::~Singleton()
    {
        _instance = nullptr;
    }

    template <typename T>
    inline T* Singleton<T>::Get()
    {
        return _instance;
    }

}
