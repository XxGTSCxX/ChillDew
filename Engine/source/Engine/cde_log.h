/******************************************************************************/
/*!
  \project GTE
  \file    CD_Log.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines most of the commonly used data by all log features.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_core.h"

namespace chilldew::engine
{

    struct CD_API log final
    {
        struct colour
        {
            static constexpr cd::string_view reset          = CD_L("\033[0m"   ); // Default
            static constexpr cd::string_view black          = CD_L("\033[30m"  ); // Black
            static constexpr cd::string_view red            = CD_L("\033[31m"  ); // Red
            static constexpr cd::string_view green          = CD_L("\033[32m"  ); // Green
            static constexpr cd::string_view yellow         = CD_L("\033[33m"  ); // Yellow
            static constexpr cd::string_view blue           = CD_L("\033[34m"  ); // Blue
            static constexpr cd::string_view magenta        = CD_L("\033[35m"  ); // Magenta
            static constexpr cd::string_view cyan           = CD_L("\033[36m"  ); // Cyan
            static constexpr cd::string_view white          = CD_L("\033[37m"  ); // White
            static constexpr cd::string_view bright_black   = CD_L("\033[1;30m"); // Bright Black
            static constexpr cd::string_view bright_red     = CD_L("\033[1;31m"); // Bright Red
            static constexpr cd::string_view bright_green   = CD_L("\033[1;32m"); // Bright Green
            static constexpr cd::string_view bright_yellow  = CD_L("\033[1;33m"); // Bright Yellow
            static constexpr cd::string_view bright_blue    = CD_L("\033[1;34m"); // Bright Blue
            static constexpr cd::string_view bright_magenta = CD_L("\033[1;35m"); // Bright Magenta
            static constexpr cd::string_view bright_cyan    = CD_L("\033[1;36m"); // Bright Cyan
            static constexpr cd::string_view bright_white   = CD_L("\033[1;37m"); // Bright White
        };

        struct format
        {
            static constexpr cd::string_view variable_specifier = CD_L("{}");

            static cd::string format_text(cd::string_view const& text);

            template <typename Arg, typename ... Args>
            static cd::string format_text(cd::string_view const& text, Arg&& arg, Args&& ... args);
        };

        enum class type : std::uint8_t
        {
              trace     = 0b0001
            , error     = 0b0010
            , exception = 0b0100
            , warning   = 0b1000

            , all = trace | error | exception | warning                         // Required by flag<>
        };

        using flag = cdu::flag<type>;
    };

}
