#ifndef CFLYMODULE_HPP_GUARD
#define CFLYMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"
static const char* fly_modes[] = { "Keep-y", "Spartan" , "JetPack"};
static const char* fly_current_mode = "Spartan";
typedef struct CFlyModule : CModule {
	CFlyModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
private:
	static inline char* displayName = "Fly";

};



#endif //CFLYMODULE_HPP_GUARD
