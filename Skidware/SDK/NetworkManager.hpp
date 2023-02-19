#pragma once
#include "JNIHelper.hpp"

class NetworkManager
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

public:
	NetworkManager(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();
};