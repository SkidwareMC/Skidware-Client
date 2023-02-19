#pragma once
#include "JNIHelper.hpp"

class ServerData
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jfieldID getPingToServerFieldID = NULL;
	jlong getPingToServerLong = NULL;

public:
	ServerData(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();
	jlong getPingToServer();
};