#include "Driver.h"
#include "MathTests.inl"

cd::Application* cd::CreateApplication()
{
    return new Tests::Driver{};
}

void cd::DestroyApplication(cd::Application* game)
{
    delete game;
}

namespace Tests
{

    void Driver::Setup()
    {
        MathTests::TestVector<2>();
        MathTests::TestVector<3>();
        MathTests::TestVector<4>();
        cd::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
        std::cin.get();
        Quit();
    }

}
