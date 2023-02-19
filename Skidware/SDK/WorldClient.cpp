#include "WorldClient.hpp"
#include "Utils/JavaUtil.hpp"

WorldClient::WorldClient(jobject obj) : World(obj)
{
	CurrentObject = obj;
}

jobject WorldClient::GetCurrentObject()
{
	return CurrentObject;
}

jclass WorldClient::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

void WorldClient::RemoveEntity(Entity entity)
{
	if (GetCurrentClass() == NULL) return;

	if (removeEntityMethodID == NULL)
	{
		removeEntityMethodID = JNIHelper::IsForge() ? JNIHelper::env->GetMethodID(GetCurrentClass(), "func_72900_e", "(Lnet/minecraft/entity/Entity;)V") : JNIHelper::env->GetMethodID(GetCurrentClass(), "e", "(Lpk;)V");
		if (removeEntityMethodID == NULL) return;
	}

	JNIHelper::env->CallVoidMethod(GetCurrentObject(), removeEntityMethodID, entity.GetCurrentObject());
}