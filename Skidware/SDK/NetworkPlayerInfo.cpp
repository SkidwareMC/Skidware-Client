#include "NetworkPlayerInfo.hpp"
#include "../Wrapper/Logger.hpp"

NetworkPlayerInfo::NetworkPlayerInfo(jobject obj)
{
	CurrentObject = obj;
}

jobject NetworkPlayerInfo::GetCurrentObject()
{
	return CurrentObject;
}

jclass NetworkPlayerInfo::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

jint NetworkPlayerInfo::GetPing()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getPingInt == NULL)
	{
		if (getPingFieldID == NULL)
		{
			getPingFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_78829_b" : "c", "I");
			if (getPingFieldID == NULL) return NULL;
		}

		getPingInt = JNIHelper::env->GetIntField(GetCurrentObject(), getPingFieldID);
	}
	
	return getPingInt;
}

void NetworkPlayerInfo::SetPing(jint latency)
{
	if (GetCurrentClass() == NULL) return;

	if (getPingFieldID == NULL)
	{
		getPingFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_78829_b" : "c", "I");
		if (getPingFieldID == NULL) return;
	}

	JNIHelper::env->SetIntField(GetCurrentObject(), getPingFieldID, latency);
}