#pragma once

#include "Chilldew-Engine.h"

namespace chilldew
{

    struct editor : public cde::app
    {
        editor();

        bool is_editor() const override;

    private:

        void setup() override;
    };

}
