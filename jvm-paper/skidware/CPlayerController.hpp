#ifndef CPLAYERCONTROLLER_HPP_GUARD
#define CPLAYERCONTROLLER_HPP_GUARD
#pragma once

#include "common.h"

typedef struct CPlayerController {
	CPlayerController(jobject);
	~CPlayerController();

	jobject GetKlass() {
		return this->_klass;
	}
private:
	jobject _klass;
} CPlayerController;

#endif //CPLAYERCONTROLLER_HPP_GUARD
