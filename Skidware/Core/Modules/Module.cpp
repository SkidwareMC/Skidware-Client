#include "Module.hpp"

Module::Module(const char* name, const int bind, const char* description)
{
	this->enabled = false;
	this->name = name;
	this->description = description;
}

void Module::OnTick()
{
}

void Module::OnUpdate()
{
}

void Module::OnRender()
{
}

const char* Module::getName()
{
	return this->name;

}

const char* Module::getDescription()
{
	return this->description;
}


