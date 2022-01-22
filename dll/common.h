#pragma once

#include <windows.h>
#include <thread>
#include <fstream>
#include <iostream>
#include <memory>
#include "d3d9.h"
#include "direct3d/IRRSpyDirect3D9.h"
#include "log/Log.h"
#include "log/DataStream.h"
#include "log/MemoryDataStream.h"

extern HMODULE direct3dHandle;
extern IDirect3D9* direct3D9;
extern std::fstream outLog;
extern std::shared_ptr<RRLog::Log> logger;
extern std::shared_ptr<RRLog::DataStream> dataStream;
extern std::shared_ptr<RRLog::MemoryDataStream> memoryDataStream;
extern IRRSpyDirect3D9* rrSpyDirect3D9;
extern WNDPROC gameWndProcHandler;

bool IsBadReadPtr(void*);