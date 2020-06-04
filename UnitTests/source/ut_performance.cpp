#include "ut_performance.h"
#include "cde_debug.inl"
#include <limits>  // std::numeric_limits
#include <cstddef> // std::size_t
#include <chrono>  // std::chrono
#include <array>   // std::array

namespace unit_tests
{

    double performance::time_test(std::function<void()> const& function, bool suppress_print)
    {
        const auto t1 = std::chrono::high_resolution_clock::now();
        function();
        const auto t2        = std::chrono::high_resolution_clock::now();
        const auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        if (!suppress_print)
            cde::debug::get()->log("\tDone: {} seconds", time_span.count());
        return time_span.count();
    }

    void performance::test_division()
    {
        static constexpr std::size_t size    = std::numeric_limits<unsigned short>::max();
        static constexpr std::size_t runtime = std::numeric_limits<short>::max();
        static constexpr std::size_t mod     = runtime >> 5;

        using val_t   = float;
        using array_t = std::array<val_t, size>;

        double div_i_avg = 0.0;
        double div_p_avg = 0.0;
        double mul_i_avg = 0.0;
        double mul_p_avg = 0.0;
        val_t* values    = new val_t[size]();
        val_t  divisor   = 5.0f;
        
        cde::debug::get()->log("// -----------------------------------------------------------------------------");
        cde::debug::get()->log("// Division Performance Test"                                                    );
        cde::debug::get()->log("// -----------------------------------------------------------------------------");

        cd::cout << "Initialising... ";

        for (std::size_t i = 0; i < size; ++i)
        {
            values[i] = static_cast<val_t>(rand());
        }

        cd::cout << "Complete" << std::endl;
        cd::cout << "  Division Test       (index): ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            div_i_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] /= divisor;
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (div_i_avg /= runtime) << std::endl;
        cd::cout << "  Division Test       (ptr)  : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            div_p_avg += time_test([&]()
            {
                for (val_t* curr = values, *end = curr + size; curr != end; ++curr)
                {
                    *curr /= divisor;
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (div_p_avg /= runtime) << std::endl;
        cd::cout << "  Multiplication Test (index): ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            mul_i_avg += time_test([&]()
            {
                val_t inv_divisor = 1.0f / divisor;
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] *= inv_divisor;
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (mul_i_avg /= runtime) << std::endl;
        cd::cout << "  Multiplication Test (ptr)  : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            mul_p_avg += time_test([&]()
            {
                val_t inv_divisor = 1.0f / divisor;
                for (val_t* curr = values, *end = curr + size; curr != end; ++curr)
                {
                    *curr *= inv_divisor;
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (mul_p_avg /= runtime) << std::endl;

        double index_ratio  = div_i_avg * 100.0 / mul_i_avg;
        double ptr_ratio    = div_p_avg * 100.0 / mul_p_avg;
        double index_vs_ptr = (div_p_avg / div_i_avg + mul_p_avg / mul_i_avg) * 50.0;

        cde::debug::get()->log("Result: (Index) Multiplication is {}% {} than division", index_ratio , index_ratio  >= 100.0 ? "faster" : "slower");
        cde::debug::get()->log("Result: (Ptr  ) Multiplication is {}% {} than division", ptr_ratio   , ptr_ratio    >= 100.0 ? "faster" : "slower");
        cde::debug::get()->log("Result: Index vs Ptr - Index was {}& {} than ptr"      , index_vs_ptr, index_vs_ptr >= 100.0 ? "faster" : "slower");

        delete [] values;
    }

}
