#include "DS2.h"
//PlayerCtrl Functions
PlayerCtrl * PlayerCtrl::GetPlayerCtrl()
{
	HMODULE baseAddress = GetModuleHandleA("DarksoulsII.exe");
	uintptr_t ptr = (uintptr_t)baseAddress + GameManagerOffset;
	std::vector<unsigned int> offsets = { 0xD0, 0x0 };
	PlayerCtrl* playerCtrl =  (PlayerCtrl *)Memory::ReadPointer(ptr, offsets);
	return playerCtrl;
}

bool PlayerCtrl::Godmode(bool enabled)
{
	if (!enabled) {
		this->m_Health.min = this->m_Health.max;
		this->m_HealthUndead = m_Health.max + 1;
		this->m_Stamina.min = this->m_Stamina.max;
		this->m_Bleed.max = 0;
		this->m_Poison.max = 0;
		this->m_Petrify.max = 0;
		this->m_Curse.max = 0;
		this->m_Toxic.max = 0;
		return true;
	}
	else
	{
		this->m_Health.min = -9999;
		//this->m_HealthUndead = health-(thing*undeadstatus)
		this->m_Stamina.min = -9999;
		this->m_Bleed.max = 100;
		this->m_Poison.max = 100;
		this->m_Petrify.max = 100;
		this->m_Curse.max = 100;
		this->m_Toxic.max = 100;
		return false;
	}
}

//CameraManager Functions

CameraManager* CameraManager::GetCameraManager()
{
	HMODULE baseAddress = GetModuleHandleA("DarksoulsII.exe");
	uintptr_t ptr = (uintptr_t)baseAddress + GameManagerOffset;
	std::vector<unsigned int> offsets = { 0x20, 0x0 };
	CameraManager* cameraManager = (CameraManager*) Memory::ReadPointer(ptr, offsets);
	return cameraManager;
}
