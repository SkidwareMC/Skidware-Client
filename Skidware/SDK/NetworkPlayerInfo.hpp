#pragma once
#include "JNIHelper.hpp"

class NetworkPlayerInfo
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jfieldID getPingFieldID = NULL;
	jint getPingInt = NULL;

public:
	NetworkPlayerInfo(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	jint GetPing();
	void SetPing(jint);
};