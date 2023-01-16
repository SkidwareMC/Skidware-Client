#ifndef CSPIDERMODULE_HPP_GUARD
#define CSPIDERMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CSpiderModule : CModule {
	CSpiderModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
};

#endif //CFLYMODULE_HPP_GUARD
