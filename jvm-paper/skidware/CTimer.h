#ifndef CTIMER_HPP_GUARD
#define CTIMER_HPP_GUARD
#pragma once

#include "common.h"
#include "CUtils.hpp"
#include "CUniqueReference.hpp"
#include "CCheat.hpp"

typedef struct CTimer {
	CTimer(jobject);
	~CTimer();
	jni_ptr<float> tickLength = make_jni_ptr<float>(this->_klass, "", "F");

	jni_ptr<float> timerSpeed = make_jni_ptr<float>(this->_klass, "", "F");


	jobject GetKlass() {
		return this->_klass;
	}
private:
	jobject _klass;
} CTimer;

#endif //CPLAYERCONTROLLER_HPP_GUARD
