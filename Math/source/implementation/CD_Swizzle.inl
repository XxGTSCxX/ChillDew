#pragma once

#include "CD_Swizzle.h"

namespace chilldew
{

    namespace detail
    {

        template <template <typename, std::size_t> typename array_t, typename elem_t, std::size_t size_v, std::size_t ... indices_v>
        inline array_t<elem_t, size_v>& swizzle<array_t, elem_t, size_v, indices_v...>::operator=(array_t<elem_t, size_v> const& array_template)
        {
            std::size_t indices[] = { indices_v... };
            for (std::size_t i = 0; i < sizeof...(indices_v); ++i)
            {
                _array[indices[i]] = array_template[i];
            }
            return *static_cast<array_t<elem_t, size_v>*>(this);
        }

        template <template <typename, std::size_t> typename array_t, typename elem_t, std::size_t size_v, std::size_t ... indices_v>
        inline swizzle<array_t, elem_t, size_v, indices_v...>::operator array_t<elem_t, sizeof...(indices_v)>() const
        {
            return array_t<elem_t, sizeof...(indices_v)>{ _array[indices_v]... };
        }

    }

}
