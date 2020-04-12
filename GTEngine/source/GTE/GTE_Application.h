/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Application.h
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
#pragma once

#include "GTE_Core.h"
#include "GTE_Singleton.inl"
#include "GTE_AppState.h"
#include "GTE_Debug.inl"
#include "GTE_Flag.inl"
#include <Windows.h> // DWORD, BOOL

namespace GTE
{

    class GTE_API Application : public Singleton<Application>
    {
    public:

        // TODO: When Event Delegates are ready, add quitting and wantsToQuit
        //       event delegates.

        Application();
        virtual ~Application();

        void Run();
        void Quit();

        virtual void Play();                                                    // Mainly for editor use
        virtual void Pause();                                                   // Mainly for editor use
        virtual void Stop();                                                    // Mainly for editor use

        virtual bool IsEditor()  const;                                         // Editor applications are expected to return true in this function (false by default)
        virtual bool IsPlaying() const;                                         // Editor applications are expected to return false if the game is not being played (true by default)

    protected:

        virtual void Setup()   {};                                              // Called once at the beginning of Run
        virtual void Destroy() {};                                              // Called once at the end of Run

        virtual void PreLoad()     {};
        virtual void PostLoad()    {};
        virtual void PreInit()     {};
        virtual void PostInit()    {};
        virtual void PreUpdate()   {};
        virtual void PostUpdate()  {};
        virtual void PreCleanup()  {};
        virtual void PostCleanup() {};
        virtual void PreUnload()   {};
        virtual void PostUnload()  {};

        // ---------------------------------------------------------------------
        // Events

        virtual BOOL ControlHandler(DWORD event_code);                          // Handles the events from the console application, can be defined by user

    private:

        enum class AppFlags : std::uint8_t
        {
              Play    = 0b01
            , Pause   = 0b10

            , Default = Play
            , All     = Play | Pause
        };

        using Flags = GTE::Flags<AppFlags>;

        //Engine   _engine;
        Debug    _debugger;
        AppState _app_state = AppState::Load;
        Flags    _flags     = Flags{ AppFlags::Default };

        void Load();
        void Init();
        void Update();
        void Cleanup();
        void Unload();

        static BOOL ControlHandlerWrapper(DWORD event_code);
    };

    GTE_API Application* CreateApplication();                                   // Defined by client
    GTE_API void         DestroyApplication(Application* app);                  // Defined by client

}
