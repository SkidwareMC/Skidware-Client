#include "Session.hpp"
#include "../Wrapper/Logger.hpp"

Session::Session(jobject obj)
{
	CurrentObject = obj;
}

jobject Session::GetCurrentObject()
{
	return CurrentObject;
}

jclass Session::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

jstring Session::GetPlayerID()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getPlayerIDFieldID == NULL)
	{
		if (getPlayerIDFieldID == NULL)
		{
			getPlayerIDFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_148257_b" : "b", "Ljava/lang/String;");
			if (getPlayerIDFieldID == NULL) return NULL;
		}

		if (getPlayerIDObject == NULL)
		{
			getPlayerIDObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getPlayerIDFieldID);
			if (getPlayerIDObject == NULL) return NULL;
		}

		PlayerIDString = (jstring)getPlayerIDObject;
	}

	return PlayerIDString;
}

jstring Session::GetUsername()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getUsernameFieldID == NULL)
	{
		if (getUsernameFieldID == NULL)
		{
			getUsernameFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_74286_b" : "a", "Ljava/lang/String;");
			if (getUsernameFieldID == NULL) return NULL;
		}

		if (getUsernameObject == NULL)
		{
			getUsernameObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getUsernameFieldID);
			if (getUsernameObject == NULL) return NULL;
		}

		UsernameString = (jstring)getUsernameObject;
	}

	return UsernameString;
}

jstring Session::GetToken()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getTokenFieldID == NULL)
	{
		if (getTokenFieldID == NULL)
		{
			getTokenFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_148258_c" : "c", "Ljava/lang/String;");
			if (getTokenFieldID == NULL) return NULL;
		}

		if (getTokenObject == NULL)
		{
			getTokenObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getTokenFieldID);
			if (getTokenObject == NULL) return NULL;
		}

		TokenString = (jstring)getTokenObject;
	}

	return TokenString;
}

void Session::SetPlayerID(jstring id)
{
	if (GetCurrentClass() == NULL) return;

	if (getPlayerIDFieldID == NULL)
	{
		if (getPlayerIDFieldID == NULL)
		{
			getPlayerIDFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_148257_b" : "b", "Ljava/lang/String;");
			if (getPlayerIDFieldID == NULL) return;
		}

		JNIHelper::env->SetObjectField(GetCurrentObject(), getPlayerIDFieldID, id);
	}
}

void Session::SetUsername(jstring name)
{
	if (GetCurrentClass() == NULL) return;
	if (getUsernameFieldID == NULL)
	{
		if (getUsernameFieldID == NULL)
		{
			getUsernameFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_74286_b" : "a", "Ljava/lang/String;");
			if (getUsernameFieldID == NULL) return;
		}

		JNIHelper::env->SetObjectField(GetCurrentObject(), getUsernameFieldID, name);
	}
}

void Session::SetToken(jstring token)
{
	if (GetCurrentClass() == NULL) return;

	if (getTokenFieldID == NULL)
	{
		if (getTokenFieldID == NULL)
		{
			getTokenFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_148258_c" : "c", "Ljava/lang/String;");
			if (getTokenFieldID == NULL) return;
		}

		JNIHelper::env->SetObjectField(GetCurrentObject(), getTokenFieldID, token);
	}
}