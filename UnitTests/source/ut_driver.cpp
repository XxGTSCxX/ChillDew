#include "ut_driver.h"
#include "ut_math.inl"
#include "ut_performance.h"

cde::app* cde::create_app()
{
    return new ut::driver{};
}

void cde::destroy_app(cde::app* game)
{
    delete game;
}

namespace unit_tests
{

    void driver::setup()
    {
        // ---------------------------------------------------------------------
        // Math Tests

        math::test_vec<2>();
        math::test_vec<3>();
        math::test_vec<4>();

        cde::debug::get()->log("");

        // ---------------------------------------------------------------------
        // Performance Tests

        performance::test_division();

        // ---------------------------------------------------------------------
        // Exit Point

        cde::debug::get()->log_warning("\nPress [Enter] to Quit the app");
    }

    void driver::post_update()
    {
        TCHAR input = cd::cin.get();
        if (input == CD_STRING('\r') || input == CD_STRING('\n'))
            quit();
    }

}
