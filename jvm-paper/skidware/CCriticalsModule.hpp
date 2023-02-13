#ifndef CCriticalsModule_HPP_GUARD
#define CCriticalsModule_HPP_GUARD
#pragma once

#include "CModule.hpp"
static const char* crits_modes[] = { "Mini-Jump", "Jump", "NoGround"};
static const char* crits_current_mode = "Mini-Jump";
typedef struct CCriticalsModule : CModule {
	CCriticalsModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
private:
	static inline char* displayName = (char*)crits_current_mode;
};



#endif //CNoFallModule_HPP_GUARD
