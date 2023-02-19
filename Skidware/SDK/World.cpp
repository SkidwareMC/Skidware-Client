#include "World.hpp"
#include "Utils/JavaUtil.hpp"
#include "../Wrapper/Logger.hpp"

World::World(jobject obj)
{
	CurrentObject = obj;
}

jobject World::GetCurrentObject()
{
	return CurrentObject;
}

jclass World::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

std::vector<EntityPlayer> World::getPlayerList()
{
	std::vector<EntityPlayer> cachedPlayers;

	if (GetCurrentClass() == NULL) return cachedPlayers;

	if (getPlayerListFieldID == NULL)
	{
		getPlayerListFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_73010_i" : "j", "Ljava/util/List;");
		if (getPlayerListFieldID == NULL) return cachedPlayers;
	}

	if (getPlayerListObject == NULL)
	{
		getPlayerListObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getPlayerListFieldID);
		if (getPlayerListObject == NULL) return cachedPlayers;
	}

	if (getPlayerListSizeInt == NULL)
	{
		getPlayerListSizeInt = JavaUtil::GetArraySize(getPlayerListObject);
		if (getPlayerListSizeInt == NULL) return cachedPlayers;
	}

	if (getplayerListObjectArray == NULL)
	{
		getplayerListObjectArray = JavaUtil::GetArray(getPlayerListObject);
		if (getplayerListObjectArray == NULL) return cachedPlayers;
	}

	for (int idx = 0; idx < getPlayerListSizeInt; idx++)
	{
		jobject entity = JNIHelper::env->GetObjectArrayElement(getplayerListObjectArray, idx);
		if (entity != NULL) cachedPlayers.push_back(EntityPlayer(entity));
	}

	return cachedPlayers;
}

std::vector<Entity> World::getEntityList()
{
	std::vector<Entity> result;

	if (GetCurrentClass() == NULL) return result;

	if (getEntityListFieldID == NULL)
	{
		getEntityListFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_72996_f" : "f", "Ljava/util/List;");
		if (getEntityListFieldID == NULL) return result;
	}

	if (getEntityListObject == NULL)
	{
		getEntityListObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getEntityListFieldID);
		if (getEntityListObject == NULL) return result;
	}

	if (getEntityListSizeInt == NULL)
	{
		getEntityListSizeInt = JavaUtil::GetArraySize(getEntityListObject);
		if (getEntityListSizeInt == NULL) return result;
	}

	if (getEntityListObjectArray == NULL)
	{
		getEntityListObjectArray = JavaUtil::GetArray(getEntityListObject);
		if (getEntityListObjectArray == NULL) return result;
	}

	for (int idx = 0; idx < getEntityListSizeInt; idx++)
	{
		jobject entity = JNIHelper::env->GetObjectArrayElement(getEntityListObjectArray, idx);
		if (entity != NULL) result.push_back(Entity(entity));
	}

	return result;
}