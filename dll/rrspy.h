#pragma once
//
//IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);

#include <windef.h>
#include "../lib/imgui/imgui_impl_win32.h"

// Forward declare message handler from imgui_impl_win32.cpp
extern LRESULT CALLBACK windowProc_hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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

void OnWorldUpdate();

void WorldUpdateHook();


void OnInit();

void GameExitInitResourcesHook();


void OnRender();

void RendererRenderHook();
void WorldUIOnDrawHook();
void DFCRootControlRenderHook();


void Inject(DWORD address, int bytesToPatch, DWORD func);

void Stop();