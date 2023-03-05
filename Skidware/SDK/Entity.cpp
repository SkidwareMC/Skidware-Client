#include "Utils/JavaUtil.hpp"
#include "Entity.hpp"
#include "../Wrapper/Logger.hpp"

Entity::Entity(jobject obj)
{
	CurrentObject = obj;
}

jobject Entity::GetCurrentObject()
{
	return CurrentObject;
}

jclass Entity::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

jstring Entity::GetDisplayName()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getDisplayNameString == NULL)
	{
		if (getDisplayNameMethodID == NULL)
		{
			getDisplayNameMethodID = JNIHelper::env->GetMethodID(GetCurrentClass(), JNIHelper::IsForge() ? "func_70005_c_" : "e_", "()Ljava/lang/String;");
			if (getDisplayNameMethodID == NULL) return NULL;
		}

		if (getDisplayNameObject == NULL)
		{
			getDisplayNameObject = JNIHelper::env->CallObjectMethod(GetCurrentObject(), getDisplayNameMethodID);
			if (getDisplayNameObject == NULL) return NULL;
		}

		getDisplayNameString = (jstring)getDisplayNameObject;
	}

	return getDisplayNameString;
}

void Entity::SetDisplayNameTag(jstring Name)
{
	if (GetCurrentClass() == NULL) return;

	if (setDisplayNameTagMethodID == NULL)
	{
		setDisplayNameTagMethodID = JNIHelper::env->GetMethodID(GetCurrentClass(), JNIHelper::IsForge() ? "func_96094_a" : "a", "(Ljava/lang/String;)V");
		if (setDisplayNameTagMethodID == NULL) return;
	}

	JNIHelper::env->CallVoidMethod(GetCurrentObject(), setDisplayNameTagMethodID, Name);
}

jboolean Entity::GetImmuneToFire()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (immuneToFireBool == NULL)
	{
		if (immuneToFireFieldID == NULL)
		{
			immuneToFireFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70178_ae" : "ab", "Z");
			if (immuneToFireFieldID == NULL) return NULL;
		}

		immuneToFireBool = JNIHelper::env->GetIntField(GetCurrentObject(), immuneToFireFieldID);
	}

	return immuneToFireBool;
}

void Entity::SetImmuneToFire(jboolean state)
{
	if (GetCurrentClass() == NULL) return;

	if (immuneToFireFieldID == NULL)
	{
		immuneToFireFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70178_ae" : "ab", "Z");
		if (immuneToFireFieldID == NULL) return;
	}

	JNIHelper::env->SetBooleanField(GetCurrentObject(), immuneToFireFieldID, state);
}

jdouble Entity::GetPositionX()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (PosXDouble == NULL)
	{
		if (PosXFieldID == NULL)
		{
			PosXFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70165_t" : "s", "D");
			if (PosXFieldID == NULL) return NULL;
		}

		PosXDouble = JNIHelper::env->GetDoubleField(GetCurrentObject(), PosXFieldID);
	}

	return PosXDouble;
}

jdouble Entity::GetPositionY()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (PosYDouble == NULL)
	{
		if (PosYFieldID == NULL)
		{
			PosYFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70163_u" : "t", "D");
			if (PosYFieldID == NULL) return NULL;
		}

		PosYDouble = JNIHelper::env->GetDoubleField(GetCurrentObject(), PosYFieldID);
	}

	return PosYDouble;
}

jdouble Entity::GetPositionZ()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (PosZDouble == NULL)
	{
		if (PosZFieldID == NULL)
		{
			PosZFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70161_v" : "u", "D");
			if (PosZFieldID == NULL) return NULL;
		}

		PosZDouble = JNIHelper::env->GetDoubleField(GetCurrentObject(), PosZFieldID);
	}

	return PosZDouble;
}

void Entity::SetBoundingBoxWidth(jfloat width)
{
	if (GetCurrentClass() == NULL) return;

	if (BoundingBoxWidthFieldID == NULL)
	{
		BoundingBoxWidthFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70130_N" : "J", "F");
		if (BoundingBoxWidthFieldID == NULL) return;
	}

	JNIHelper::env->SetFloatField(GetCurrentObject(), BoundingBoxWidthFieldID, width);
}

void Entity::SetBoundingBoxHeight(jfloat width)
{
	if (GetCurrentClass() == NULL) return;
	 
	if (BoundingBoxHeightFieldID == NULL)
	{
		BoundingBoxHeightFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70131_O" : "K", "F");
		if (BoundingBoxHeightFieldID == NULL) return;
	}

	JNIHelper::env->SetFloatField(GetCurrentObject(), BoundingBoxHeightFieldID, width);
}

jint Entity::GetEntityID()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (EntityIdInt == NULL)
	{
		if (getEntityIdFieldID == NULL)
		{
			JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_145783_c" : "c", "I");
			if (getEntityIdFieldID == NULL) return NULL;
		}

		EntityIdInt = JNIHelper::env->GetIntField(GetCurrentObject(), getEntityIdFieldID);
	}

	return EntityIdInt;
}

int Entity::ticksExisted()
{
	jfieldID ticksExistedfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70173_aa" : "W", "I");
	return JNIHelper::env->GetIntField(GetCurrentObject(), ticksExistedfd);
}
