#ifndef CAIRJUMPMODULE_HPP_GUARD
#define CAIRJUMPMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"
#include "CCheat.hpp"

typedef struct CAirJumpModule : CModule {
	CAirJumpModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
} CAirJumpModule;

#endif //CAIRJUMPMODULE_HPP_GUARD