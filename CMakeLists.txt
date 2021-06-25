cmake_minimum_required(VERSION 3.19)
project(RRSpy2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-m32")

add_compile_options(-masm=intel)

add_library(RRSpy2 SHARED dll/dllmain.h dll/dllmain.cpp dll/rrspy dll/common dll/rrspy.def)

target_link_libraries(RRSpy2 -static-libgcc -static-libstdc++)
set_target_properties(RRSpy2 PROPERTIES LINK_FLAGS "-Wl,--enable-stdcall-fixup")
set_target_properties(RRSpy2 PROPERTIES PREFIX "")

#echo ${CMAKE_CURRENT_BINARY_DIR}/RRSpy2.dll "E:/Games/DungeonRunners v666/d3d9.dll"
add_custom_command(TARGET RRSpy2 POST_BUILD
        COMMAND copy E:\\Projects\\DungeonRunners\\RRSpy2\\cmake-build-debug\\RRSpy2.dll "E:\\Games\\DungeonRunners v666\\d3d9.dll"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Copying DLL to DungeonRunners directory..."
        )

include(${CMAKE_CURRENT_SOURCE_DIR}/testapp/CMakeLists.txt)
