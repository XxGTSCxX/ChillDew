/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Application.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    Application interface for uses who wish to create their program using this
    engine. Also defines how the application is mainly run, with some available
    customisations that the clients can make.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "GTE_pch.h"
#include "GTE_Application.h"
#include <cassert> // assert

namespace GTE
{

    Application::Application()
    {}

    Application::~Application()
    {}

    void Application::Run()
    {
        SetConsoleCtrlHandler((PHANDLER_ROUTINE)(Application::ControlHandlerWrapper), TRUE);

        Debug::Get()->Log("Welcome to the GTEngine {}");

        Setup();

        while (_app_state != AppState::Quit)
        {
            switch (_app_state)
            {
            case AppState::Load:
                Load();
            case AppState::Init:
                Init();
                _app_state = AppState::Run;
            }

            Update();

            if (_app_state != AppState::Run)
            {
                Cleanup();
                if (_app_state != AppState::Init)
                    Unload();
            }
        }

        Destroy();
    }

    void Application::Pause()
    {
        _is_paused = true;
    }

    void Application::Quit()
    {
        _app_state = AppState::Quit;
    }

    bool Application::IsEditor() const
    {
        return false;
    }

    BOOL Application::ControlHandler(DWORD event_code)
    {
        BOOL result = TRUE;

        switch (event_code)
        {
        case CTRL_CLOSE_EVENT:
            Quit();
            Sleep(1000);                                                        // Give the application 1 second to do the quitting
            break;
            // Add more cases as needed
        default:                                                                // If unhandled, message is not processed, so return FALSE
            result = FALSE;
        }

        return result;
    }

    void Application::Load()
    {
        PreLoad();
        //_engine.Load();
        PostLoad();
    }

    void Application::Init()
    {
        PreInit();
        //_engine.Init();
        PostInit();
    }

    void Application::Update()
    {
        PreUpdate();
        //if (_is_paused)
        //	_engine.PausedUpdate();
        //else
        //{
        //	_engine.FixedUpdate();
        //	_engine.Update();
        //}
        PostUpdate();
    }

    void Application::Cleanup()
    {
        PreCleanup();
        //_engine.Cleanup();
        PostCleanup();
    }

    void Application::Unload()
    {
        PreUnload();
        //_engine.Unload();
        PostUnload();
    }

    BOOL Application::ControlHandlerWrapper(DWORD event_code)
    {
        BOOL result = FALSE;
        result = Get()->ControlHandler(event_code);
        return result;
    }

}
