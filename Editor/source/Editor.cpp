#define GLM_FORCE_SWIZZLE

#include "Editor.h"
#include "glm/glm.hpp"

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
        CD::Vector3D<float> vec3{ 1,2,3   };
        CD::Vector2D<float> vec2{ vec3.yz };

        glm::vec3 glm_vec3{ 3,2,1    };
        glm::vec2 glm_vec2{ glm_vec3 };

        vec3 = CD::Vector3D<float>::one;

        CD::Debug::Get()->Log("vec2 = {}", vec2);
        CD::Debug::Get()->Log("vec3 = {}", vec3);

        CD::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
        if (getchar())
            Quit();
    }

}
