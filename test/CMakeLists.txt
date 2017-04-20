cmake_minimum_required (VERSION 2.6)
project (containers)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(coverage utest coverage)
endif()
 

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link
add_executable(utest utest.cpp unstable_vector.cpp)
target_link_libraries(utest ${GTEST_LIBRARIES} pthread)

# Settings
set_property(TARGET utest PROPERTY CXX_STANDARD 14)
set_property(TARGET utest PROPERTY CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
