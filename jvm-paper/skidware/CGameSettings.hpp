#ifndef CGAMESETTINGS_HPP_GUARD
#define CGAMESETTINGS_HPP_GUARD
#pragma once

#include "common.h"
#include "CKeyBinding.hpp"

typedef struct CKeyBinding CKeyBinding;

typedef struct CGameSettings {
	CGameSettings(jobject);
	~CGameSettings();

	CKeyBinding* keyBindForward = nullptr;
	CKeyBinding* keyBindBack = nullptr;
	CKeyBinding* keyBindLeft = nullptr;
	CKeyBinding* keyBindRight = nullptr;
	CKeyBinding* keyBindJump = nullptr;
	CKeyBinding* keyBindSneak = nullptr;
	bool isAnyKeyDown();
private:
	jobject _klass;
} CGameSettings;

#endif //CGAMESETTINGS_HPP_GUARD
