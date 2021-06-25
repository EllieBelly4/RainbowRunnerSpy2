#pragma once
//
//IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);

#include <windef.h>

extern "C" __declspec(dllexport) void DoIt();

const DWORD worldUpdatePatchAddress = 0x004D0016;
const DWORD worldUpdateReturnAddress = worldUpdatePatchAddress + 6;

const DWORD gameExitInitResourcesPatchAddress = 0x004093E3;
const DWORD gameExitInitResourcesReturnAddress = gameExitInitResourcesPatchAddress + 6;

const DWORD rendererRenderPatchAddress = 0x00659CD7;
const DWORD rendererRenderReturnAddress = rendererRenderPatchAddress + 6;


void OnWorldUpdate();

void WorldUpdateHook();


void OnGameExitInitResources();

void GameExitInitResourcesHook();


void OnRendererRender();

void RendererRenderHook();


void Inject(DWORD address, int bytesToPatch, DWORD func);

void Stop();