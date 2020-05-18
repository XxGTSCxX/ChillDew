#pragma once

#include "CD_Swizzle.h"

namespace CD
{

    template <template <typename T, size_t SZ> class ArrayTemplate, typename ElemType, size_t N, size_t ... INDICES>
    inline ArrayTemplate<ElemType, N>& Swizzle<ArrayTemplate, ElemType, N, INDICES...>::operator=(ArrayTemplate<ElemType, N> const& array_template)
    {
        size_t indices[] = { INDICES... };
        for (size_t i = 0; i < sizeof...(INDICES); ++i)
        {
            _array[indices[i]] = array_template[i];
        }
        return *static_cast<ArrayTemplate<ElemType, N>*>(this);
    }

    template <template <typename T, size_t SZ> class ArrayTemplate, typename ElemType, size_t N, size_t ... INDICES>
    inline Swizzle<ArrayTemplate, ElemType, N, INDICES...>::operator ArrayTemplate<ElemType, sizeof...(INDICES)>() const
    {
        return ArrayTemplate<ElemType, sizeof...(INDICES)>{ _array[INDICES]... };
    }

}
