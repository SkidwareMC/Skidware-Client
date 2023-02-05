#pragma once
#ifndef CANTIKBMODULE_HPP_GUARD
#define CANTIKBMODULE_HPP_GUARD


#include "CModule.hpp"
#include "CCheat.hpp"
#include "mathUtil.h"
#include "wrapper.h"
static const char* velo_modes[] = { "Motion", "Jump" };
static const char* velo_current_mode = "Jump";
typedef struct CAntiKBModule : CModule {
	CAntiKBModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
private:
	static inline char* displayName = (char*)velo_current_mode;
} CAntiKBModule;




#endif // !ANTIKBMODULE_CGUARD