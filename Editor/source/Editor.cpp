#define GLM_FORCE_SWIZZLE

#include "Editor.h"
#include "glm/glm.hpp"
#include "glm/gtx/projection.inl"
#include "glm/gtx/perpendicular.inl"

CD::Application* CD::CreateApplication()
{
    return new ChilldewEditor{};
}

void CD::DestroyApplication(CD::Application* game)
{
    delete game;
}

ChilldewEditor::ChilldewEditor()
{
    Stop();
}

bool ChilldewEditor::IsEditor() const
{
    return true;
}

void ChilldewEditor::Setup()
{
    CD::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
    std::cin.get();
    Quit();
}
