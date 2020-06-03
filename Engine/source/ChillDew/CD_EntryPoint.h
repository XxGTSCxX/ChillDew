/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_EntryPoint.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Entry point for the application.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Application.h"
#include <memory>
#include <crtdbg.h>

#ifdef _WIN32

#include <windows.h>

extern cd::Application* cd::CreateApplication();
extern void             cd::DestroyApplication(cd::Application* app);

// if Win32 is the platform - different entry point for different platforms
int CALLBACK WinMain( _In_     [[maybe_unused]] HINSTANCE hInstance
                    , _In_opt_ [[maybe_unused]] HINSTANCE hPrevInstance // obsolete
                    , _In_     [[maybe_unused]] LPSTR     lpCmdLine
                    , _In_     [[maybe_unused]] int       nCmdShow)
{
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(2799);
#endif

    cd::Application* app = cd::CreateApplication();
    app->Run();
    cd::DestroyApplication(app);

    return 0;
}

#else

#error Unsupported Platform

#endif
