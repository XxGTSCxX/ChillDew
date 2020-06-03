#include "ut_performance.h"
#include "Chilldew/CD_Debug.inl"
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
            cd::Debug::Get()->Log("\tDone: {} seconds", time_span.count());
        return time_span.count();
    }

    void performance::test_division()
    {
        static constexpr std::size_t size    = std::numeric_limits<unsigned short>::max();
        static constexpr std::size_t runtime = std::numeric_limits<         short>::max();
        static constexpr std::size_t mod     = runtime >> 5;

        using val_t   = float;
        using array_t = std::array<val_t, size>;

        double division_avg = 0.0;
        double multi_avg    = 0.0;
        val_t* values       = new val_t[size]();
        val_t  divisor      = 5.0f;
        
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");
        cd::Debug::Get()->Log("// Division Performance Test"                                                    );
        cd::Debug::Get()->Log("// -----------------------------------------------------------------------------");

        cd::cout << "Initialising... ";

        for (std::size_t i = 0; i < size; ++i)
        {
            values[i] = static_cast<val_t>(rand());
        }

        cd::cout << "Complete" << std::endl;
        cd::cout << "  Division Test      : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            division_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] /= divisor;
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (division_avg /= runtime) << std::endl;
        cd::cout << "  Multiplication Test: ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            multi_avg += time_test([&]()
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

        cd::cout << " Avg Time: " << (multi_avg /= runtime) << std::endl;
        cd::Debug::Get()->Log("Result: Multiplication is {}% {} than division", division_avg * 100.0 / multi_avg, multi_avg < division_avg ? "faster" : "slower");

        delete [] values;
    }

}
