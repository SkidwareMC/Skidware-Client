#include "CModule.hpp"

CModule::CModule(std::string name, int keyBind) {
	this->name = name;
	this->keyBind = keyBind;
}

CModule::~CModule() {

}

void CModule::onEnable() {
	
}

void CModule::onDisable() {

}

void CModule::setState(bool state) {
	if (this->state != state) {
		this->state = state;

		if (state) {
			this->onEnable();
		} else {
			this->onDisable();
		}
	}
}

void CModule::toggle() {
	this->setState(!this->state);
}