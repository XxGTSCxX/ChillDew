/******************************************************************************/
/*!
  \project ChillDew-Engine
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

#include "CD_Core.h"

namespace CD
{

    template <template <typename, size_t> class ArrayTemplate, typename ElemType, size_t N, size_t ... INDICES>
    class CD_API Swizzle final
    {
        ElemType _array[N];

    public:

        ArrayTemplate<ElemType, N>& operator=(ArrayTemplate<ElemType, N> const& array_template);

        explicit operator ArrayTemplate<ElemType, N>() const;
    };

}
