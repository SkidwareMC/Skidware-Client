#ifndef CPLAYERCONTROLLER_HPP_GUARD
#define CPLAYERCONTROLLER_HPP_GUARD
#pragma once

#include "common.h"
#include "CPlayer.hpp"

typedef struct CPlayerController {
	CPlayerController(jobject);
	~CPlayerController();

	void attackEntity(CPlayer* player, CPlayer* target);

	jobject GetKlass() {
		return this->_klass;
	}
private:
	jobject _klass;
} CPlayerController;

#endif //CPLAYERCONTROLLER_HPP_GUARD
