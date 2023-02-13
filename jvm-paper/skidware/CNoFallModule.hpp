#ifndef CNoFallModule_HPP_GUARD
#define CNoFallModule_HPP_GUARD
#pragma once

#include "CModule.hpp"
static const char* nofall_modes[] = { "AAC 3.3.7", "Motion", "Spoof"};
static const char* nofall_current_mode = "AAC 3.3.7";
typedef struct CNoFallDamageModule : CModule {
	CNoFallDamageModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
private:
	static inline char* displayName = (char*)nofall_current_mode;
};

static int force = -6;



#endif //CNoFallModule_HPP_GUARD
