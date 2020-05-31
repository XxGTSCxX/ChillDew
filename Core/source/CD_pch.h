/******************************************************************************/
/*!
  \project Chilldew-Core
  \file    CD_pch.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Precompile header.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

// -----------------------------------------------------------------------------
// STL Headers

#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <chrono>
#include <ctime>
#include <cstddef>     // std::size_t
#include <cstdint>     // std::uint64_t, etc.
#include <string_view> // great for view only strings
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
#include <memory>
#include <utility>     // std::forward
#include <type_traits> // std::is_base_of_v
