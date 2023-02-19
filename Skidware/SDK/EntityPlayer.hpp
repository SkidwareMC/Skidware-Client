#pragma once
#include "EntityLivingBase.hpp"
#include "NetworkPlayerInfo.hpp"
#include "InventoryPlayer.hpp"
#include "ItemStack.hpp"

class EntityPlayer : public EntityLivingBase
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jmethodID getNetworkPlayerInfoMethodID = NULL;
	jobject getNetworkPlayerInfoObject = NULL;
	NetworkPlayerInfo NetworkPlayerInfoInstance = NULL;

	jfieldID getInventoryPlayerFieldID = NULL;
	jobject getInventoryPlayerObject = NULL;
	InventoryPlayer InventoryPlayerInstance = NULL;

	jmethodID getCurrentEquipedItemMethodID = NULL;
	jobject getCurrentEquipedItemObject = NULL;
	ItemStack CurrentEquipedItemInstance = NULL;

public:
	EntityPlayer(jobject obj);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	NetworkPlayerInfo getNetworkPlayerInfo();
	InventoryPlayer getInventoryPlayer();
	ItemStack getCurrentEquipedItem();
};