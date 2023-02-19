#include "EntityLivingBase.hpp"
#include "../Wrapper/Logger.hpp"

EntityLivingBase::EntityLivingBase(jobject obj) : Entity(obj)
{
	CurrentObject = obj;
}

jobject EntityLivingBase::GetCurrentObject()
{
	return CurrentObject;
}

jclass EntityLivingBase::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

jfloat EntityLivingBase::GetHealth()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getHealtFloat == NULL)
	{
		if (getHealthMethodID == NULL)
		{
			getHealthMethodID = JNIHelper::env->GetMethodID(GetCurrentClass(), JNIHelper::IsForge() ? "func_110143_aJ" : "bn", "()F");
			if (getHealthMethodID == NULL) return NULL;
		}

		getHealtFloat = JNIHelper::env->CallFloatMethod(GetCurrentObject(), getHealthMethodID);
	}

	return getHealtFloat;
}