#ifndef CHUDMODULE_HPP_GUARD
#define CHUDMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CHUDModule : CModule {
	CHUDModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
};

#endif //CHUDMODULE_HPP_GUARD