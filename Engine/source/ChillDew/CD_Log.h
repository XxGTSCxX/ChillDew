/******************************************************************************/
/*!
  \project GTE
  \file    CD_Log.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines most of the commonly used data by all log features.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Core.h"
#include "CD_Flags.h"

namespace chilldew
{

    struct CD_API Log final
    {
        struct Colour
        {
            static constexpr CD::string_view DEFAULT        = CD_STRING("\033[0m"   ); // Default
            static constexpr CD::string_view BLACK          = CD_STRING("\033[30m"  ); // Black
            static constexpr CD::string_view RED            = CD_STRING("\033[31m"  ); // Red
            static constexpr CD::string_view GREEN          = CD_STRING("\033[32m"  ); // Green
            static constexpr CD::string_view YELLOW         = CD_STRING("\033[33m"  ); // Yellow
            static constexpr CD::string_view BLUE           = CD_STRING("\033[34m"  ); // Blue
            static constexpr CD::string_view MAGENTA        = CD_STRING("\033[35m"  ); // Magenta
            static constexpr CD::string_view CYAN           = CD_STRING("\033[36m"  ); // Cyan
            static constexpr CD::string_view WHITE          = CD_STRING("\033[37m"  ); // White
            static constexpr CD::string_view BRIGHT_BLACK   = CD_STRING("\033[1;30m"); // Bright Black
            static constexpr CD::string_view BRIGHT_RED     = CD_STRING("\033[1;31m"); // Bright Red
            static constexpr CD::string_view BRIGHT_GREEN   = CD_STRING("\033[1;32m"); // Bright Green
            static constexpr CD::string_view BRIGHT_YELLOW  = CD_STRING("\033[1;33m"); // Bright Yellow
            static constexpr CD::string_view BRIGHT_BLUE    = CD_STRING("\033[1;34m"); // Bright Blue
            static constexpr CD::string_view BRIGHT_MAGENTA = CD_STRING("\033[1;35m"); // Bright Magenta
            static constexpr CD::string_view BRIGHT_CYAN    = CD_STRING("\033[1;36m"); // Bright Cyan
            static constexpr CD::string_view BRIGHT_WHITE   = CD_STRING("\033[1;37m"); // Bright White
        };

        struct Format
        {
            static constexpr CD::string_view VARIABLE_SPECIFIER = CD_STRING("{}");

            static CD::string FormatText(CD::string_view const& text);

            template <typename Arg, typename ... Args>
            static CD::string FormatText(CD::string_view const& text, Arg&& arg, Args&& ... args);
        };

        enum class Type : std::uint8_t
        {
              Default   = 0b000                                                 // Equivalent to Trace I suppose?
            , Error     = 0b001
            , Exception = 0b010
            , Warning   = 0b100

            , All = Default | Error | Exception | Warning                       // Required by Flags<>
        };

        using TypeFlag = Flags<Type>;
    };

}
