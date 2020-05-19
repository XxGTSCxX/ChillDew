#define GLM_FORCE_SWIZZLE

#include "Editor.h"
#include "glm/glm.hpp"
#include "glm/gtx/projection.inl"
#include "glm/gtx/perpendicular.inl"

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
        MathTestVector2();

        CD::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
        if (getchar())
            Quit();
    }

    // -------------------------------------------------------------------------
    // Test Cases

    using vec2 = CD::Vector2D<float>;

    bool operator==(glm::vec2 const& lhs, vec2 const& rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    bool operator==(vec2 const& lhs, glm::vec2 const& rhs)
    {
        return rhs == lhs;
    }

    void EditorApp::MathTestVector2()
    {
        CD::stringstream stream;

        vec2 default_init{           };
        vec2 var_init    { 1,2       };
        vec2 fill_init   { 1         };
        vec2 copy_init   { fill_init };

        glm::vec2 glm_default_init{               };
        glm::vec2 glm_var_init    { 1,2           };
        glm::vec2 glm_fill_init   { 1             };
        glm::vec2 glm_copy_init   { glm_fill_init };

        copy_init  = vec2::up;  glm_copy_init  = glm::vec2{ 0,1 }; CD::Debug::Get()->Log("Vector2D<float>::operator=  {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init += var_init;  glm_copy_init += glm_var_init;     CD::Debug::Get()->Log("Vector2D<float>::operator+= {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init -= var_init;  glm_copy_init -= glm_var_init;     CD::Debug::Get()->Log("Vector2D<float>::operator-= {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init *= fill_init; glm_copy_init *= glm_fill_init;    CD::Debug::Get()->Log("Vector2D<float>::operator*= {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init;  glm_copy_init /= glm_var_init;     CD::Debug::Get()->Log("Vector2D<float>::operator/= {}", copy_init == glm_copy_init ? "Passed" : "Failed");

        copy_init *= var_init.y;  glm_copy_init *= glm_var_init.y; CD::Debug::Get()->Log("Vector2D<float>::operator*= {}", copy_init == glm_copy_init ? "Passed" : "Failed");
        copy_init /= var_init.y;  glm_copy_init /= glm_var_init.y; CD::Debug::Get()->Log("Vector2D<float>::operator/= {}", copy_init == glm_copy_init ? "Passed" : "Failed");

        CD::Debug::Get()->Log("Vector2D<float>::operator[] {}",  copy_init[0]     == glm_copy_init[0] ? "Passed" : "Failed");
        CD::Debug::Get()->Log("Vector2D<float>::data       {}", *copy_init.data() == glm_copy_init[0] ? "Passed" : "Failed");

        CD::Debug::Get()->Log("Vector2D<float>::size       {}", copy_init.size());
        CD::Debug::Get()->Log("Vector2D<float> operator-   {} && { {}, {} }", -copy_init, (-glm_copy_init)[0], (-glm_copy_init)[1]);
        CD::Debug::Get()->Log("Vector2D<float> operator==  {}", copy_init == copy_init ? "Passed" : "Failed");
        CD::Debug::Get()->Log("Vector2D<float> operator!=  {}", copy_init != copy_init ? "Failed" : "Passed");

        stream << copy_init;
        stream >> default_init;

        CD::Debug::Get()->Log("Vector2D<float> operator>>  {}", copy_init == default_init ? "Passed" : "Failed");

        default_init = CD::Perpendicular(copy_init); glm_default_init = glm::perp<glm::vec2>(glm_default_init, glm_default_init); CD::Debug::Get()->Log("Vector2D<float> Perpendicular {}", default_init == glm_default_init ? "Passed" : "Failed");
    }

    void EditorApp::MathTestVector3()
    {
    }

    void EditorApp::MathTestVector4()
    {
    }

    void EditorApp::MathTestVector5()
    {
    }

}
