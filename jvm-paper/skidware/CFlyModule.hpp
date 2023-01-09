#ifndef CFLYMODULE_HPP_GUARD
#define CFLYMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CFlyModule : CModule {
	CFlyModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
};

#endif //CFLYMODULE_HPP_GUARD
