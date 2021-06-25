// dllmain.cpp : Defines the entry point for the DLL application.
#include "common.h"
#include "dllmain.h"
#include "rrspy.h"

HMODULE handle;
std::fstream outLog;

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
//            MessageBox(NULL, "Hello", "There", MB_OKCANCEL | MB_DEFBUTTON2);
            InjectSpy();
            handle = LoadLibraryA(
                    "C:\\Windows\\SysWOW64\\d3d9.dll"
            );
            break;
        case DLL_PROCESS_DETACH:
            Stop();
            break;
    }
    return TRUE;
}

// Exported function (faking d3d9.dll's one-and-only export)
IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion) {
    typedef IDirect3D9* (WINAPI* D3D9_Type)(UINT SDKVersion);
    auto D3DCreate9_fn = (D3D9_Type) GetProcAddress(handle, "Direct3DCreate9");
    return D3DCreate9_fn(SDKVersion);
}