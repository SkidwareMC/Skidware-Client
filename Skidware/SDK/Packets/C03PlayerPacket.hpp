#pragma once
#include "../JNIHelper.hpp"

class C03PlayerPacket
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

public:
	C03PlayerPacket(bool onGround);
	jobject GetCurrentObject();
	jclass GetCurrentClass();
};