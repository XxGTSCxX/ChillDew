#pragma once

#include "GTEngine.h"

namespace GTEditor
{

    class EditorApp : public GTE::Application
    {
    public:

        EditorApp();

        bool IsEditor() const override;

    private:

        void Setup() override;
    };

}
