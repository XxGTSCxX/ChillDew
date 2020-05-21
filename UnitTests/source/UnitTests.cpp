#include "UnitTests.h"

CD::Application* CD::CreateApplication()
{
    return new Tests::UnitTests{};
}

void CD::DestroyApplication(CD::Application* game)
{
    delete game;
}

namespace Tests
{

    void UnitTests::Setup()
    {
    }

}
