#ifndef CMODULE_HPP_GUARD
#define CMODULE_HPP_GUARD
#pragma once

#include "common.h"
#include "CSimpleEventSystem.hpp"

typedef struct CModule : CEventListener {
	std::string name = "Module";
	bool state = false;
	int keyBind = 0x0;
protected:
	CModule(std::string, int);
public:
	virtual ~CModule();
	virtual void setState(bool);
	virtual void toggle();
	virtual void onEnable();
	virtual void onDisable();
} CModule;

#endif //CMODULE_HPP_GUARD
