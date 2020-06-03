#include "ut_driver.h"
#include "ut_math.inl"
#include "ut_performance.inl"

cd::Application* cd::CreateApplication()
{
    return new ut::driver{};
}

void cd::DestroyApplication(cd::Application* game)
{
    delete game;
}

namespace unit_tests
{

    void driver::Setup()
    {
        // ---------------------------------------------------------------------
        // Math Tests

        math::test_vec<2>();
        math::test_vec<3>();
        math::test_vec<4>();

        cd::Debug::Get()->Log("");

        // ---------------------------------------------------------------------
        // Performance Tests

        performance::test_division();

        // ---------------------------------------------------------------------
        // Exit Point

        cd::Debug::Get()->LogWarning("\nPress [Enter] to Quit the Application");
    }

    void driver::PostUpdate()
    {
        TCHAR input = cd::cin.get();
        if (input == CD_STRING('\r') || input == CD_STRING('\n'))
            Quit();
    }

}
