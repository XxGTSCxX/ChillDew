#pragma once

#include "GTEngine.h"

namespace GTEditor
{

    class EditorApp : public GTE::Application
    {
    public:

        EditorApp();

    private:

        void Setup() override;
    };

}
