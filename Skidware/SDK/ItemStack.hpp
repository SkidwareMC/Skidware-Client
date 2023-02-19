#pragma once
#include "JNIHelper.hpp"

class ItemStack
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jmethodID getUnlocalizedNameMethodID = NULL;
	jobject getUnlocalizedNameObject = NULL;
	jstring getUnlocalizedNameString = NULL;

	jmethodID getDisplayNameMethodID = NULL;
	jobject getDisplayNameObject = NULL;
	jstring getDisplayNameString = NULL;

public:
	ItemStack(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	jstring getUnlocalizedName();
	jstring getDisplayName();
};