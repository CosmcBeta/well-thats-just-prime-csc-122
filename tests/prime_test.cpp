#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <vector>

#include "../src/prime.hpp"

TEST_CASE( "#prime" ) {
    Factorizer factorizer;

    // Zero
    REQUIRE(factorizer.getPrimeFactors(0) == std::vector<int>{});
    REQUIRE(factorizer.getPrimeFactors(1) == std::vector<int>{});
    // One
    REQUIRE(factorizer.getPrimeFactors(2) == std::vector<int>{2});
    REQUIRE(factorizer.getPrimeFactors(13) == std::vector<int>{13});
    // Many
    REQUIRE(factorizer.getPrimeFactors(9) == std::vector<int>{3, 3});
    REQUIRE(factorizer.getPrimeFactors(10) == std::vector<int>{2, 5});
    REQUIRE(factorizer.getPrimeFactors(12) == std::vector<int>{2, 2, 3});
    REQUIRE(factorizer.getPrimeFactors(60) == std::vector<int>{2, 2, 3, 5});
    // Boundaries
    REQUIRE(factorizer.getPrimeFactors(97) == std::vector<int>{97});
    REQUIRE(factorizer.getPrimeFactors(49) == std::vector<int>{7, 7});
    // Exceptions
    REQUIRE(factorizer.getPrimeFactors(-5) == std::vector<int>{});
    // Sample
    REQUIRE(factorizer.getPrimeFactors(4) == std::vector<int>{2, 2});
}
