/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Log.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Format settings such as Colour attribute for logging.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Log.h"

namespace GTE
{

	template <typename Arg, typename ... Args>
	inline GTE::string Log::Format::FormatText(GTE::string_view const& text, Arg&& arg, Args&& ... args)
	{
		size_t pos = text.find(VARIABLE_SPECIFIER);

		if (pos != GTE::string_view::npos)
		{
			GTE::stringstream stream;
			stream << text.substr(0, pos) << arg << text.substr(pos + 2);
			return FormatText(stream.str(), std::forward<Args>(args)...);
		}
		else
			return FormatText(text);
	}

}
