
#ifndef CPATCH_HPP_GUARD
#define CPATCH_HPP_GUARD
#pragma once

#include "common.h"

#define CALLVOID(a) ((void (__cdecl *)())a)()
#define CALLVOIDRETCHAR(a) ((char (__cdecl *)())a)()
#define READPVOID(a) (*(void **)a)
#define READCHAR(a) (*(char *)a)

typedef struct CPatch {
private:
	inline static void Patch(void* address, void* data, int size) {
		unsigned long protect[2];
		VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memcpy(address, data, size);
		VirtualProtect(address, size, protect[0], &protect[1]);
	}
public:
	inline static void Nop(long long address, int size) {
		unsigned long protect[2];
		VirtualProtect((void*)address, size, PAGE_EXECUTE_READWRITE, &protect[0]);
		memset((void*)address, 0x90, size);
		VirtualProtect((void*)address, size, protect[0], &protect[1]);
	}
	inline static bool CheckChar(long long address, unsigned char value) {
		unsigned long protect[2];
		unsigned char dummy = value;
		VirtualProtect((void*)address, 1, PAGE_EXECUTE_READ, &protect[0]);
		memcpy(&dummy, (void*)address, 1);
		VirtualProtect((void*)address, 1, protect[0], &protect[1]);
		return (dummy == value);
	}
	inline static void RedirectCall(long long address, void* func) {
		int temp = 0xE8; //places a call
		Patch((void*)address, &temp, 1);
		temp = (int)func - ((int)address + 5);
		Patch((void*)((int)address + 1), &temp, 8);
	}
	inline static void RedirectJump(long long address, void* func) {
		int temp = 0xE9; //places a jmp
		Patch((void*)address, &temp, 1);
		temp = (int)func - ((int)address + 5);
		Patch((void*)((int)address + 1), &temp, 8);
	}
	inline static void SetChar(long long address, char value) {
		Patch((void*)address, &value, 1);
	}
	inline static void SetShort(long long address, short value) {
		Patch((void*)address, &value, 2);
	}
	inline static void SetInt(long long address, int value) {
		Patch((void*)address, &value, 4);
	}
	inline static void SetFloat(long long address, float value) {
		Patch((void*)address, &value, 4);
	}
	inline static void SetPointer(long long address, void* value) {
		Patch((void*)address, &value, 8);
	}
} CPatch;

#endif //CPATCH_HPP_GUARD