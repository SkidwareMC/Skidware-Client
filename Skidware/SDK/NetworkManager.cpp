#include "NetworkManager.hpp"

NetworkManager::NetworkManager(jobject obj)
{
	CurrentObject = obj;
}

jobject NetworkManager::GetCurrentObject()
{
	return CurrentObject;
}

jclass NetworkManager::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}