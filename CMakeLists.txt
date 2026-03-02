cmake_minimum_required(VERSION 3.5)

project(CatHash)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    "example/main.cpp"
    "lib/core_hash256.cc"
    "lib/hash256.cc"
    "lib/read_hash_file.cc"
)
add_executable(cathash_test ${SOURCES})

link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)