#include "EntityPlayer.hpp"

EntityPlayer::EntityPlayer(jobject obj) : EntityLivingBase(obj)
{
	CurrentObject = obj;
}

jobject EntityPlayer::GetCurrentObject()
{
	return CurrentObject;
}

jclass EntityPlayer::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

NetworkPlayerInfo EntityPlayer::getNetworkPlayerInfo() // AbstractClientPlayer
{
	if (GetCurrentClass() == NULL) return NULL;

	if (NetworkPlayerInfoInstance.GetCurrentClass() == NULL)
	{
		if (getNetworkPlayerInfoMethodID == NULL)
		{
			getNetworkPlayerInfoMethodID = JNIHelper::IsForge() ? JNIHelper::env->GetMethodID(GetCurrentClass(), "func_175155_b", "()Lnet/minecraft/client/network/NetworkPlayerInfo;") : JNIHelper::env->GetMethodID(GetCurrentClass(), "b", "()Lbdc;");
			if (getNetworkPlayerInfoMethodID == NULL) return NULL;
		}

		if (getNetworkPlayerInfoObject == NULL)
		{
			getNetworkPlayerInfoObject = JNIHelper::env->CallObjectMethod(GetCurrentObject(), getNetworkPlayerInfoMethodID);
			if (getNetworkPlayerInfoObject == NULL) return NULL;
		}
		
		NetworkPlayerInfoInstance = NetworkPlayerInfo(getNetworkPlayerInfoObject);
	}

	return NetworkPlayerInfoInstance;
}

InventoryPlayer EntityPlayer::getInventoryPlayer()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (InventoryPlayerInstance.GetCurrentClass() == NULL)
	{
		if (getInventoryPlayerFieldID == NULL)
		{
			getInventoryPlayerFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_71071_by", "Lnet/minecraft/entity/player/InventoryPlayer;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "bi", "Lwm;");
			if (getInventoryPlayerFieldID == NULL) return NULL;
		}

		if (getInventoryPlayerObject == NULL)
		{
			getInventoryPlayerObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getInventoryPlayerFieldID);
			if (getInventoryPlayerObject == NULL) return NULL;
		}

		InventoryPlayerInstance = InventoryPlayer(getInventoryPlayerObject);
	}

	return InventoryPlayerInstance;
}

ItemStack EntityPlayer::getCurrentEquipedItem()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (CurrentEquipedItemInstance.GetCurrentClass() == NULL)
	{
		if (getCurrentEquipedItemMethodID == NULL)
		{
			getCurrentEquipedItemMethodID = JNIHelper::IsForge() ? JNIHelper::env->GetMethodID(GetCurrentClass(), "func_71045_bC", "()Lnet/minecraft/item/ItemStack;") : JNIHelper::env->GetMethodID(GetCurrentClass(), "bZ", "()Lzx;");
			if (getCurrentEquipedItemMethodID == NULL) return NULL;
		}

		if (getCurrentEquipedItemObject == NULL)
		{
			getCurrentEquipedItemObject = JNIHelper::env->CallObjectMethod(GetCurrentObject(), getCurrentEquipedItemMethodID);
			if (getCurrentEquipedItemObject == NULL) return NULL;
		}

		CurrentEquipedItemInstance = ItemStack(getCurrentEquipedItemObject);
	}

	return CurrentEquipedItemInstance;
}