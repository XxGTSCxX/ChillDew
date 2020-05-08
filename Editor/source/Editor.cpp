#include "Editor.h"

CD::Application* CD::CreateApplication()
{
    return new CDEditor::EditorApp{};
}

void CD::DestroyApplication(CD::Application* game)
{
    delete game;
}

namespace CDEditor
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
        CD::Vector3D<float> vec{ 1,2,3 };
        CD::Debug::Get()->Log("vec = {}", vec);

        CD::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
        if (getchar())
            Quit();
    }

}
