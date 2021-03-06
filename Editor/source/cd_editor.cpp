#include "cd_editor.h"

cde::app* cde::create_app()
{
    return new cd::editor{};
}

void cde::destroy_app(cde::app* game)
{
    delete game;
}

namespace chilldew
{

    editor::editor()
    {
        stop();
    }

    bool editor::is_editor() const
    {
        return true;
    }

    struct test_type
    {};

    void editor::setup()
    {
        cde::debug::get()->enable_developer_console();

        cde::debug::get()->log("Working Directory: {}", cdu::filesystem::get()->convert_path(cdu::filesystem::path{ CD_L("assets"), CD_L("") }));
        cde::debug::get()->log("User Directory   : {}", cdu::filesystem::get()->convert_path(cdu::filesystem::path{ CD_L("user"  ), CD_L("") }));

        cde::debug::get()->log_warning("Press [Enter] to Quit the app");
        std::cin.get();
        quit();
    }

}
