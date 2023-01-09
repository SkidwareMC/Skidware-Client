#ifndef CSTRAFEMODULE_HPP_GUARD
#define CSTRAFEMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CStrafeModule : CModule {
	CStrafeModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
};

#endif //CSTRAFEMODULE_HPP_GUARD
