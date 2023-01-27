#ifndef CSpeedModule_HPP_GUARD
#define CSpeedModule_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CSpeedModule : CModule {
	CSpeedModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
	float multiplier;
};
static const char* speed_modes[] = { "AAC BHop", "Spartan BHop", "MineGuard Y-Port", "Spectre BHop"};
static const char* speed_current_mode = "Spartan BHop";

#endif //CSpeedModule_HPP_GUARD
