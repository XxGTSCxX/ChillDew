/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    cde_log.inl
  \author  Gabrielle Tan Suan Choo
  \brief
    Format settings such as Colour attribute for logging.

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "cde_log.h"

namespace chilldew::engine
{

	template <typename Arg, typename ... Args>
	inline cd::string log::format::format_text(cd::string_view const& text, Arg&& arg, Args&& ... args)
	{
		size_t pos = text.find(variable_specifier);

		if (pos != cd::string_view::npos)
		{
			cd::stringstream stream;
			stream << text.substr(0, pos) << arg << text.substr(pos + 2);
			return format_text(stream.str(), std::forward<Args>(args)...);
		}
		else
			return format_text(text);
	}

}
