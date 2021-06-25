//
// Created by Sophie on 25/06/2021.
//

#include <d3d9.h>

#ifndef RRSPY2TESTAPP_IRRSPYDIRECT3D9_H
#define RRSPY2TESTAPP_IRRSPYDIRECT3D9_H


class IRRSpyDirect3D9 : public IDirect3D9 {
public:
    explicit IRRSpyDirect3D9(IDirect3D9* realD3d) : m_realD3d(realD3d){}

private:
    IDirect3D9* m_realD3d;

    __stdcall HRESULT QueryInterface(const IID &iid, PVOID* pvoid) override;

    __stdcall ULONG AddRef(void) override;

    __stdcall ULONG Release(void) override;

    __stdcall HRESULT RegisterSoftwareDevice(void* pInitializeFunction) override;

    __stdcall UINT GetAdapterCount(void) override;

    __stdcall HRESULT GetAdapterIdentifier(UINT uint, DWORD dword, D3DADAPTER_IDENTIFIER9* identifier9) override;

    __stdcall UINT GetAdapterModeCount(UINT uint, D3DFORMAT dformat) override;

    __stdcall HRESULT EnumAdapterModes(UINT uint, D3DFORMAT dformat, UINT uint1, D3DDISPLAYMODE* ddisplaymode) override;

    __stdcall HRESULT GetAdapterDisplayMode(UINT uint, D3DDISPLAYMODE* ddisplaymode) override;

    __stdcall HRESULT
    CheckDeviceType(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, D3DFORMAT d3Dformat, BOOL b) override;

    __stdcall HRESULT
    CheckDeviceFormat(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, DWORD dword, D3DRESOURCETYPE dresourcetype,
                      D3DFORMAT d3Dformat) override;

    __stdcall HRESULT
    CheckDeviceMultiSampleType(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, BOOL b, D3DMULTISAMPLE_TYPE type,
                               DWORD* dword) override;

    __stdcall HRESULT CheckDepthStencilMatch(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, D3DFORMAT d3Dformat,
                                             D3DFORMAT dformat1) override;

    __stdcall HRESULT
    CheckDeviceFormatConversion(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, D3DFORMAT d3Dformat) override;

    __stdcall HRESULT GetDeviceCaps(UINT uint, D3DDEVTYPE ddevtype, D3DCAPS9* dcaps9) override;

    __stdcall HMONITOR GetAdapterMonitor(UINT uint) override;

    __stdcall HRESULT
    CreateDevice(UINT uint, D3DDEVTYPE ddevtype, HWND hwnd, DWORD dword, D3DPRESENT_PARAMETERS* parameters,
                 IDirect3DDevice9** pDevice9) override;
};


#endif //RRSPY2TESTAPP_IRRSPYDIRECT3D9_H
