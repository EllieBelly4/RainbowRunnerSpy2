//
// Created by Sophie on 25/06/2021.
//

#include "IRRSpyDirect3D9.h"

HRESULT IRRSpyDirect3D9::QueryInterface(const IID &iid, PVOID* pvoid) {
    return m_realD3d->QueryInterface(iid, pvoid);
}

ULONG IRRSpyDirect3D9::AddRef(void) {
    return m_realD3d->AddRef();
}

ULONG IRRSpyDirect3D9::Release(void) {
    return m_realD3d->Release();
}

HRESULT IRRSpyDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction) {
    return m_realD3d->RegisterSoftwareDevice(pInitializeFunction);
}

UINT IRRSpyDirect3D9::GetAdapterCount(void) {
    return m_realD3d->GetAdapterCount();
}

HRESULT IRRSpyDirect3D9::GetAdapterIdentifier(UINT uint, DWORD dword, D3DADAPTER_IDENTIFIER9* identifier9) {
    return m_realD3d->GetAdapterIdentifier(uint, dword, identifier9);
}

UINT IRRSpyDirect3D9::GetAdapterModeCount(UINT uint, D3DFORMAT dformat) {
    return m_realD3d->GetAdapterModeCount(uint, dformat);
}

HRESULT IRRSpyDirect3D9::EnumAdapterModes(UINT uint, D3DFORMAT dformat, UINT uint1, D3DDISPLAYMODE* ddisplaymode) {
    return m_realD3d->EnumAdapterModes(uint, dformat, uint1, ddisplaymode);
}

HRESULT IRRSpyDirect3D9::GetAdapterDisplayMode(UINT uint, D3DDISPLAYMODE* ddisplaymode) {
    return m_realD3d->GetAdapterDisplayMode(uint, ddisplaymode);
}

HRESULT
IRRSpyDirect3D9::CheckDeviceType(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, D3DFORMAT d3Dformat, BOOL b) {
    return m_realD3d->CheckDeviceType(uint, ddevtype, dformat, d3Dformat, b);
}

HRESULT IRRSpyDirect3D9::CheckDeviceFormat(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, DWORD dword,
                                           D3DRESOURCETYPE dresourcetype, D3DFORMAT d3Dformat) {
    return m_realD3d->CheckDeviceFormat(uint, ddevtype, dformat, dword, dresourcetype, d3Dformat);
}

HRESULT IRRSpyDirect3D9::CheckDeviceMultiSampleType(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, BOOL b,
                                                    D3DMULTISAMPLE_TYPE type, DWORD* dword) {
    return m_realD3d->CheckDeviceMultiSampleType(uint, ddevtype, dformat, b, type, dword);
}

HRESULT IRRSpyDirect3D9::CheckDepthStencilMatch(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, D3DFORMAT d3Dformat,
                                                D3DFORMAT dformat1) {
    return m_realD3d->CheckDepthStencilMatch(uint, ddevtype, dformat, d3Dformat, dformat1);
}

HRESULT
IRRSpyDirect3D9::CheckDeviceFormatConversion(UINT uint, D3DDEVTYPE ddevtype, D3DFORMAT dformat, D3DFORMAT d3Dformat) {
    return m_realD3d->CheckDeviceFormatConversion(uint, ddevtype, dformat, d3Dformat);
}

HRESULT IRRSpyDirect3D9::GetDeviceCaps(UINT uint, D3DDEVTYPE ddevtype, D3DCAPS9* dcaps9) {
    return m_realD3d->GetDeviceCaps(uint, ddevtype, dcaps9);
}

HMONITOR IRRSpyDirect3D9::GetAdapterMonitor(UINT uint) {
    return m_realD3d->GetAdapterMonitor(uint);
}

HRESULT
IRRSpyDirect3D9::CreateDevice(UINT uint, D3DDEVTYPE ddevtype, HWND hwnd, DWORD dword, D3DPRESENT_PARAMETERS* parameters,
                              IDirect3DDevice9** pDevice9) {
    return m_realD3d->CreateDevice(uint, ddevtype, hwnd, dword, parameters, pDevice9);
}

