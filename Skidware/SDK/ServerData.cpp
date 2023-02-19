#include "ServerData.hpp"

ServerData::ServerData(jobject obj)
{
	CurrentObject = obj;
}

jobject ServerData::GetCurrentObject()
{
	return CurrentObject;
}

jclass ServerData::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

jlong ServerData::getPingToServer()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getPingToServerLong == NULL)
	{
		if (getPingToServerFieldID == NULL)
		{
			getPingToServerFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_78844_e" : "e", "J");
			if (getPingToServerFieldID == NULL) return NULL;
		}

		getPingToServerLong = JNIHelper::env->GetLongField(GetCurrentObject(), getPingToServerFieldID);
	}

	return getPingToServerLong;
}