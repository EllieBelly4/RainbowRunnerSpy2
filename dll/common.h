#pragma once

#include <windows.h>
#include <thread>
#include <fstream>
#include <iostream>
#include "d3d9.h"
#include "direct3d/IRRSpyDirect3D9.h"

extern HMODULE direct3dHandle;
extern IDirect3D9* direct3D9;
extern std::fstream outLog;
extern IRRSpyDirect3D9* rrSpyDirect3D9;