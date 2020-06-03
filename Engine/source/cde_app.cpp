/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_app.cpp
  \author  Gabrielle Tan Suan Choo
  \brief
    app interface for uses who wish to create their program using this
    engine. Also defines how the application is mainly run, with some available
    customisations that the clients can make.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#include "cd_pch.h"
#include "cde_app.h"
#include <cassert> // assert

namespace chilldew::engine
{

    app::app()
    {}

    app::~app()
    {}

    void app::run()
    {
        SetConsoleCtrlHandler((PHANDLER_ROUTINE)(app::control_handler_wrapper), TRUE);

        setup();

        while (_app_state != appstate::quit)
        {
            switch (_app_state)
            {
            case appstate::load:
                load();
            case appstate::init:
                init();
                _app_state = appstate::run;
            }

            update();

            if (_app_state != appstate::run)
            {
                cleanup();
                if (_app_state != appstate::init)
                    unload();
            }
        }

        destroy();
    }

    bool app::is_playing() const
    {
        return _flags.is_on(appflags::play);
    }

    void app::quit()
    {
        // TODO: Once quitting and wantsToQuit events are added, fire the events
        //       here.
        _app_state = appstate::quit;
    }

    void app::play()
    {
        if (is_editor())
        {
            _flags.on (appflags::play );
            _flags.off(appflags::pause);
        }
    }

    void app::pause()
    {
        if (is_editor())
        {
            _flags.on(appflags::pause);
        }
    }

    void app::stop()
    {
        if (is_editor())
        {
            _flags.off(appflags::play, appflags::pause);
        }
    }

    bool app::is_editor() const
    {
        return false;
    }

    BOOL app::control_handler(DWORD event_code)
    {
        BOOL result = TRUE;

        switch (event_code)
        {
        case CTRL_CLOSE_EVENT:
            quit();
            Sleep(1000);                                                        // Give the application 1 second to do the quitting
            break;
            // Add more cases as needed
        default:                                                                // If unhandled, message is not processed, so return FALSE
            result = FALSE;
        }

        return result;
    }

    void app::load()
    {
        pre_load();

        post_load();
    }

    void app::init()
    {
        pre_init();

        post_init();
    }

    void app::update()
    {
        pre_update();

        post_update();
    }

    void app::cleanup()
    {
        pre_cleanup();

        post_cleanup();
    }

    void app::unload()
    {
        pre_unload();

        post_unload();
    }

    BOOL app::control_handler_wrapper(DWORD event_code)
    {
        BOOL result = FALSE;
        result = app::get()->control_handler(event_code);
        return result;
    }

}
