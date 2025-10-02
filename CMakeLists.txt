cmake_minimum_required(VERSION 3.24)

project(well_thats_just_prime)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(prime_test tests/prime_test.cpp src/prime.cpp)
add_executable(main main.cpp src/prime.cpp)

target_link_libraries(prime_test PRIVATE Catch2::Catch2WithMain)
