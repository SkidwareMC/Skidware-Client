#ifndef CPLAYER_HPP_GUARD
#define CPLAYER_HPP_GUARD
#pragma once

#include "common.h"
#include "CIntelligentMappings.hpp"
#include "CUniqueReference.hpp"
#include "CMovementInput.hpp"
#include "CWorld.hpp"

typedef struct CIntelligentMappings CIntelligentMappings;
typedef struct CMovementInput CMovementInput;
typedef struct CWorld CWorld;

typedef struct CPlayer {
	CPlayer(jobject);
	~CPlayer();
	jni_ptr<bool> onGround = make_jni_ptr<bool>(this->_klass, "", "Z");

	jni_ptr<float> moveForward = make_jni_ptr<float>(this->_klass, "", "F");
	jni_ptr<float> moveStrafing = make_jni_ptr<float>(this->_klass, "", "F");

	jni_ptr<double> motionX = make_jni_ptr<double>(this->_klass, "", "D");
	jni_ptr<double> motionY = make_jni_ptr<double>(this->_klass, "", "D");
	jni_ptr<double> motionZ = make_jni_ptr<double>(this->_klass, "", "D");	
	
	jni_ptr<float> rotationYaw = make_jni_ptr<float>(this->_klass, "", "F");
	jni_ptr<float> headRotationYaw = make_jni_ptr<float>(this->_klass, "", "F");

	jni_ptr<int> hurtTime = make_jni_ptr<int>(this->_klass, "", "I");

	jni_ptr<float> speedInAir = make_jni_ptr<float>(this->_klass, "", "F");
	jni_ptr<bool> inWater = make_jni_ptr<bool>(this->_klass, "", "Z");
	jni_ptr<float> fallDistance = make_jni_ptr<float>(this->_klass, "", "F");
	jni_ptr<float> rotationPitch = make_jni_ptr<float>(this->_klass, "", "F");

	jni_ptr<double> posX = make_jni_ptr<double>(this->_klass, "", "D");
	jni_ptr<double> posY = make_jni_ptr<double>(this->_klass, "", "D");
	jni_ptr<double> posZ = make_jni_ptr<double>(this->_klass, "", "D");

	CMovementInput* movementInput = nullptr;
	CWorld* theWorld = nullptr;

	double getDirection();
	void strafe(float);
	bool IsHurt();
	bool isCollidedHorizontally();
	bool isStrafing();
	bool isMovingForwardOrBackwards();
	float getSpeed();
	void jump();
	void setSprint(jboolean state);
	jobject GetKlass() {
		return this->_klass;
	}
private: 
	jobject _klass;
} CPlayer;

#endif //CPLAYER_HPP_GUARD
