#pragma once
#include <Windows.h>
#include <vector>
/*ToDo: Create Structs from member ptrs*/
//Base Pointers;
static uintptr_t GameManagerOffset = 0x160B8D0; 
static uintptr_t KatanaAppOffset = 0x0166C1D8;
static uintptr_t DLDrawDevice = 0x0166C1D0;
//Basic Data Types
typedef struct Vec2
{
	float x, y;
} Vec2;

typedef struct Vec3
{
	float x, y, z;
} Vec3;

typedef struct Vec4
{
	float x, y, z, w;
} Vec4;

typedef struct Transform
{
	Vec4 rotation_x;
	Vec4 rotation_y;
	Vec4 rotation_z;
	Vec4 location;
}Transform;

typedef struct StatInt {
	int value, min, max;
} StatInt;

typedef struct StatFloat {
	float value, min, max;
} StatFloat;

typedef struct SpEffectOwner {
    uintptr_t Vftable_SpEffectOwner;
    class PlayerCtrl* m_pPlayerCtrl;
    uintptr_t m_pChrStatusAbnormalities;
    DWORD64 unknown;
} SpEffectOwner;

//Game Classes
class GameObject
{
public:
	uintptr_t vftable;
	unsigned int m_Refcount;
	char padding_0xc[4];
};

class GameEntity : public GameObject 
{
public:
	uintptr_t ptr_0x10;
	uintptr_t ptr_0x18;
};

class CharacterCtrlBase : public GameEntity
{
public:
	uintptr_t m_Heap_;
	DWORD64 unknown_0x28;
	int field_0x30;
	int field_0x34;
	uintptr_t ptr_0x38;
	uintptr_t ptr_0x40;
	uintptr_t ptr_0x48;
	int flags;
	unsigned char cam1;//???
	unsigned char cam2;
	char field_0x56[2];
};

class CharacterCtrl : public CharacterCtrlBase
{
public:
    uintptr_t ptr_0x58;
    struct Transform coordinates;
    struct Vec4 pos2;
    uintptr_t ptr_0xb0;
    uintptr_t ptr_0xb8;
    uintptr_t ptr_0xc0;
    uintptr_t ptr_0xc8;
    uintptr_t ptr_0xd0;
    uintptr_t ptr_0xd8;
    uintptr_t m_pPlayerActionControl;
    uintptr_t m_pPlayerOperator;
    uintptr_t m_pCharacterModelCtrl;
    uintptr_t m_pChrMotionControl;
    uintptr_t m_pChrPhysicsCtrl;
    int unused_;
    int unused_2;
    int field_0x110;
    int field_0x114;
    WCHAR* m_pObjectName;
    DWORD64 field_0x120;
    DWORD64 field_0x128;
    DWORD64 field_0x130;
    uintptr_t m_pHeapObject1;
    DWORD64 field_0x140;
    DWORD64 field_0x148;
    DWORD64 field_0x150;
    DWORD64 field_0x158;
    float m_PlayerSpeedMax;
    float m_PlayerSpeedMin;
    StatInt m_Health;
    int m_HealthUndead;
    char field_0x178[4];
    char filler[0x30];
    //DWORD64 field_0x17c;
    //DWORD64 field_0x184;
    //DWORD64 field_0x18c;
    //DWORD64 field_0x194;
    //DWORD64 field_0x19c;
    //DWORD64 field_0x1a4;
    StatFloat m_Stamina;
    StatFloat m_UnknownStat;
    StatFloat m_Poison;
    StatFloat m_Bleed;
    StatFloat m_UnknownStat0;
    StatFloat m_Curse;
    StatFloat m_UnknwonStat1;
    StatFloat m_Toxic;
    StatFloat m_Petrify;
    StatFloat m_UnknownStat2;
    int field_0x224;
    uintptr_t ptr_0x228;
    uintptr_t m_pChrAttackDamageCtrl;
    uintptr_t m_pChrFootEffectCtrl;
    uintptr_t m_pChrCullingGroupCtrl;
    uintptr_t m_pCharacterSfxSlotCtrl;
    uintptr_t m_pCharacterHorizontalSfxSlotCtrl;
    uintptr_t m_pChrFullBodySfxCtrl;
    uintptr_t m_pChrWepSfxCtrl;
    uintptr_t ptr_0x268;
    DWORD64 field_0x270;
    int field_0x278;
    char field_0x27c;
    char field_0x27d;
    char field_0x27e;
    char field_0x27f;
    char field_0x280[16];
    char field_0x290[16];
    float field_0x2a0;
    float field_0x2a4;
    float m_TickSpeed;
    float field_0x2ac;
    Vec4 field_0x2b0;
    Vec4 field_0x2c0;
    Vec4 field_0x2d0;
    Vec4 field_0x2e0;
    Vec4 field_0x2f0;
    Vec4 field_0x300;
    Vec4 field_0x310;
    Vec4 field_0x320;
    Vec4 field_0x330;
    Vec4 field_0x340;
    Vec4 field_0x350;
    Vec4 field_0x360;
    int field_0x370;
    int field_0x374;
    uintptr_t m_pChrAsmCtrl;
    uintptr_t m_pChrCollideReactionCtrl; /* indirect */
    uintptr_t m_pChrCollideReactionCtrl2; /* indirect+20 */
    uintptr_t m_pChrEventTriggerCtrl;
    uintptr_t m_pPlayerGameParamCalculator;
    uintptr_t m_pPlayerLockTargetCtrl;
    uintptr_t m_pChrCollideReactionCtr3;
    uintptr_t m_pChrNaviGraphLocationComponent;
    SpEffectOwner m_SpEffectOwner;
    uintptr_t m_pChrStatusAbnormalities;
    uintptr_t m_pChrSpEffectCtrl;
    uintptr_t m_pChrSpEffectSlotWatcher;
    uintptr_t ptr_0x3f0;
    uintptr_t ptr_0x3f8;
    uintptr_t m_pChrMorphemeTimeActTrackSoundCtrlCharacterInterface;
    uintptr_t ptr_0x408;
    uintptr_t m_pCharacterSoundSlotCtrl;
    uintptr_t ptr_0x418;
    uintptr_t ptr_0x420;
    char field_0x428;
    short field_0x429;
    char field_0x42b;
    int field_0x42c[6];
    int field_0x444[6];
    int field_0x45c;
    uintptr_t m_pTextureCube;
    uintptr_t m_pMapEntity;
    DWORD64 field_0x470;
    DWORD64 field_0x478;

};

class PlayerCtrl : public CharacterCtrl {
public:
    uintptr_t m_pPlayerActionCtrl;
    uintptr_t field_0x488;
    uintptr_t m_PlayerStats;
    uintptr_t field_0x498;
private:

public:
    static PlayerCtrl* GetPlayerCtrl();
    bool Godmode(bool enable);

};

typedef enum CameraMode
{
    ALTERNATIVE0 = 0,
    TOPDOWN,
    FIRSTPERSON,
    ALTERNATIVE1,
    ALTERNATIVE2,
    ALTERNATIVE3
    //6 crashes game
}CameraMode;

class CameraManager {
public:
    uintptr_t vftable;
    //DLKRD::HeapAllocator<
    //class_DLKR::DLDynamicHeap<
    //class_WinAssertHeapStrategy<
    //class_DLKR::DLBiHeapStrategy<
    //class_DLKR::DLRobustHeap,class_DLKR::DLMultiThreadingPolicy
    //>_>_>_>
    uintptr_t DLKR_MultithreadRobustHeap;
    bool m_bCameraFollowPlayer;
    char padding_0x11[15];
    uintptr_t m_pFreeCameraOperator;
    uintptr_t m_pPlayerCameraOperator;
    uintptr_t m_pIngameCameraOperator;
    char field_0x30[0x18];
    CameraMode m_CameraMode;
    int field_0x4C;
    char unused_0x50[0x120];
    //Camera Rotation/Skew/Location
public:
    static CameraManager* GetCameraManager();
};