#pragma once

#include "ut_core.h"
#include "Chilldew.h"
#include "Chilldew-Math.h"

namespace unit_tests
{

    class driver : public cd::Application
    {
    private:

        void Setup()      override;
        void PostUpdate() override;
    };

}
