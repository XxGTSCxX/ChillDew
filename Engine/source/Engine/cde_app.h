/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_app.h
  \author  Gabrielle Tan Suan Choo
  \brief
    app interface for users who wish to create their program using this
    engine. Also defines how the application is mainly run, with some available
    customisations that the clients can make.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_core.h"
#include "Utility/cdu_flag.inl"
#include "Utility/cdu_singleton.inl"
#include "cde_appstate.h"
#include "cde_debug.inl"
#include <Windows.h> // DWORD, BOOL

namespace chilldew::engine
{

    struct CD_API app : public cdu::singleton<app>
    {
        // TODO: When Event Delegates are ready, add quitting and wantsToQuit
        //       event delegates.

        app();
        virtual ~app();

        void run();
        void quit();

        virtual void play();                                                    // Mainly for editor use
        virtual void pause();                                                   // Mainly for editor use
        virtual void stop();                                                    // Mainly for editor use

        virtual bool is_editor()  const;                                        // Editor applications are expected to return true in this function (false by default)
        virtual bool is_playing() const;                                        // Editor applications are expected to return false if the game is not being played (true by default)

    protected:

        virtual void setup()   {};                                              // Called once at the beginning of run
        virtual void destroy() {};                                              // Called once at the end of run

        virtual void pre_load()     {};
        virtual void pre_init()     {};
        virtual void pre_update()   {};
        virtual void pre_cleanup()  {};
        virtual void pre_unload()   {};

        virtual void post_load()    {};
        virtual void post_init()    {};
        virtual void post_update()  {};
        virtual void post_cleanup() {};
        virtual void post_unload()  {};

        // ---------------------------------------------------------------------
        // Events

        virtual BOOL control_handler(DWORD event_code);                         // Handles the events from the console application, can be defined by user

    private:

        enum class appflags : std::uint8_t
        {
              play  = 0b01
            , pause = 0b10
            , all   = play | pause
        };

        using Flags = cdu::flag<appflags>;

        debug    _debugger;
        appstate _app_state = appstate::load;
        Flags    _flags     = Flags{ appflags::play };

        void load();
        void init();
        void update();
        void cleanup();
        void unload();

        static BOOL control_handler_wrapper(DWORD event_code);
    };

    CD_API app* create_app();                                                   // Defined by client
    CD_API void destroy_app(app* app);                                          // Defined by client

}
