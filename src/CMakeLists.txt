cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(serialize_arma)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB all_src
    "*.cc"
)
find_package(Boost 1.71  REQUIRED COMPONENTS system thread filesystem iostreams serialization)
add_executable(serialize_arma ${all_src})
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

target_link_libraries(serialize_arma LINK_PUBLIC ${Boost_LIBRARIES} ${ARMADILLO_LIBRARIES})
