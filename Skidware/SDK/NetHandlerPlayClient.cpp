#include "NetHandlerPlayClient.hpp"

NetHandlerPlayClient::NetHandlerPlayClient(jobject obj)
{
	CurrentObject = obj;
}

jobject NetHandlerPlayClient::GetCurrentObject()
{
	return CurrentObject;
}

jclass NetHandlerPlayClient::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}