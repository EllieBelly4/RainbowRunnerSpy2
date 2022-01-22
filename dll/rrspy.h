#pragma once
//
//IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);

#include <memory>
#include <windef.h>
#include "../lib/imgui/imgui_impl_win32.h"
#include "gui/RRSpyGUI.h"

extern "C" __declspec(dllexport) void DoIt();

const DWORD worldUpdatePatchAddress = 0x004D0016;
const DWORD worldUpdateReturnAddress = worldUpdatePatchAddress + 6;

const DWORD gameExitInitResourcesPatchAddress = 0x004093E3;
const DWORD gameExitInitResourcesReturnAddress = gameExitInitResourcesPatchAddress + 6;

const DWORD rendererRenderPatchAddress = 0x00659CD7;
const DWORD rendererRenderReturnAddress = rendererRenderPatchAddress + 6;

const DWORD worldUIOnDrawPatchAddress = 0x0047DE2D;
const DWORD worldUIOnDrawReturnAddress = worldUIOnDrawPatchAddress + 6;

const DWORD DFCRootControlRenderPatchAddress = 0x00684E44;
const DWORD DFCRootControlRenderReturnAddress = DFCRootControlRenderPatchAddress + 6;

const DWORD GameClientUpdateAppPatchAddress = 0x00408D12;
const DWORD GameClientUpdateAppReturnAddress = GameClientUpdateAppPatchAddress + 6;

void OnWorldUpdate();

void WorldUpdateHook();


void OnInit();

void GameExitInitResourcesHook();

void GameClientUpdateAppHook();

void OnRender();

void OnUpdate();

void RendererRenderHook();

void WorldUIOnDrawHook();

void DFCRootControlRenderHook();

void Inject(DWORD address, int bytesToPatch, DWORD func);

void Stop();