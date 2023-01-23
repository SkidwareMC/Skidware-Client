#ifndef CFLYMODULE_HPP_GUARD
#define CFLYMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CFlyModule : CModule {
	CFlyModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
	

};

static inline const char* fly_modes[] = { "Keep-Y", "Spartan" };
static inline const char* fly_current_mode = "Spartan";

#endif //CFLYMODULE_HPP_GUARD
