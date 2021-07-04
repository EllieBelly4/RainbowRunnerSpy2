//
// Created by Sophie on 04/07/2021.
//

#include <iomanip>
#include <iostream>
#include <windows.h>

bool IsBadReadPtr(void* p)
{
    MEMORY_BASIC_INFORMATION mbi = {0};
    if (::VirtualQuery(p, &mbi, sizeof(mbi)))
    {
        DWORD mask = (PAGE_READONLY|PAGE_READWRITE|PAGE_WRITECOPY|PAGE_EXECUTE_READ|PAGE_EXECUTE_READWRITE|PAGE_EXECUTE_WRITECOPY);
        bool b = !(mbi.Protect & mask);
        // check the page is not a guard page
        if (mbi.Protect & (PAGE_GUARD|PAGE_NOACCESS)) b = true;

        return b;
    }
    return true;
}
