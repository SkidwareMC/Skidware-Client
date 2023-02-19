#include "InventoryPlayer.hpp"

InventoryPlayer::InventoryPlayer(jobject obj)
{
	CurrentObject = obj;
}

jobject InventoryPlayer::GetCurrentObject()
{
	return CurrentObject;
}

jclass InventoryPlayer::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}