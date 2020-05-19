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

        void MathTestVector2();
        void MathTestVector3();
        void MathTestVector4();
        void MathTestVector5();
    };

}
