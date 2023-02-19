#pragma once
#include "JNIHelper.hpp"

class ActiveRenderInfo
{
private:
	jclass CurrentClass = NULL;

public:
	ActiveRenderInfo(jclass obj);
	jclass GetCurrentClass();
};