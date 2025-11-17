#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/DynamicArray.h"

TEST_CASE( "New DynamicArray has size 0" ) {
    DynamicArray arr;
    REQUIRE(arr.size() == 0);
}

TEST_CASE("Adding elements increases size") {
    DynamicArray arr;
    arr.push_back(10);
    REQUIRE(arr.size() == 1);

    arr.push_back(20);
    REQUIRE(arr.size() == 2);
}

TEST_CASE("Getting elements returns correct values") {
    DynamicArray arr;
    arr.push_back(5);
    arr.push_back(15);

    REQUIRE(arr.get(0) == 5);
    REQUIRE(arr.get(1) == 15);
}

TEST_CASE("Dynamic resizing works when adding many elements") {
    DynamicArray arr;
    for (int i = 0; i < 10; ++i) {
        arr.push_back(i * 2);
    }

    REQUIRE(arr.size() == 10);
    REQUIRE(arr.get(9) == 18);
}

TEST_CASE("Accessing out-of-bounds indices returns 0 or default value") {
    DynamicArray arr;
    arr.push_back(1);
    REQUIRE(arr.get(5) == 0);
}