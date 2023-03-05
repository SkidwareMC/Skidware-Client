#pragma once
#include "JNIHelper.hpp"

class Entity
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jmethodID getDisplayNameMethodID = NULL;
	jobject getDisplayNameObject = NULL;
	jstring getDisplayNameString = NULL;

	jmethodID setDisplayNameTagMethodID = NULL;

	jfieldID immuneToFireFieldID = NULL;
	jboolean immuneToFireBool = NULL;

	jfieldID PosXFieldID = NULL;
	jfieldID PosYFieldID = NULL;
	jfieldID PosZFieldID = NULL;
	jdouble PosXDouble = NULL;
	jdouble PosYDouble = NULL;
	jdouble PosZDouble = NULL;

	jfieldID BoundingBoxWidthFieldID = NULL;
	jfieldID BoundingBoxHeightFieldID = NULL;

	jfieldID getEntityIdFieldID = NULL;
	jint EntityIdInt = NULL;

public:
	Entity(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	jstring GetDisplayName();
	void SetDisplayNameTag(jstring);
	jboolean GetImmuneToFire();
	void SetImmuneToFire(jboolean);
	jdouble GetPositionX();
	jdouble GetPositionY();
	jdouble GetPositionZ();
	void SetBoundingBoxWidth(jfloat);
	void SetBoundingBoxHeight(jfloat);
	jint GetEntityID();
	int ticksExisted();
};