#pragma once

#include "ChillDew.h"

namespace CDEditor
{

    class EditorApp : public CD::Application
    {
    public:

        EditorApp();

        bool IsEditor() const override;

    private:

        void Setup() override;
    };

}
