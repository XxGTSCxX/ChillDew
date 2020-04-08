#include "GTE_pch.h"
#include "GTE_Application.h"
#include <cassert> // assert

namespace GTE
{

    Application* Application::_application_instance = nullptr;

    Application::Application()
    {
        assert(!_application_instance);                                         // TODO: Replace with own assert function
        _application_instance = this;
    }

    Application* Application::Get()
    {
        return _application_instance;
    }

    void Application::Run()
    {
        GTE::cout << GTE_STRING("Welcome to the GTEngine") << std::endl;

        //Setup();

        //while (_app_state != AppState::QUIT)
        //{
        //	switch (_app_state)
        //	{
        //	case AppState::LOAD:
        //		Load();
        //	case AppState::INIT:
        //		Init();
        //		_app_state = AppState::RUN;
        //	}

        //	Update();

        //	if (_app_state != AppState::RUN)
        //	{
        //		Cleanup();
        //		if (_app_state != AppState::INIT)
        //			Unload();
        //	}
        //}

        //Destroy();
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
        default:
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
        if (_application_instance)
            result = _application_instance->ControlHandler(event_code);
        return result;
    }

}
