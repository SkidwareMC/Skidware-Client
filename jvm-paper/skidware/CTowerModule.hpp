#ifndef CTower_HPP_GUARD
#define CTower_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CTowerModule : CModule {
	CTowerModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
} CTowerModule;
static float speed = 0.4;



#endif //CNoFallModule_HPP_GUARD
