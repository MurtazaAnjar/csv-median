cmake_minimum_required(VERSION 3.24)

project(csv-median)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(DynamicArray_test tests/DynamicArray_test.cpp src/DynamicArray.cpp)
add_executable(CSVParser_test tests/CSVParser_test.cpp src/CSVParser.cpp src/DynamicArray.cpp)
add_executable(main main.cpp src/DynamicArray.cpp src/CSVParser.cpp)

target_link_libraries(DynamicArray_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(CSVParser_test PRIVATE Catch2::Catch2WithMain)
