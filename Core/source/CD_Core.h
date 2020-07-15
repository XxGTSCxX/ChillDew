/******************************************************************************/
/*!
  \project Chilldew-Core
  \file    cd_core.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Defines engine API and settings for the project.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#ifdef _WIN32
    #ifdef _WINDLL
        #ifdef CD_BUILD_DLL
            #define CD_API      __declspec(dllexport)
            #define CD_TEMPLATE
        #else
            #define CD_API      __declspec(dllimport)
            #define CD_TEMPLATE extern
        #endif
    #else
        #define CD_API
        #define CD_TEMPLATE
    #endif

    #include <Windows.h>
#else
    #error Unsupported Platform
#endif

namespace chilldew {}
namespace cd = ::chilldew;

#define CD_STRINGIFY(x)   #x
#define CD_X_STRINGIFY(x) CD_STRINGIFY(x)

#ifdef UNICODE

#include <iostream>    // std::wistream , std::wostream , std::wiostream
#include <fstream>     // std::wifstream, std::wfostream, std::wfstream
#include <sstream>     // std::wstringstream
#include <string>      // std::wstring
#include <string_view> // std::wstring_view

#define CD_STRING(x)   L##x
#define CD_STRING_W(x) CD_STRING(x)

namespace chilldew
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

    inline cd::string cstr_to_str(std::string_view const& c_string)
    {
        cd::string result;
        size_t     size      = c_string.size() + 1;
        size_t     converted = 0;

        result.resize(size);
        mbstowcs_s(&converted, &result.front(), size, c_string.data(), size);
        result.resize(converted);

        return result;
    }
}

#else

#include <iostream>    // std::istream , std::ostream , std::iostream
#include <fstream>     // std::ifstream, std::fostream, std::fstream
#include <sstream>     // std::stringstream
#include <string>      // std::string
#include <string_view> // std::string_view

#define CD_STRING(x)   x
#define CD_STRING_W(x) CD_STRING(x)

namespace chilldew
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

    inline cd::string cstr_to_str(std::string_view const& c_string)
    {
        return cd::string{ c_string };
    }
}

#endif
