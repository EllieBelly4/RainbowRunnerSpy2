cmake_minimum_required(VERSION 3.19)
project(RRSpy2TestApp)

set (APPEND CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive, -Wno-dev")

add_executable(RRSpy2TestApp testapp/main.cpp)

target_link_libraries(RRSpy2TestApp RRSpy2)

