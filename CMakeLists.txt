cmake_minimum_required (VERSION 2.6)
project (containers)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(coverage utest coverage)
endif()

# Link
set(SOURCE_FILES ${SOURCE_FILES} utest.cpp)
add_executable(utest ${SOURCE_FILES})
add_subdirectory(src)
add_subdirectory(tests)
target_link_libraries(utest pthread gtest)

# Settings
set_property(TARGET utest PROPERTY CXX_STANDARD 14)
set_property(TARGET utest PROPERTY CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")

