#ifndef CTimerModule_HPP_GUARD
#define CTimerModule_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CTimerModule : CModule {
	CTimerModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
};

static int millsEachTick = 50;
#endif //CNoFallModule_HPP_GUARD
