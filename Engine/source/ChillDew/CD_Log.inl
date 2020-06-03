/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Log.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Format settings such as Colour attribute for logging.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "CD_Log.h"

namespace chilldew
{

	template <typename Arg, typename ... Args>
	inline cd::string Log::Format::FormatText(cd::string_view const& text, Arg&& arg, Args&& ... args)
	{
		size_t pos = text.find(VARIABLE_SPECIFIER);

		if (pos != cd::string_view::npos)
		{
			cd::stringstream stream;
			stream << text.substr(0, pos) << arg << text.substr(pos + 2);
			return FormatText(stream.str(), std::forward<Args>(args)...);
		}
		else
			return FormatText(text);
	}

}
