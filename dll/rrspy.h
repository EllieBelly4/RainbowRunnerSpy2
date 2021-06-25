#pragma once
//
//IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);

extern "C" __declspec(dllexport) void DoIt();

void SpyStart();
void InjectSpy();
void Stop();