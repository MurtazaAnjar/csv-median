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

TEST_CASE("CSVParser calculates mode for dataset with a single clear mode") {
    std::stringstream ss("1,2,2,3,4");
    CSVParser parser(ss);
    REQUIRE(parser.findMode() == 2.0);
}

TEST_CASE("CSVParser calculates mode when values are unsorted") {
    std::stringstream ss("7,1,7,3,4,2");
    CSVParser parser(ss);
    REQUIRE(parser.findMode() == 7.0);
}

TEST_CASE("CSVParser returns the first occurring mode when multiple are tied") {
    // 3 appears twice, 5 appears twice → mode = 3 (first in sorted order)
    std::stringstream ss("5,3,5,3,1");
    CSVParser parser(ss);
    REQUIRE(parser.findMode() == 3.0);
}

TEST_CASE("CSVParser calculates mean") {
    std::stringstream ss("2,4,6,8");
    CSVParser parser(ss);
    REQUIRE(parser.findMean() == 5.0);
}


TEST_CASE("CSVParser bubbleSort sorts data in ascending order") {
    std::stringstream ss("9,1,5,3");
    CSVParser parser(ss);

    REQUIRE(parser.get(0) == 1);
    REQUIRE(parser.get(1) == 3);
    REQUIRE(parser.get(2) == 5);
    REQUIRE(parser.get(3) == 9);
}

TEST_CASE("CSVParser bubbleSort handles already sorted data") {
    std::stringstream ss("1,2,3,4,5");
    CSVParser parser(ss);

    REQUIRE(parser.get(0) == 1);
    REQUIRE(parser.get(1) == 2);
    REQUIRE(parser.get(2) == 3);
    REQUIRE(parser.get(3) == 4);
    REQUIRE(parser.get(4) == 5);
}

TEST_CASE("CSVParser bubbleSort handles duplicates correctly") {
    std::stringstream ss("4,2,4,1");
    CSVParser parser(ss);

    REQUIRE(parser.get(0) == 1);
    REQUIRE(parser.get(1) == 2);
    REQUIRE(parser.get(2) == 4);
    REQUIRE(parser.get(3) == 4);
}

