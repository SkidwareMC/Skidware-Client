#include "CPlayerController.hpp"
#include "CCheat.hpp"

CPlayerController::CPlayerController(jobject klass) : _klass(klass) {
	this->_klass = klass;
}

CPlayerController::~CPlayerController() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}
/*
void CPlayerController::attackEntity(CPlayer* player, CPlayer* target)
{
	CIntelligentMappedClass playerClass = CIntelligentMappings::getClass("net.minecraft.client.multiplayer.PlayerControllerMP");
	CUtils::CallMethod<void>(this->_klass, playerClass.getMethod("attackEntity").name(),
		playerClass.getMethod("attackEntity").signature(), player, target);
}
*/




