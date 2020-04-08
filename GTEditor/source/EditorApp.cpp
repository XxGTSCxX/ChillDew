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
    {}

}
