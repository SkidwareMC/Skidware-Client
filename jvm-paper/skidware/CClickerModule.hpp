#pragma once
#ifndef CAIRJUMPMODULE_HPP_GUARD
#define CAIRJUMPMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"
#include "CCheat.hpp"

typedef struct CClickerModule : CModule {
	CClickerModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
} CAirJumpModule;

float m_delay = {};
float m_random = {};
float f_cps = {};

#endif //CAIRJUMPMODULE_HPP_GUARD