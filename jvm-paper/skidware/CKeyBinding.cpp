#include "CKeyBinding.hpp"
#include "CCheat.hpp"
#include "CIntelligentMappings.hpp"

CKeyBinding::CKeyBinding(jobject klass) : _klass(klass), pressed(klass,
	CIntelligentMappings::getClass("net.minecraft.client.settings.KeyBinding").getField("pressed").name(), "Z"), keyCode(klass,
		CIntelligentMappings::getClass("net.minecraft.client.settings.KeyBinding").getField("keyCode").name(), "I") {
	this->_klass = klass;
}

CKeyBinding::~CKeyBinding() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}

bool CKeyBinding::isKeyDown() {
	CIntelligentMappedClass klass = CIntelligentMappings::getClass("net.minecraft.client.settings.KeyBinding");
	CIntelligentMappedMethod isKeyDownMethod = klass.getMethod("isKeyDown");

	return CUtils::CallMethod<bool>(this->_klass, isKeyDownMethod.name(), "()Z");
}