cmake_minimum_required(VERSION 3.19)
project(RRSpy2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-m32")

#add_compile_options(-masm=intel)

add_library(RRSpy2 SHARED
        dll/dllmain.h dll/dllmain.cpp
        dll/rrspy.h dll/rrspy.cpp dll/rrspy.def
        dll/common.h
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
        dll/direct3d/IRRSpyDirect3D9.h dll/direct3d/IRRSpyDirect3D9.cpp
        dll/gameobjects/Entities/Avatar.h
        dll/gameobjects/Entities/Avatar.cpp
        dll/gameobjects/ServerEntity.h
        dll/gameobjects/ServerEntity.cpp
        dll/gui/general/structs.cpp
        dll/gui/general/colours.h
        dll/log/Log.h
        dll/log/Log.cpp
        dll/gui/RRSpyGUI.cpp dll/gui/RRSpyGUI.h dll/gameobjects/GameClientStateManager.cpp dll/gameobjects/GameClientStateManager.h dll/gui/GameObjectPanels.h dll/gui/GameObjectPanels.cpp dll/gameobjects/World.cpp dll/gameobjects/World.h dll/gameobjects/EntityManager.cpp dll/gameobjects/EntityManager.h dll/gameobjects/ClientEntity.cpp dll/gameobjects/ClientEntity.h dll/gameobjects/Entities/Player.cpp dll/gameobjects/Entities/Player.h dll/datatypes/DRString.cpp dll/datatypes/DRString.h dll/gameobjects/Entities/DFCNode.cpp dll/gameobjects/Entities/DFCNode.h dll/gameobjects/Entities/MeleeWeapon.cpp dll/gameobjects/Entities/MeleeWeapon.h dll/gameobjects/Entities/GCObject.cpp dll/gameobjects/Entities/GCObject.h dll/gameobjects/Entities/GCClass.cpp dll/gameobjects/Entities/GCClass.h dll/datatypes/DRLinkedList.cpp dll/datatypes/DRLinkedList.h dll/datatypes/GCProperties.cpp dll/datatypes/GCProperties.h dll/gameobjects/Entities/DFCClass.cpp dll/gameobjects/Entities/DFCClass.h dll/gameobjects/Entities/MeleeWeaponDesc.cpp dll/gameobjects/Entities/MeleeWeaponDesc.h dll/gui/entities/properties.cpp dll/gui/entities/properties.h dll/gui/general/gui_functions.cpp dll/gui/general/gui_functions.h dll/gui/entities/RRSpyGUIEntityWrapper.cpp dll/gui/entities/RRSpyGUIEntityWrapper.h dll/gui/components/RRSpyGUIList.cpp dll/gui/components/RRSpyGUIList.h dll/gui/views/RRSpyGUIInfoView.cpp dll/gui/views/RRSpyGUIInfoView.h dll/gui/views/RRSpyGUIPropertyView.cpp dll/gui/views/RRSpyGUIPropertyView.h dll/gui/RRSpyState.cpp dll/gui/RRSpyState.h dll/gameobjects/EntityContainer.cpp dll/gameobjects/EntityContainer.h dll/common.cpp dll/gui/views/viewhandlers/AvatarView.cpp dll/gui/views/viewhandlers/AvatarView.h dll/gui/views/viewhandlers/PlayerView.cpp dll/gui/views/viewhandlers/PlayerView.h dll/gui/views/viewhandlers/MeleeWeaponView.cpp dll/gui/views/viewhandlers/MeleeWeaponView.h dll/gui/views/viewhandlers/ViewHandler.cpp dll/gui/views/viewhandlers/ViewHandler.h dll/gui/views/viewhandlers/GCClassView.cpp dll/gui/views/viewhandlers/GCClassView.h dll/gui/views/viewhandlers/GameClientStateManagerView.cpp dll/gui/views/viewhandlers/GameClientStateManagerView.h dll/gui/views/viewhandlers/DFCNodeView.cpp dll/gui/views/viewhandlers/DFCNodeView.h)

target_link_libraries(RRSpy2 -static-libgcc -static-libstdc++ -static -limm32 -ldwmapi)
set_target_properties(RRSpy2 PROPERTIES LINK_FLAGS "-Wl,--enable-stdcall-fixup, -Bstatic")
set_target_properties(RRSpy2 PROPERTIES PREFIX "")

#echo ${CMAKE_CURRENT_BINARY_DIR}/RRSpy2.dll "E:/Games/DungeonRunners v666/d3d9.dll"
add_custom_command(TARGET RRSpy2 POST_BUILD
        COMMAND copy E:\\Projects\\DungeonRunners\\RRSpy2\\cmake-build-debug\\RRSpy2.dll "E:\\Games\\DungeonRunners v666\\d3d9.dll"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Copying DLL to DungeonRunners directory..."
        )

include(${CMAKE_CURRENT_SOURCE_DIR}/testapp/CMakeLists.txt)
