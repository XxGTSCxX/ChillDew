#include "Editor.h"

cd::Application* cd::CreateApplication()
{
    return new ChilldewEditor{};
}

void cd::DestroyApplication(cd::Application* game)
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
    cd::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
    std::cin.get();
    Quit();
}
