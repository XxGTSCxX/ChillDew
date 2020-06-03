/******************************************************************************/
/*!
  \project Chilldew-Math
  \file    CD_Swizzle.h
  \author  Gabrielle Tan Suan Choo
  \brief
    The stuff that makes me wanna bash my head thru a wall. (TODO: update this)

    all content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include <cstddef> // std::size_t

namespace chilldew::math::detail
{

    template <template <typename, std::size_t> typename array_t, typename elem_t, std::size_t size_v, std::size_t ... indices_v>
    struct swizzle final
    {
        array_t<elem_t, size_v>& operator=(array_t<elem_t, size_v> const& array_template);
        explicit operator array_t<elem_t, sizeof...(indices_v)>() const;

    private:

        elem_t _array[size_v];
    };

}
