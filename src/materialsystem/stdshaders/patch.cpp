#include "tier0/dbg.h"
#include <Windows.h>

const Color ColorAqua(0, 255, 200, 255);

template <typename T>
inline T PatchMemory(void* Address, T Value)
{
	T PrevMemory = *(T*)Address;
	unsigned long PrevProtect, Dummy;
	VirtualProtect(Address, sizeof(T), PAGE_EXECUTE_READWRITE, &PrevProtect);
	*(T*)Address = Value;
	VirtualProtect(Address, sizeof(T), PrevProtect, &Dummy);
	return PrevMemory;
}

struct OverrideShader
{
	OverrideShader()
	{
		ConColorMsg(ColorAqua, "Loading custom shaders...\n");

		unsigned char* materialsystem = (unsigned char*)GetModuleHandle("materialsystem.dll");
		PatchMemory<unsigned char>(materialsystem + 0x3FEDE, 0xEB);

	}
} g_OverrideShader;