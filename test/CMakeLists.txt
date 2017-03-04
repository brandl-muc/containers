cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link
add_executable(utest utest.cpp unstable_vector.cpp)
target_link_libraries(utest ${GTEST_LIBRARIES} pthread)

# Settings
set_property(TARGET utest PROPERTY CXX_STANDARD 14)
set_property(TARGET utest PROPERTY CXX_STANDARD_REQUIRED on)

