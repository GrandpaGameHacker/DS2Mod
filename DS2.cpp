#include "pch.h"
#include "DS2.h"
#include "Memory.h"
PlayerCtrl * PlayerCtrl::GetPlayerCtrl()
{
	HMODULE baseAddress = GetModuleHandleA("DarksoulsII.exe");
	uintptr_t ptr = (uintptr_t)baseAddress + 0x160B8D0;
	std::vector<unsigned int> offsets = { 0xD0, 0x0 };
	PlayerCtrl* playerCtrl =  (PlayerCtrl *)Memory::ReadPointer(ptr, offsets);
	return playerCtrl;
}
