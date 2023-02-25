#pragma once
#include "JNIHelper.hpp"
#include "NetHandlerPlayClient.hpp"
#include "EntityPlayer.hpp"
#include "../Wrapper/Utils.hpp"
class LocalPlayer : public EntityPlayer
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jfieldID getNetHandlerPlayClientFieldID = NULL;
	jfieldID motionXfd = NULL;
	jfieldID motionYfd = NULL;
	jfieldID motionZfd = NULL;
	jfieldID playerCapablitiesfd = NULL;
	jfieldID hurttimefd = NULL;
	jfieldID ongroundfd = NULL;
	jfieldID speedinairfd = NULL;

	jobject getNetHandlerPlayClientObject = NULL;
	NetHandlerPlayClient NetHandlerPlayClientInstance = NULL;

	jmethodID setSprintingMethodID = NULL;
	jmethodID swingItemMethodID = NULL;


public:
	LocalPlayer(jobject);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	NetHandlerPlayClient getNetHandlerPlayClient();
	void setSprinting(jboolean);
	void swingItem();
	void SetVelocity(double motionx, double motiony, double motionz);
	vector3 GetVelocity();
	jobject getPlayerCapabilites();
	void setFly(jboolean);
	bool isHurt(int ticks);
	void setOnGround(jboolean onGround);
	bool getOnGround();
	bool isSneaking();
	void setSneak(bool state);
};