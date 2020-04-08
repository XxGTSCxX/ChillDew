/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_EntryPoint.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Entry point for the application.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Application.h"
#include <memory>
#include <crtdbg.h>

#ifdef _WIN32

#include <windows.h>

extern GTE::Application* GTE::CreateApplication();
extern void              GTE::DestroyApplication(GTE::Application* app);

// if Win32 is the platform - different entry point for different platforms
int CALLBACK WinMain( _In_     HINSTANCE hInstance
                    , _In_opt_ HINSTANCE hPrevInstance // obsolete
                    , _In_     LPSTR     lpCmdLine
                    , _In_     int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(2799);
#endif

    GTE::Application* app = GTE::CreateApplication();
    app->Run();
    GTE::DestroyApplication(app);

    return 0;
}

#else

#error Unsupported Platform

#endif
