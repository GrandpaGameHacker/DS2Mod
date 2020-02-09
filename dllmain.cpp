#include "dllmain.h"
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
    SetConsoleTitleA("< DS2 Debug Console >");
    AttachConsole(GetCurrentProcessId());
    freopen_s(&nullfile, "CONIN$", "r", stdin);
    freopen_s(&nullfile, "CONOUT$", "w", stdout);
    freopen_s(&nullfile, "CONOUT$", "w", stderr);
    std::cout << "[!] DS2Mod Injected!" << std::endl;
    std::cout << "[i] Created By SamsonPianoFingers" << std::endl;
    bool bGodmodeToggle = false;
    while (true)
    {
        if (GetAsyncKeyState(VK_NUMPAD0))
        {
            auto player = PlayerCtrl::GetPlayerCtrl();
            bGodmodeToggle = player->Godmode(bGodmodeToggle);
            if (bGodmodeToggle) std::cout << "[+] Godmode Enabled" << std::endl;
            else std::cout << "[-] Godmode Disabled" << std::endl;
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_DELETE))
        {
            exit();
        }
    }
};
void exit()
{
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    FreeConsole();

    HMODULE selfhandle;
    GetModuleHandleEx(0, "DS2Mod.dll", &selfhandle);
    FreeLibraryAndExitThread(selfhandle, 0);
}
