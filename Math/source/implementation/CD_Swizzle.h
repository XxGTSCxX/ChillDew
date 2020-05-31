/******************************************************************************/
/*!
  \project Chilldew-Engine
  \file    CD_Swizzle.h
  \author  Gabrielle Tan Suan Choo
  \brief
    The stuff that makes me wanna bash my head thru a wall. (TODO: Update this)

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include <cstddef> // std::size_t

namespace chilldew
{

    namespace detail
    {

        template <template <typename, std::size_t> typename array_t, typename elem_t, std::size_t size_v, std::size_t ... indices_v>
        class swizzle final
        {
            elem_t _array[size_v];

        public:

            array_t<elem_t, size_v>& operator=(array_t<elem_t, size_v> const& array_template);

            explicit operator array_t<elem_t, sizeof...(indices_v)>() const;
        };

    }

}
