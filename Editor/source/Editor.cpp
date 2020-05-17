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
        CD::Vector2D<float> vec2{ 1,2   };
        CD::Vector3D<float> vec3{ 1,2,3 };

        CD::Debug::Get()->Log("vec2 = {}", vec2);
        CD::Debug::Get()->Log("vec3 = {}", vec3);

        CD::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
        if (getchar())
            Quit();
    }

}
