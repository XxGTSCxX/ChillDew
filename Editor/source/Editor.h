#pragma once

#include "Chilldew.h"

class ChilldewEditor : public cd::Application
{
public:

    ChilldewEditor();

    bool IsEditor() const override;

private:

    void Setup() override;
};
