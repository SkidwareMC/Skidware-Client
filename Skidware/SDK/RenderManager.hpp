#pragma once
#include "JNIHelper.hpp"

class RenderManager
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

public:
	RenderManager(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();
};