#pragma once

//Basic Data Types
typedef struct Vec2 Vec2, *pVec2;
typedef struct Vec3 Vec3, *pVec3;
typedef struct Vec4 Vec4, *pVec4;
typedef struct StatInt StatInt;
typedef struct StatFloat StatFloat;
typedef struct Transform Transform, * pTransform;
typedef struct PlayerCtrl PlayerCtrl, *pPlayerCtrl;
struct Vec2
{
	float x, y;
};

struct Vec3
{
	float x, y, z;
};

struct Vec4
{
	float x, y, z, w;
};

struct Transform {
	struct Vec4 rotation_x;
	struct Vec4 rotation_y;
	struct Vec4 rotation_z;
	struct Vec4 location;
};

struct StatInt {
	int value, min, max;
};

struct StatFloat {
	float value, min, max;
};

struct PlayerCtrl {
	//Members
	uintptr_t vftable;
	unsigned int refcount;


	//Functions
	static PlayerCtrl* GetPlayerCtrl();
};