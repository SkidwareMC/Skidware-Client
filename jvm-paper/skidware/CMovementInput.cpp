#include "CMovementInput.hpp"
#include "CCheat.hpp"
#include "CUniqueReference.hpp"

CMovementInput::CMovementInput(jobject klass) : _klass(klass), moveForward(klass,
	CIntelligentMappings::getClass("net.minecraft.util.MovementInput").getField("moveForward").name(), "F"), moveStrafe(klass,
		CIntelligentMappings::getClass("net.minecraft.util.MovementInput").getField("moveStrafe").name(), "F") {
	this->_klass = klass;
}

CMovementInput::~CMovementInput() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}