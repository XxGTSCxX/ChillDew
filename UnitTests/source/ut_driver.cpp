#include "ut_driver.h"
#include "ut_math.inl"
#include "ut_performance.h"

//#define ENABLE_MATH_TESTS
//#define ENABLE_PERF_TESTS

cde::app* cde::create_app()
{
    return new unit_tests::driver{};
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
        // Setup

#ifndef _DEBUG
        cde::debug::get()->enable_developer_console();
#endif // DEBUG

        // ---------------------------------------------------------------------
        // Math Tests
#ifdef ENABLE_MATH_TESTS
        math::test_vec<2>();
        math::test_vec<3>();
        math::test_vec<4>();

        cde::debug::get()->log("");
#endif
        // ---------------------------------------------------------------------
        // Performance Tests
#ifdef ENABLE_PERF_TESTS
        performance::test_division_vs_multiplication();
        performance::test_index_vs_ptr();
        performance::test_conditional_vs_multiplication();
        performance::test_if_vs_tenary();

        cde::debug::get()->log("");
#endif

        performance::test_multiplication_vs_assignment();
        cde::debug::get()->log("");

        // ---------------------------------------------------------------------
        // Exit Point

        cde::debug::get()->log_warning("Press [Enter] to Quit the app");
    }

    void driver::post_update()
    {
        TCHAR input = cd::cin.get();
        if (input == CD_STRING('\r') || input == CD_STRING('\n'))
            quit();
    }

}
