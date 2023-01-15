#include "CPlayerController.hpp"
#include "CCheat.hpp"

CPlayerController::CPlayerController(jobject klass) : _klass(klass) {
	this->_klass = klass;
}

CPlayerController::~CPlayerController() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}

