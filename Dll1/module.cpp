#include "module.h"
#include "player.h"
#include "world.h"
#include <iostream>

modules::c_modules::~c_modules()
{
	mods.clear();
	mods_reset.clear();
}

void modules::c_modules::create(std::function<void(std::shared_ptr<c_context>)> m)
{
	mods.push_back(m);
}

void modules::c_modules::invoke(std::shared_ptr<c_context> ctx)
{
	for (auto m : mods)
	{
		m(ctx);
	}
}

void modules::c_modules::create_reset(std::function<void(std::shared_ptr<c_context>)> m)
{
	mods_reset.push_back(m);
}

void modules::c_modules::reset(std::shared_ptr<c_context> ctx)
{
	for (auto m : mods_reset)
	{
		m(ctx);
	}
}
