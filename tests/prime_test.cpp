#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/prime.hpp"

TEST_CASE( "#prime" ) {
    REQUIRE( prime() == "You can delete this function and replace it with your own!" );
}
