/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_logger.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Logger for debug messages. Specifies where to stream the messages to.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_logger.h"
#include "cde_log.inl"
#include <type_traits> // std::forward<>

namespace chilldew::engine
{

    template <typename ... Args>
    inline void logger::log(cd::string_view const& text, Args&& ... args)
    {
        log(log::format::format_text(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void logger::log_warning(cd::string_view const& text, Args&& ... args)
    {
        log_warning(log::format::format_text(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void logger::log_error(cd::string_view const& text, Args&& ... args)
    {
        log_error(log::format::format_text(text, std::forward<Args>(args)...));
    }

    template <typename ... Args>
    inline void logger::log_assert(cd::string_view const& text, Args&& ... args)
    {
        log_assert(log::format::format_text(text, std::forward<Args>(args)...));
    }

}
