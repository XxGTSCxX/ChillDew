#include "ut_performance.h"
#include "Chilldew-Utility.h"
#include <limits>  // std::numeric_limits
#include <cstddef> // std::size_t
#include <chrono>  // std::chrono
#include <array>   // std::array

namespace unit_tests
{

    static constexpr std::size_t size    = std::numeric_limits<unsigned short>::max() >> 1;
    static constexpr std::size_t runtime = std::numeric_limits<short>::max();
    static constexpr std::size_t mod     = runtime >> 5;

    void performance::test_division_vs_multiplication()
    {
        using val_t   = float;
        using array_t = std::array<val_t, size>;
        
        cde::debug::get()->log("// -----------------------------------------------------------------------------");
        cde::debug::get()->log("// Division vs Multiplication Performance Test"                                  );
        cde::debug::get()->log("// -----------------------------------------------------------------------------");

        cd::cout << "Initialising... ";
        
        val_t* values  = new val_t[size]();
        val_t  divisor = 5.0f;
        double div_avg = 0.0;
        double mul_avg = 0.0;

        for (std::size_t i = 0; i < size; ++i)
        {
            values[i] = static_cast<val_t>(rand());
        }

        cd::cout << "Complete" << std::endl;
        cd::cout << "  Division Test      : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            div_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] /= divisor;
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (div_avg /= runtime) << std::endl;
        cd::cout << "  Multiplication Test: ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            mul_avg += time_test([&]()
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

        cd::cout << " Avg Time: " << (mul_avg /= runtime) << std::endl;

        double mul_vs_div = div_avg * 100.0 / mul_avg;

        cde::debug::get()->log("Result: Multiplication is {}% {} than division", mul_vs_div, mul_vs_div >= 100.0 ? "faster" : "slower");

        delete [] values;
    }

    void performance::test_index_vs_ptr()
    {
        using val_t   = float;
        using array_t = std::array<val_t, size>;
        
        cde::debug::get()->log("// -----------------------------------------------------------------------------");
        cde::debug::get()->log("// Index vs Ptr Performance Test"                                                );
        cde::debug::get()->log("// -----------------------------------------------------------------------------");

        cd::cout << "Initialising... ";

        val_t* values  = new val_t[size]();
        double i_avg   = 0.0;
        double p_avg   = 0.0;

        for (std::size_t i = 0; i < size; ++i)
        {
            values[i] = static_cast<val_t>(rand());
        }

        cd::cout << "Complete" << std::endl;
        cd::cout << "  Index Test: ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            i_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] /= values[i];
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (i_avg /= runtime) << std::endl;
        cd::cout << "  Ptr Test  : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            p_avg += time_test([&]()
            {
                for (val_t* curr = values, *end = curr + size; curr != end; ++curr)
                {
                    *curr /= *curr;
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (p_avg /= runtime) << std::endl;

        double index_vs_ptr = p_avg * 100.0 / i_avg;

        cde::debug::get()->log("Result: Index vs Ptr - Index was {}& {} than ptr", index_vs_ptr, index_vs_ptr >= 100.0 ? "faster" : "slower");

        delete [] values;
    }

    void performance::test_conditional_vs_multiplication()
    {
        using val_t   = float;
        using array_t = std::array<val_t, size>;
        
        cde::debug::get()->log("// -----------------------------------------------------------------------------");
        cde::debug::get()->log("// Conditional vs Multiplication Performance Test"                               );
        cde::debug::get()->log("// -----------------------------------------------------------------------------");

        cd::cout << "Initialising... ";

        val_t* values  = new val_t[size]();
        double c_avg   = 0.0;
        double m_avg   = 0.0;

        for (std::size_t i = 0; i < size; ++i)
        {
            values[i] = static_cast<val_t>(rand());
        }

        cd::cout << "Complete" << std::endl;
        cd::cout << "  Conditional Test   : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            c_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] = rand() % 2 ? values[i] : -values[i];
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (c_avg /= runtime) << std::endl;
        cd::cout << "  Multiplication Test: ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            m_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] = (1 + (rand() % 2) * -2) * values[i];
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (m_avg /= runtime) << std::endl;

        double con_vs_mul = m_avg * 100.0 / c_avg;

        cde::debug::get()->log("Result: Conditional was {}& {} than multiplication", con_vs_mul, con_vs_mul >= 100.0 ? "faster" : "slower");

        delete [] values;
    }

    void performance::test_if_vs_tenary()
    {
        using val_t   = float;
        using array_t = std::array<val_t, size>;
        
        cde::debug::get()->log("// -----------------------------------------------------------------------------");
        cde::debug::get()->log("// If vs Tenary Performance Test"                                                );
        cde::debug::get()->log("// -----------------------------------------------------------------------------");

        cd::cout << "Initialising... ";

        val_t* values  = new val_t[size]();
        double c_avg   = 0.0;
        double m_avg   = 0.0;

        for (std::size_t i = 0; i < size; ++i)
        {
            values[i] = static_cast<val_t>(rand());
        }

        cd::cout << "Complete" << std::endl;
        cd::cout << "  Tenary Test: ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            c_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    values[i] = rand() % 2 ? values[i] : -values[i];
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (c_avg /= runtime) << std::endl;
        cd::cout << "  If Test    : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            m_avg += time_test([&]()
            {
                for (std::size_t i = 0; i < size; ++i)
                {
                    if (rand() % 2)
                        values[i] = values[i];
                    else
                        values[i] = -values[i];
                }
            }, true);
            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (m_avg /= runtime) << std::endl;

        double con_vs_mul = m_avg * 100.0 / c_avg;

        cde::debug::get()->log("Result: Tenary was {}& {} than if", con_vs_mul, con_vs_mul >= 100.0 ? "faster" : "slower");

        delete [] values;
    }

    struct base
    {
        base() = default;
        base(cdu::type::id_t true_type)
        : m_type{ true_type }
        {}

        cdu::type::id_t type_id() const
        {
            return m_type;
        }

        void hi() { throw; };

    private:

        cdu::type::id_t m_type = cdu::type::id<base>();
    };

    struct derived : base
    {
        derived()
        : base{ cdu::type::id<derived>() }
        {}

        derived(cdu::type::id_t true_type)
        : base{ true_type }
        {}

        void hi() {};
    };

    struct v_base
    {
        virtual ~v_base() = default;

        void hi() { throw; };
    };

    struct v_derived : v_base
    {
        void hi() {};
    };

    void performance::test_virtual_vs_static()
    {
        cde::debug::get()->log("// -----------------------------------------------------------------------------");
        cde::debug::get()->log("// Virtual vs Custom Compare"                                                    );
        cde::debug::get()->log("// -----------------------------------------------------------------------------");

        cd::cout << "Initialising... ";

        cdu::type::register_type  <base            >();
        cdu::type::register_type  <derived         >();
        cdu::type::register_parent<base   , derived>();

        using val_t = std::pair<std::unique_ptr<base>, std::unique_ptr<v_base>>;

        std::vector<val_t> values;
        std::size_t        count = size;
        double             c_avg = 0.0;
        double             m_avg = 0.0;

        values.reserve(count);

        while (count--)
        {
            values.emplace_back(std::make_unique<derived>(), std::make_unique<v_derived>());
        }

        cd::cout << "Complete" << std::endl;
        cd::cout << "  Virtual Test: ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            c_avg += time_test([&]()
                {
                    for (std::size_t i = 0; i < size; ++i)
                    {
                        if (auto&& ptr = dynamic_cast<v_derived*>(values[i].second.get()))
                            ptr->hi();
                    }
                }, true);

            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (c_avg /= runtime) << std::endl;
        cd::cout << "  Custom Test : ";

        for (std::size_t run = 0; run < runtime; ++run)
        {
            m_avg += time_test([&]()
                {
                    for (std::size_t i = 0; i < size; ++i)
                    {
                        if (cdu::type::is_base_of(values[i].first->type_id(), cdu::type::id<derived>()))
                            reinterpret_cast<derived*>(values[i].first.get())->hi();
                    }
                }, true);

            if (!(run % mod))
                cd::cout << '.';
        }

        cd::cout << " Avg Time: " << (m_avg /= runtime) << std::endl;

        double con_vs_mul = m_avg * 100.0 / c_avg;

        cde::debug::get()->log("Result: Virtual was {}% {} than custom", con_vs_mul, con_vs_mul >= 100.0 ? "faster" : "slower");
    }

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

}
