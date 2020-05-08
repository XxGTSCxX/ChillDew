#pragma once

#include "CD_Swizzle.h"

namespace CD
{

    template <class ArrayTemplate<>, typename ElemType, size_t N, size_t ... INDICES>
    inline ArrayTemplate<ElemType, N>& Swizzle<ArrayTemplate<>, ElemType, N, ... INDICES>::operator=(ArrayTemplate<ElemType, N> const& array_template)
    {
        size_t indices[] = { INDICES... };
        for (size_t i = 0; i < sizeof...(INDICES); ++i)
        {
            _array[indices[i]] = array_template[i];
        }
        return *static_cast<ArrayTemplate<ElemType, N>*>(this);
    }

    template <class ArrayTemplate<,>, typename ElemType, size_t N, size_t ...INDICES>
    inline Swizzle<ArrayTemplate<,>, ElemType, N, ...INDICES>::operator ArrayTemplate<ElemType, N>() const
    {
        return ArrayTemplate<ElemType, N>{ _array[INDICES]... };
    }

}
