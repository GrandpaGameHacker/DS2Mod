#pragma once
#include <Windows.h>
#include <Vector>

namespace Memory
{
	uintptr_t ReadPointer(uintptr_t ptr, std::vector<unsigned int> offsets);
	void SetNOP(BYTE* dst, BYTE* stolenbytes, unsigned int len);
	void UndoNOP(BYTE* dst, BYTE* stolenbytes, unsigned int len);
}