#pragma once

#include "ut_core.h"
#include "Chilldew-Engine.h"
#include "Chilldew-Math.h"

namespace unit_tests
{

    struct driver : public cde::app
    {
    private:

        void setup()       override;
        void post_update() override;
    };

}
