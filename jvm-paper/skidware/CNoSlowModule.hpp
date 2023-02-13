#pragma once
#ifndef CNOSLOWMODULE_HPP_GUARD
#define CNOSLOWMODULE_HPP_GUARD


#include "CModule.hpp"
#include "CCheat.hpp"
#include "mathUtil.h"
#include "wrapper.h"

static const char* noslow_modes[] = { "Sprint", "Move", "Motion"};
static const char* noslow_current_mode = "Sprint";
typedef struct CNoSlowModule : CModule {
	CNoSlowModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
} CNoSlowModule;

#endif // !ANTIKBMODULE_CGUARD