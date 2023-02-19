#pragma once
#include "Entity.hpp"

class EntityLivingBase : public Entity
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jmethodID getHealthMethodID = NULL;
	jfloat getHealtFloat = NULL;

public:
	EntityLivingBase(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	float GetHealth();
};