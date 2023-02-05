#ifndef CFULLBRIGHT_HPP_GUARD
#define CFULLBRIGHT_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CFullBrightModule : CModule {
	CFullBrightModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
};
#endif //CHUDMODULE_HPP_GUARD