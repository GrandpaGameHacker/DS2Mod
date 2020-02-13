#include "Memory.h"

uintptr_t Memory::ReadPointer(uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		addr = *(uintptr_t*)addr;
		addr += offsets.at(i);
	}
	return addr;
}

void Memory::SetNOP(BYTE* dst, BYTE* stolenbytes, unsigned int len) {
	DWORD OldProtect;
	VirtualProtect(dst, len, PAGE_EXECUTE_READWRITE, &OldProtect);
	memcpy_s(stolenbytes, len, dst, len);
	memset(dst, 0x90, len);
	VirtualProtect(dst, len, OldProtect, &OldProtect);
}

void Memory::UndoNOP(BYTE* dst, BYTE* stolenbytes, unsigned int len)
{
	DWORD OldProtect;
	VirtualProtect(dst, len, PAGE_EXECUTE_READWRITE, &OldProtect);
	memcpy_s(dst, len, stolenbytes, len);
	VirtualProtect(dst, len, OldProtect, &OldProtect);
}