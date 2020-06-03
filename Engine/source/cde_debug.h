/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_debug.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Mimics Unity's Debug class as best as we can within the constraints of C++.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_core.h"
#include "cdu_singleton.inl"
#include "cde_ilogger.h"
#include "cde_logger.h"

namespace chilldew::engine
{

    class CD_API debug final : public cdu::singleton<debug>
    {
    public:

        debug();
        ~debug();

        bool is_debug_build()               const noexcept;
        bool is_developer_console_visible() const noexcept;

        void  enable_developer_console();
        void disable_developer_console();

        ilogger&       get_logger();
        ilogger const& get_logger() const;

        void breakpoint() const;        // Does a breakpoint at the line this is called
        void clear_developer_console(); // Clears errors from the developer console.

        template <typename ... Args> void log_assert (bool condition, std::string_view const& text = "", Args&& ... args); // Assert a condition and logs an error message to the GTE console on failure.
        template <typename ... Args> void log        (                std::string_view const& text     , Args&& ... args);
        template <typename ... Args> void log_error  (                std::string_view const& text     , Args&& ... args);
        template <typename ... Args> void log_warning(                std::string_view const& text     , Args&& ... args);

    private:

        logger _logger;
        bool   _developer_console_is_visible = false; // only opened on any log calls
    };

}
