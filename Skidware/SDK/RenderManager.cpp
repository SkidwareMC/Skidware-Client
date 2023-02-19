#include "RenderManager.hpp"
#include "../Wrapper/Logger.hpp"

RenderManager::RenderManager(jobject obj)
{
	CurrentObject = obj;
}

jobject RenderManager::GetCurrentObject()
{
	return CurrentObject;
}

jclass RenderManager::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}