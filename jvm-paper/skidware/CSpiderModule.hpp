#ifndef CSPIDERMODULE_HPP_GUARD
#define CSPIDERMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"
#include "CCheat.hpp"

typedef struct CSpiderModule : CModule {
	CSpiderModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
};

#endif //CSPIDERMODULE_HPP_GUARD
