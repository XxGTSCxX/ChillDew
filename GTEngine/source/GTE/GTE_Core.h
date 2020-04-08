/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Core.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines engine API and settings for the project.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#ifdef _WIN32
    #ifdef _WINDLL
        #ifdef GTE_BUILD_DLL
            #define GTE_API      __declspec(dllexport)
            #define GTE_TEMPLATE
        #else
            #define GTE_API      __declspec(dllimport)
            #define GTE_TEMPLATE extern
        #endif
    #else
        #define GTE_API
        #define GTE_TEMPLATE
    #endif
#else
    #error Unsupported Platform
#endif

#ifdef UNICODE

#include <iostream>    // std::wistream, std::wostream, std::wiostream
#include <fstream>     // std::wifstream, std::wfostream, std::wfstream
#include <sstream>     // std::wstringstream
#include <string>      // std::wstring
#include <string_view> // std::wstring_view

#define GTE_STRING(x) L##x

namespace GTE
{
    using istream      = std::wistream;
    using ostream      = std::wostream;
    using iostream     = std::wiostream;
    using ifstream     = std::wifstream;
    using ofstream     = std::wofstream;
    using fstream      = std::wfstream;
    using stringstream = std::wstringstream;
    using string       = std::wstring;
    using string_view  = std::wstring_view;

    static inline istream& cin  = std::wcin;
    static inline ostream& cout = std::wcout;
    static inline ostream& cerr = std::wcerr;
    static inline ostream& clog = std::wclog;

    inline GTE::string CStrToStr(std::string_view const& c_string)
    {
        GTE::string result;
        size_t      size = c_string.size() + 1;

        result.resize(size);
        mbtowc(&result.front(), c_string.data(), size);

        return result;
    }
}

#else

#include <iostream>    // std::istream , std::ostream , std::iostream
#include <fstream>     // std::ifstream, std::fostream, std::fstream
#include <sstream>     // std::stringstream
#include <string>      // std::string
#include <string_view> // std::string_view

#define GTE_STRING(x) x

namespace GTE
{
    using istream      = std::istream;
    using ostream      = std::ostream;
    using iostream     = std::iostream;
    using ifstream     = std::ifstream;
    using ofstream     = std::ofstream;
    using fstream      = std::fstream;
    using stringstream = std::stringstream;
    using string       = std::string;
    using string_view  = std::string_view;

    static inline istream& cin  = std::cin;
    static inline ostream& cout = std::cout;
    static inline ostream& cerr = std::cerr;
    static inline ostream& clog = std::clog;

    inline GTE::string CStrToStr(std::string_view const& c_string)
    {
        return GTE::string{ c_string };
    }
}

#endif
