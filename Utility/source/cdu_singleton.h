/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Singleton.h
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

#include "cdu_core.h"
#include <cassert> // assert

namespace chilldew::utility
{

    template <typename obj_t>
    struct CD_API singleton
    {
        singleton();
        virtual ~singleton();

        // Disable Copy
        singleton(singleton const&)            = delete;
        singleton(singleton&&)                 = delete;
        singleton& operator=(singleton const&) = delete;
        singleton& operator=(singleton&&)      = delete;

        static obj_t* get();

    private:

        static inline obj_t* _instance = nullptr;
    };

}
