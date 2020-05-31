#pragma once

namespace chilldew
{

    namespace detail
    {

        template <typename elem_t, std::size_t size_v>
        struct CD_API vector_base
        {
            std::array<elem_t, size_v> _array;
        };

    }

}
