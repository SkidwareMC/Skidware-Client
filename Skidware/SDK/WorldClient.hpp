#pragma once
#include "JNIHelper.hpp"
#include "World.hpp"

class WorldClient : public World
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jmethodID removeEntityMethodID = NULL;

public:
	WorldClient(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();
	void RemoveEntity(Entity);
};