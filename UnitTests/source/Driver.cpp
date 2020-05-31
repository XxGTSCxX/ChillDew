#include "Driver.h"
#include "MathTests.inl"

CD::Application* CD::CreateApplication()
{
    return new Tests::Driver{};
}

void CD::DestroyApplication(CD::Application* game)
{
    delete game;
}

namespace Tests
{

    void Driver::Setup()
    {
        MathTests::TestVector<2>();
        CD::Debug::Get()->LogWarning("Press [Enter] to Quit the Application");
        std::cin.get();
        Quit();
    }

}
