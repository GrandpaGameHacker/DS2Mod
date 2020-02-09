#pragma once
#include <Windows.h>
#include <vector>
//64Bit only
namespace Memory {
	uintptr_t ReadPointer(uintptr_t ptr, std::vector<unsigned int> offsets);
}