#pragma once
#ifndef CCVELOCITYMODULE_HPP_GUARD
#define CAIVELOCITYMODULE_HPP_GUARD


#include "CModule.hpp"
#include "CCheat.hpp"
#include "mathUtil.h"

typedef struct CVelocityModule : CModule {
	CVelocityModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
	double horizontal = 0;
	double vertical = 0;
} CVelocityModule;

#endif // !CCLICKERMODULE_HPP_GUARD