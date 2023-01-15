#ifndef CWORLD_HPP_GUARD
#define CWORLD_HPP_GUARD
#pragma once

#include "common.h"

typedef struct CPlayer CPlayer;

typedef struct CWorld {
	CWorld(jobject);
	~CWorld();

	std::vector<CPlayer*> getPlayers();

	jobject GetKlass() {
		return this->_klass;
	}
private:
	jobject _klass;
} CWorld;

#endif //CWORLD_HPP_GUARD
