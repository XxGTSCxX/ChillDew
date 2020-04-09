/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Singleton.h
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

#include "GTE_Core.h"
#include <cassert> // assert

namespace GTE
{

    template <typename T>
    class GTE_API Singleton
    {
    public:

        Singleton();
        virtual ~Singleton();

        // Disabling Copy
        Singleton(Singleton const&)            = delete;
        Singleton(Singleton&&)                 = delete;
        Singleton& operator=(Singleton const&) = delete;
        Singleton& operator=(Singleton&&)      = delete;

        static T* Get();

    private:

        static inline T* _instance = nullptr;
    };

}
