#pragma once
#ifndef CCAIMASSISTMODULE_HPP_GUARD
#define CAIMASSISTMODULE_HPP_GUARD


#include "CModule.hpp"
#include "CCheat.hpp"
#include "mathUtil.h"

typedef struct CAimAssistModule : CModule {
	CAimAssistModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
} CAimassistModule;

#endif // !CCLICKERMODULE_HPP_GUARD