#include "pch.h"
#include "DS2.h"
#include "Memory.h"

//PlayerCtrl Functions
PlayerCtrl * PlayerCtrl::GetPlayerCtrl()
{
	HMODULE baseAddress = GetModuleHandleA("DarksoulsII.exe");
	uintptr_t ptr = (uintptr_t)baseAddress + GameManagerOffset;
	std::vector<unsigned int> offsets = { 0xD0, 0x0 };
	PlayerCtrl* playerCtrl =  (PlayerCtrl *)Memory::ReadPointer(ptr, offsets);
	return playerCtrl;
}

//CameraManager Functions

CameraManager* CameraManager::GetCameraManager()
{
	HMODULE baseAddress = GetModuleHandleA("DarksoulsII.exe");
	uintptr_t ptr = (uintptr_t)baseAddress + GameManagerOffset;
	std::vector<unsigned int> offsets = { 0x20, 0x0 };
	CameraManager* cameraManager = (CameraManager*)Memory::ReadPointer(ptr, offsets);
	return cameraManager;
}
