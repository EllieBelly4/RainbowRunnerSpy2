cmake_minimum_required(VERSION 3.19)
project(RRSpy2TestApp)

set (APPEND CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive")

add_executable(RRSpy2TestApp testapp/main)

target_link_libraries(RRSpy2TestApp RRSpy2)

