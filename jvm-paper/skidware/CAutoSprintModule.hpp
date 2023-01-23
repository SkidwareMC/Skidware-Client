#ifndef CAutoSprintMODULE_HPP_GUARD
#define CAutoSprintMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"
#include "CCheat.hpp"

typedef struct CAutoSprintModule : CModule {
	CAutoSprintModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
} CAutoSprintModule;

#endif //CAIRJUMPMODULE_HPP_GUARD