#ifndef CJAVAHOOK_HPP_GUARD
#define CJAVAHOOK_HPP_GUARD
#pragma once

#include "common.h"
#include "CMethod.hpp"

typedef enum struct EHookType {
	//do not use overwrite until i fix it - xwhitey (suka blyat ya ne mogu na unicode pisat')
	OVERWRITE = 0,
	APPEND = 1,
} CHookType;

typedef struct CJavaHook {
	explicit CJavaHook(_In_ CMethod* _Method, _In_ EHookType _HookType, _In_ void** _Hooked, _In_opt_ void** _Original) {
		if (_HookType == CHookType::APPEND) {
			MH_STATUS status = MH_CreateHook(/*_Method->_from_compiled_entry */ reinterpret_cast<void(__cdecl*)(void**, void**)>(*(unsigned long long*)(*(unsigned long long*)_Method + 0x40)), _Hooked, _Original);
			if (status != MH_OK) {
				printf("Failed to create detours for compiled entry: %s\n", MH_StatusToString(status));
			} else {
				//MH_EnableHook(_Hooked);
				// to be sure if we are enabling our hook - xwhitey
				status = MH_EnableHook(MH_ALL_HOOKS);
				if (status != MH_OK) {
					printf("Failed to enable detours for compiled entry: %s\n", MH_StatusToString(status));
				} else {
					printf("chitty chitty bang bang :sunglasses:\n");
				}
			}
		} else if (_HookType == CHookType::OVERWRITE) {
			//_Method->setNative();
			//WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(*(unsigned long long*)_Method->_i2i_entry), &_Hooked, sizeof(unsigned long long), NULL);
			//WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(*(unsigned long long*)_Method->_from_interpreted_entry), &_Hooked, sizeof(unsigned long long), NULL);
			_Method->_i2i_entry = *(unsigned char**)_Hooked;
			_Method->_from_interpreted_entry = *(unsigned char**)_Hooked;
		}
	}
} JavaHook;

#endif //CJAVAHOOK_HPP_GUARD
