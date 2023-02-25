#pragma once
#include <Windows.h>
#include <iostream>
#include "JNIHelper.hpp"
#include <vector>
#include "EntityPlayer.hpp"
#include <string>

class World
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jfieldID getPlayerListFieldID = NULL;
	jobject getPlayerListObject = NULL;
	jint getPlayerListSizeInt = NULL;
	jobjectArray getplayerListObjectArray = NULL;

	jfieldID getEntityListFieldID = NULL;
	jobject getEntityListObject = NULL;
	jint getEntityListSizeInt = NULL;
	jobjectArray getEntityListObjectArray = NULL;

public:
	World(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	std::vector<EntityPlayer> getPlayerList();
	std::vector<Entity> getEntityList();
	bool isBlockAir(double x, double y, double z);

};