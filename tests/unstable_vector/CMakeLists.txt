include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB UNSTABLE_VECTOR_SOURCES *.cpp)

target_sources(utest PRIVATE ${UNSTABLE_VECTOR_SOURCES})

set_property(TARGET utest PROPERTY CXX_STANDARD 14)
set_property(TARGET utest PROPERTY CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")