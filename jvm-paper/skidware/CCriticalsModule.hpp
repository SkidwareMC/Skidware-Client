#ifndef CCriticalsModule_HPP_GUARD
#define CCriticalsModule_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CCriticalsModule : CModule {
	CCriticalsModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
};
static const char* crits_modes[] = { "Mini-Jump", "Jump" };
static const char* crits_current_mode = "Mini-Jump";

#endif //CNoFallModule_HPP_GUARD
