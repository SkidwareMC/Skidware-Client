#pragma once
#include "JNIHelper.hpp"
#include "NetHandlerPlayClient.hpp"
#include "EntityPlayer.hpp"

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
	jobject getPlayerCapabilites();
	void setFly(jboolean);
};