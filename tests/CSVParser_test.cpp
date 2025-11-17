#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <fstream>

#include "../src/DynamicArray.h"
#include "../src/CSVParser.h"

TEST_CASE("CSVParser reads multiple integers correctly") {
    std::stringstream ss("1,2,3,4,5");
    CSVParser parser(ss);

    REQUIRE(parser.size() == 5);
    REQUIRE(parser.get(0) == 1);
    REQUIRE(parser.get(1) == 2);
    REQUIRE(parser.get(2) == 3);
    REQUIRE(parser.get(3) == 4);
    REQUIRE(parser.get(4) == 5);
}

TEST_CASE("CSVParser handles single-value CSV") {
    std::stringstream ss("42");
    CSVParser parser(ss);

    REQUIRE(parser.size() == 1);
    REQUIRE(parser.get(0) == 42);
    REQUIRE(parser.findMedian() == 42.0);
}

TEST_CASE("CSVParser calculates median for odd number of elements") {
    std::stringstream ss("1,3,5,7,9");
    CSVParser parser(ss);

    REQUIRE(parser.findMedian() == 5.0);
}

TEST_CASE("CSVParser calculates median for even number of elements") {
    std::stringstream ss("2,4,6,8");
    CSVParser parser(ss);

    REQUIRE(parser.findMedian() == 5.0); // (4+6)/2 = 5
}

TEST_CASE("CSVParser handles empty CSV") {
    std::stringstream ss("");
    CSVParser parser(ss);

    REQUIRE(parser.size() == 0);
    // Depending on your implementation, findMedian could return 0 or NAN
    // REQUIRE(parser.findMedian() == 0.0);
}
