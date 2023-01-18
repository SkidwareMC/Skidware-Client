#ifndef CSpeedModule_HPP_GUARD
#define CSpeedModule_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CSpeedModule : CModule {
	CSpeedModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
};

#endif //CSpeedModule_HPP_GUARD
