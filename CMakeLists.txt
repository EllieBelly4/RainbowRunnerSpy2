cmake_minimum_required(VERSION 3.19)
project(RRSpy2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-m32")
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true dll/*.h dll/*.cpp)
set(SOURCES ${SOURCES} dll/gameobjects/PathManager.cpp dll/gameobjects/PathManager.h dll/gui/views/viewhandlers/PathManagerView.cpp dll/gui/views/viewhandlers/PathManagerView.h dll/gameobjects/PathMap.cpp dll/gameobjects/PathMap.h dll/gui/views/viewhandlers/PathMapView.cpp dll/gui/views/viewhandlers/PathMapView.h dll/datatypes/PathNode.cpp dll/datatypes/PathNode.h dll/datatypes/DRFloat.h dll/datatypes/DRVectorType.h)

#add_compile_options(-masm=intel)
add_compile_options(-g)

add_library(RRSpy2 SHARED ${SOURCES}
        lib/nlohmann/json.hpp
        lib/imgui/imconfig.h
        lib/imgui/imgui.cpp
        lib/imgui/imgui.h
        lib/imgui/imgui_demo.cpp
        lib/imgui/imgui_draw.cpp
        lib/imgui/imgui_impl_dx9.cpp
        lib/imgui/imgui_impl_dx9.h
        lib/imgui/imgui_internal.h
        lib/imgui/imgui_tables.cpp
        lib/imgui/imgui_widgets.cpp
        lib/imgui/imstb_rectpack.h
        lib/imgui/imstb_textedit.h
        lib/imgui/imstb_truetype.h
        lib/imgui/imgui_impl_win32.h
        lib/imgui/imgui_impl_win32.cpp
        dll/dllmain.h dll/dllmain.cpp
        dll/rrspy.h dll/rrspy.cpp dll/rrspy.def
        dll/common.h
        dll/direct3d/IRRSpyDirect3D9.h
        dll/direct3d/IRRSpyDirect3D9.cpp
        dll/gameobjects/Entities/Avatar.h
        dll/gameobjects/Entities/Avatar.cpp
        dll/gameobjects/ServerEntity.h
        dll/gameobjects/ServerEntity.cpp
        dll/gui/general/structs.cpp
        dll/gui/general/colours.h
        dll/log/Log.h
        dll/log/Log.cpp
        dll/gui/RRSpyGUI.cpp
        dll/gui/RRSpyGUI.h
        dll/gameobjects/GameClientStateManager.cpp
        dll/gameobjects/GameClientStateManager.h
        dll/gui/GameObjectPanels.h
        dll/gui/GameObjectPanels.cpp
        dll/gameobjects/World.cpp
        dll/gameobjects/World.h
        dll/gameobjects/EntityManager.cpp
        dll/gameobjects/EntityManager.h
        dll/gameobjects/ClientEntityList.cpp
        dll/gameobjects/ClientEntityList.h
        dll/gameobjects/Entities/Player.cpp
        dll/gameobjects/Entities/Player.h
        dll/datatypes/DRString.cpp
        dll/datatypes/DRString.h
        dll/gameobjects/Entities/DFCNode.cpp
        dll/gameobjects/Entities/DFCNode.h
        dll/gameobjects/Entities/MeleeWeapon.cpp
        dll/gameobjects/Entities/MeleeWeapon.h
        dll/gameobjects/Entities/GCObject.cpp
        dll/gameobjects/Entities/GCObject.h
        dll/gameobjects/Entities/GCClass.cpp
        dll/gameobjects/Entities/GCClass.h
        dll/datatypes/DRLinkedList.cpp
        dll/datatypes/DRLinkedList.h
        dll/datatypes/GCProperties.cpp
        dll/datatypes/GCProperties.h
        dll/gameobjects/Entities/DFCClass.cpp
        dll/gameobjects/Entities/DFCClass.h
        dll/gameobjects/Entities/MeleeWeaponDesc.cpp
        dll/gameobjects/Entities/MeleeWeaponDesc.h
        dll/gui/entities/properties.cpp
        dll/gui/entities/properties.h
        dll/gui/general/gui_functions.cpp
        dll/gui/general/gui_functions.h
        dll/gui/entities/RRSpyGUIBaseEntityWrapper.cpp
        dll/gui/entities/RRSpyGUIBaseEntityWrapper.h
        dll/gui/components/RRSpyGUIList.cpp
        dll/gui/components/RRSpyGUIList.h
        dll/gui/views/RRSpyGUIInfoView.cpp
        dll/gui/views/RRSpyGUIInfoView.h
        dll/gui/views/RRSpyGUIPropertyView.cpp
        dll/gui/views/RRSpyGUIPropertyView.h
        dll/gui/RRSpyState.cpp
        dll/gui/RRSpyState.h
        dll/gameobjects/EntityContainer.cpp
        dll/gameobjects/EntityContainer.h
        dll/common.cpp
        dll/gui/views/viewhandlers/AvatarView.cpp
        dll/gui/views/viewhandlers/AvatarView.h
        dll/gui/views/viewhandlers/PlayerView.cpp
        dll/gui/views/viewhandlers/PlayerView.h
        dll/gui/views/viewhandlers/MeleeWeaponView.cpp
        dll/gui/views/viewhandlers/MeleeWeaponView.h
        dll/gui/views/viewhandlers/ViewHandler.cpp
        dll/gui/views/viewhandlers/ViewHandler.h
        dll/gui/views/viewhandlers/GCClassView.cpp
        dll/gui/views/viewhandlers/GCClassView.h
        dll/gui/views/viewhandlers/GameClientStateManagerView.cpp
        dll/gui/views/viewhandlers/GameClientStateManagerView.h
        dll/gui/views/viewhandlers/DFCNodeView.cpp
        dll/gui/views/viewhandlers/DFCNodeView.h
        dll/gui/views/viewhandlers/ClientEntityManagerView.cpp
        dll/gui/views/viewhandlers/ClientEntityManagerView.h
        dll/gui/views/viewhandlers/EntityContainerView.cpp
        dll/gui/views/viewhandlers/EntityContainerView.h
        dll/gui/views/viewhandlers/EntityView.cpp
        dll/gui/views/viewhandlers/EntityView.h
        dll/gameobjects/Entities/Entity.cpp
        dll/gameobjects/Entities/Entity.h
        dll/gameobjects/map.cpp
        dll/gameobjects/map.h
        dll/gui/views/viewhandlers/UnknownView.cpp
        dll/gui/views/viewhandlers/UnknownView.h
        dll/gui/views/viewhandlers/GCPropertiesView.cpp
        dll/gui/views/viewhandlers/GCPropertiesView.h
        dll/log/DataStream.cpp
        dll/log/DataStream.h
        dll/log/MemoryDataStream.cpp dll/log/MemoryDataStream.h
        dll/gameobjects/Entities/StaticObject.h
        dll/gui/views/viewhandlers/StaticObjectView.h
        )

include_directories(lib dll)

target_link_libraries(RRSpy2 -static-libgcc -static-libstdc++ -static -limm32 -ldwmapi)
set_target_properties(RRSpy2 PROPERTIES LINK_FLAGS "-Wl,--enable-stdcall-fixup,-Bstatic")
set_target_properties(RRSpy2 PROPERTIES PREFIX "")

set(DLL_SOURCE_PATH "${CMAKE_CURRENT_BINARY_DIR}")
string (REGEX REPLACE "/" "\\\\" DLL_SOURCE_PATH ${DLL_SOURCE_PATH})

if (DEFINED ENV{DR_GAME_DIR})
    message(STATUS "Will attempt to copy DLL from ${DLL_SOURCE_PATH}\\RRSpy2.dll to $ENV{DR_GAME_DIR}\\d3d9.dll")
    add_custom_command(TARGET RRSpy2 POST_BUILD
            COMMAND copy ${DLL_SOURCE_PATH}\\RRSpy2.dll "$ENV{DR_GAME_DIR}\\d3d9.dll"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Copying DLL to DungeonRunners directory $ENV{DR_GAME_DIR}..."
            )
else ()
    message("DLL created at ${CMAKE_CURRENT_BINARY_DIR}/RRSpy2.dll")
endif ()

include(${CMAKE_CURRENT_SOURCE_DIR}/testapp/CMakeLists.txt)
