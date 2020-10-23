#pragma once

#include "cdu_core.h"
#include "cdu_type.h"
#include "cdu_stlcontainers.h"
#include "cdu_reflection.h"

#include <cstdint>
#include <variant>
#include <string>
#include <string_view>

namespace chilldew::utility::reflection
{

    struct reflector
    {
        // ---------------------------------------------------------------------
        // Modifiers
        // ---------------------------------------------------------------------

        template <typename value_t> static bool register_type();

        // ---------------------------------------------------------------------
        // Readers
        // ---------------------------------------------------------------------

        static bool is_registered(type::id_t type_id);

        template <typename value_t> static bool is_registered();

    private:


    };

}
