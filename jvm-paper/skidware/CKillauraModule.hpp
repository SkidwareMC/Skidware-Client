#ifndef CKILLAURAMODULE_HPP_GUARD
#define CKILLAURAMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CKillauraModule : CModule {
	CKillauraModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();

	// void click();

} CNoFallModule;

namespace cps {
	static float cps = 10;
}
#endif //CKILLAURAMODULE_HPP_GUARD
