// dllmain.cpp : Defines the entry point for the DLL application.
#include "common.h"
#include "dllmain.h"
#include "rrspy.h"
#include "direct3d/IRRSpyDirect3D9.h"

HMODULE direct3dHandle;
IDirect3D9* direct3D9;
IRRSpyDirect3D9* rrSpyDirect3D9;
std::fstream outLog;

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            outLog.open("logs\\runlog.txt", std::ios_base::out | std::ios_base::app);
            outLog << "Attach";
//            hwnd = GetActiveWindow();
//            MessageBox(NULL, "Hello", "There", MB_OKCANCEL | MB_DEFBUTTON2);
            Inject((DWORD) worldUpdatePatchAddress, 6, (DWORD) WorldUpdateHook);
//            Inject((DWORD) rendererRenderPatchAddress, 6, (DWORD) RendererRenderHook);
//            Inject((DWORD) worldUIOnDrawPatchAddress, 6, (DWORD) WorldUIOnDrawHook);
            Inject((DWORD) DFCRootControlRenderPatchAddress, 7, (DWORD) DFCRootControlRenderHook);
            Inject((DWORD) gameExitInitResourcesPatchAddress, 6, (DWORD) GameExitInitResourcesHook);
            Inject((DWORD) GameClientUpdateAppPatchAddress, 7, (DWORD) GameClientUpdateAppHook);

            direct3dHandle = LoadLibraryA(
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
    auto D3DCreate9_fn = (D3D9_Type) GetProcAddress(direct3dHandle, "Direct3DCreate9");
    direct3D9 = D3DCreate9_fn(SDKVersion);
    rrSpyDirect3D9 = new IRRSpyDirect3D9(direct3D9);

    return rrSpyDirect3D9;
}