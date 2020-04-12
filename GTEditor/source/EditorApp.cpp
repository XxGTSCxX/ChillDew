#include "EditorApp.h"

GTE::Application* GTE::CreateApplication()
{
    return new GTEditor::EditorApp{};
}

void GTE::DestroyApplication(GTE::Application* game)
{
    delete game;
}

namespace GTEditor
{

    EditorApp::EditorApp()
    {
        Stop();
    }

    bool EditorApp::IsEditor() const
    {
        return true;
    }

    void EditorApp::Setup()
    {
        GTE::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
        if (getchar())
            Quit();
    }

}
