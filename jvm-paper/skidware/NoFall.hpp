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
static const char* nofall_modes[] = { "AAC 3.3.7", "GroundSpoof"};
static const char* nofall_current_mode = "Spartan BHop";

#endif //CSpeedModule_HPP_GUARD
