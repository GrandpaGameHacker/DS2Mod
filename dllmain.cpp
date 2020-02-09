#include "pch.h"
#include "dllmain.h"
#include <cstdio>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Hackthread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

void Hackthread()
{
    FILE* nullfile = nullptr;
    AllocConsole();
    SetConsoleTitleA("<DS2_DebugConsole>");
    AttachConsole(GetCurrentProcessId());
    freopen_s(&nullfile, "CONIN$", "r", stdin);
    freopen_s(&nullfile, "CONOUT$", "w", stdout);
    freopen_s(&nullfile, "CONOUT$", "w", stderr);

    while (true)
    {
        if(GetAsyncKeyState(VK_NUMPAD0)) {
            // Mod1
        }
        /*Implement exit code with key combination
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
        FreeConsole();

        HMODULE selfhandle;
        GetModuleHandleEx(0, moduleName, &selfhandle);
        FreeLibraryAndExitThread(selfhandle, 0)
        */
    }
};