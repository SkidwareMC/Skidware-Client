#pragma once
#include "JNIHelper.hpp"

class InventoryPlayer
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

public:
	InventoryPlayer(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();
};