#pragma once
#ifndef CANTIKBMODULE_HPP_GUARD
#define CANTIKBMODULE_HPP_GUARD


#include "CModule.hpp"
#include "CCheat.hpp"
#include "mathUtil.h"
#include "wrapper.h"

typedef struct CAntiKBModule : CModule {
	CAntiKBModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
} CAntiKBModule;

#endif // !ANTIKBMODULE_CGUARD