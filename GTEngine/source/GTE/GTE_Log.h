/******************************************************************************/
/*!
  \project GTE
  \file    GTE_Log.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines most of the commonly used data by all log features.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_Flags.h"

namespace GTE
{

    struct GTE_API Log final
    {
        struct Colour
        {
            static constexpr GTE::string_view DEFAULT        = GTE_STRING("\033[0m"   ); // Default
            static constexpr GTE::string_view BLACK          = GTE_STRING("\033[30m"  ); // Black
            static constexpr GTE::string_view RED            = GTE_STRING("\033[31m"  ); // Red
            static constexpr GTE::string_view GREEN          = GTE_STRING("\033[32m"  ); // Green
            static constexpr GTE::string_view YELLOW         = GTE_STRING("\033[33m"  ); // Yellow
            static constexpr GTE::string_view BLUE           = GTE_STRING("\033[34m"  ); // Blue
            static constexpr GTE::string_view MAGENTA        = GTE_STRING("\033[35m"  ); // Magenta
            static constexpr GTE::string_view CYAN           = GTE_STRING("\033[36m"  ); // Cyan
            static constexpr GTE::string_view WHITE          = GTE_STRING("\033[37m"  ); // White
            static constexpr GTE::string_view BRIGHT_BLACK   = GTE_STRING("\033[1;30m"); // Bright Black
            static constexpr GTE::string_view BRIGHT_RED     = GTE_STRING("\033[1;31m"); // Bright Red
            static constexpr GTE::string_view BRIGHT_GREEN   = GTE_STRING("\033[1;32m"); // Bright Green
            static constexpr GTE::string_view BRIGHT_YELLOW  = GTE_STRING("\033[1;33m"); // Bright Yellow
            static constexpr GTE::string_view BRIGHT_BLUE    = GTE_STRING("\033[1;34m"); // Bright Blue
            static constexpr GTE::string_view BRIGHT_MAGENTA = GTE_STRING("\033[1;35m"); // Bright Magenta
            static constexpr GTE::string_view BRIGHT_CYAN    = GTE_STRING("\033[1;36m"); // Bright Cyan
            static constexpr GTE::string_view BRIGHT_WHITE   = GTE_STRING("\033[1;37m"); // Bright White
        };

        struct Format
        {
            static constexpr GTE::string_view VARIABLE_SPECIFIER = GTE_STRING("{}");

            static GTE::string FormatText(GTE::string_view const& text);

            template <typename Arg, typename ... Args>
            static GTE::string FormatText(GTE::string_view const& text, Arg&& arg, Args&& ... args);
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
