#ifndef CCLICKERMODULE_HPP_GUARD
#define CCLICKERMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"
#include "CCheat.hpp"

typedef struct CClickerModule : CModule {
	CClickerModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
} CClickerModule;

float m_delay = {};
float m_random = {};
float f_cps = 15;
#endif // !CCLICKERMODULE_HPP_GUARD