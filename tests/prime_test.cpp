#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <vector>

#include "../src/prime.hpp"
#include "catch2/internal/catch_decomposer.hpp"

TEST_CASE( "prime_factors" ) {
    Factorizer factorizer;

    // Zero
    REQUIRE(factorizer.primeFactors(0) == std::vector<int>{});
    REQUIRE(factorizer.primeFactors(1) == std::vector<int>{});
    // One
    REQUIRE(factorizer.primeFactors(2) == std::vector<int>{2});
    REQUIRE(factorizer.primeFactors(13) == std::vector<int>{13});
    // Many
    REQUIRE(factorizer.primeFactors(9) == std::vector<int>{3, 3});
    REQUIRE(factorizer.primeFactors(10) == std::vector<int>{2, 5});
    REQUIRE(factorizer.primeFactors(12) == std::vector<int>{2, 2, 3});
    REQUIRE(factorizer.primeFactors(60) == std::vector<int>{2, 2, 3, 5});
    // Boundaries
    REQUIRE(factorizer.primeFactors(97) == std::vector<int>{97});
    REQUIRE(factorizer.primeFactors(49) == std::vector<int>{7, 7});
    // Exceptions
    REQUIRE(factorizer.primeFactors(-5) == std::vector<int>{});
    // Sample
    REQUIRE(factorizer.primeFactors(4) == std::vector<int>{2, 2});
}

TEST_CASE("isPrime")
{
    Factorizer factorizer;
    // Zero
    REQUIRE(factorizer.isPrime(0) == false);
    REQUIRE(factorizer.isPrime(1) == false);
    // One
    REQUIRE(factorizer.isPrime(2) == true);
    REQUIRE(factorizer.isPrime(13) == true);
    // Many
    REQUIRE(factorizer.isPrime(9) == false);
    REQUIRE(factorizer.isPrime(10) == false);
    REQUIRE(factorizer.isPrime(12) == false);
    REQUIRE(factorizer.isPrime(60) == false);
    // Boundaries
    REQUIRE(factorizer.isPrime(97) == true);
    REQUIRE(factorizer.isPrime(49) == false);
    // Exceptions
    REQUIRE(factorizer.isPrime(-5) == false);
    // Sample
    REQUIRE(factorizer.isPrime(4) == false);
}

TEST_CASE("reduce")
{
    Factorizer factorizer;
    // Zero
    REQUIRE(factorizer.reduce(0, 5) == "0");
    REQUIRE(factorizer.reduce(5, 0) == "UNDEFINED"); // if you decide division by 0 should throw
    // One
    REQUIRE(factorizer.reduce(1, 1) == "1");
    REQUIRE(factorizer.reduce(12, 12) == "1");
    REQUIRE(factorizer.reduce(1, 5) == "1/5");
    REQUIRE(factorizer.reduce(5, 1) == "5");
    // Many
    REQUIRE(factorizer.reduce(36, 12) == "3");     // multiple factors cancel out
    REQUIRE(factorizer.reduce(150, 100) == "3/2"); // reduces by 50
    // Boundaries
    REQUIRE(factorizer.reduce(-12, 8) == "-3/2");  // sign handling
    REQUIRE(factorizer.reduce(12, -8) == "-3/2");  // denominator negative
    REQUIRE(factorizer.reduce(-12, -8) == "3/2");  // double negative
    // Exceptions
    REQUIRE(factorizer.reduce(7, 0) == "UNDEFINED");
    // Sample
    REQUIRE(factorizer.reduce(12, 14) == "6/7");
    REQUIRE(factorizer.reduce(12, 37) == "12/37");
}
