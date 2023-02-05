#ifndef CJesusModule_HPP_GUARD
#define CJesusModule_HPP_GUARD
#pragma once

#include "CModule.hpp"
static const char* jesus_modes[] = { "AAC 4.2.1", "Dolphin" };
static const char* jesus_current_mode = "AAC 4.2.1";
typedef struct CJesusModule : CModule {
	CJesusModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
private:
	static inline char* displayName = "Jesus";
};


#endif //CNoFallModule_HPP_GUARD
