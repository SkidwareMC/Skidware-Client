#ifndef CMODULE_HPP_GUARD
#define CMODULE_HPP_GUARD
#pragma once

#include "common.h"
#include "CSimpleEventSystem.hpp"

enum CATAGORY {
	MOVEMENT, COMBAT, RENDER, UTIL, MISC
};

typedef struct CModule : CEventListener {
	std::string name = "Module";
	bool state = false;
	int keyBind = 0x0;
	CATAGORY catagory;

protected:
	CModule(std::string name, int keyBind, CATAGORY catagory);
public:

	virtual ~CModule();
	virtual void setState(bool);
	virtual void toggle();
	virtual void renderSettings();
	virtual void onEnable();
	virtual void onDisable();
} CModule;

#endif //CMODULE_HPP_GUARD
