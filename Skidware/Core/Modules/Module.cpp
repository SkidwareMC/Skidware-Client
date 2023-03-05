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


void Module::onEnable()
{
}

void Module::onDisable()
{
}

void Module::toggle()
{
	this->enabled = !this->enabled;
	if (this->enabled) {
		this->onEnable();
	}
	else {
		this->onDisable();
	}
}


const char* Module::getName()
{
	return this->name;

}

const char* Module::getDescription()
{
	return this->description;
}

void Module::renderSetts()
{
}


