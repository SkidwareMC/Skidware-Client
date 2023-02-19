#pragma once
#include "JNIHelper.hpp"

class Session
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jfieldID getPlayerIDFieldID = NULL;
	jobject getPlayerIDObject = NULL;
	jstring PlayerIDString = NULL;

	jfieldID getUsernameFieldID = NULL;
	jobject getUsernameObject = NULL;
	jstring UsernameString = NULL;

	jfieldID getTokenFieldID = NULL;
	jobject getTokenObject = NULL;
	jstring TokenString = NULL;
public:
	Session(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	jstring GetPlayerID();
	jstring GetUsername();
	jstring GetToken();
	void SetPlayerID(jstring);
	void SetUsername(jstring);
	void SetToken(jstring);
};