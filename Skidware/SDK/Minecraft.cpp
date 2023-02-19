#include "Minecraft.hpp"

Minecraft::Minecraft(jobject obj)
{
	CurrentObject = obj;
}

jobject Minecraft::GetCurrentObject()
{
	return CurrentObject;
}

jclass Minecraft::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

LocalPlayer Minecraft::getLocalPlayer()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (LocalPlayerInstance.GetCurrentClass() == NULL)
	{
		if (getLocalPlayerFieldID == NULL)
		{
			getLocalPlayerFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_71439_g", "Lnet/minecraft/client/entity/EntityPlayerSP;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "h", "Lbew;");
			if (getLocalPlayerFieldID == NULL) return NULL;
		}

		if (getLocalPlayerObject == NULL)
		{
			getLocalPlayerObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getLocalPlayerFieldID);
			if (getLocalPlayerObject == NULL) return NULL;
		}

		LocalPlayerInstance = LocalPlayer(getLocalPlayerObject);
	}

	return LocalPlayerInstance;
}

WorldClient Minecraft::getWorld()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (WorldInstance.GetCurrentClass() == NULL)
	{
		if (getWorldFieldID == NULL)
		{
			getWorldFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_71441_e", "Lnet/minecraft/client/multiplayer/WorldClient;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "f", "Lbdb;");
			if (getWorldFieldID == NULL) return NULL;
		}
		
		if (getWorldObject == NULL)
		{
			getWorldObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getWorldFieldID);
			if (getWorldObject == NULL) return NULL;
		}

		WorldInstance = WorldClient(getWorldObject);
	}

	return WorldInstance;
}

NetworkManager Minecraft::getNetworkManager()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (NetworkManagerInstance.GetCurrentClass() == NULL)
	{
		if (getNetworkManagerFieldID == NULL)
		{
			getNetworkManagerFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_71453_ak", "Lnet/minecraft/client/network/NetworkManager;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "av", "Lek;");
			if (getNetworkManagerFieldID == NULL) return NULL;
		}

		if (getNetworkManagerObject == NULL)
		{
			getNetworkManagerObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getNetworkManagerFieldID);
			if (getNetworkManagerObject == NULL) return NULL;
		}

		NetworkManagerInstance = NetworkManager(getNetworkManagerObject);
	}

	return NetworkManagerInstance;
}

ServerData Minecraft::getServerData()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (ServerDataInstance.GetCurrentClass() == NULL)
	{
		if (getServerDataFieldID == NULL)
		{
			getServerDataFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_71422_O", "Lnet/minecraft/client/multiplayer/ServerData;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "Q", "Lbde;");
			if (getServerDataFieldID == NULL) return NULL;
		}

		if (getServerDataObject == NULL)
		{
			getServerDataObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getServerDataFieldID);
			if (getServerDataObject == NULL) return NULL;
		}

		ServerDataInstance = ServerData(getServerDataObject);
	}

	return ServerDataInstance;
}

RenderManager Minecraft::getRenderManager()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (RenderManagerInstance.GetCurrentClass() == NULL)
	{
		if (getRenderManagerFieldID == NULL)
		{
			getRenderManagerFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_175616_W", "Lnet/minecraft/client/renderer/entity/RenderManager;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "aa", "Lbiu;");
			if (getRenderManagerFieldID == NULL) return NULL;
		}

		if (getRenderManagerObject == NULL)
		{
			getRenderManagerObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getRenderManagerFieldID);
			if (getRenderManagerObject == NULL) return NULL;
		}

		RenderManagerInstance = RenderManager(getRenderManagerObject);
	}

	return RenderManagerInstance;
}

Session Minecraft::getSession()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (SessionInstance.GetCurrentClass() == NULL)
	{
		if (getSessionFieldID == NULL)
		{
			getSessionFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_71449_j", "Lnet/minecraft/util/Session;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "ae", "Lavm;");
			if (getSessionFieldID == NULL) return NULL;
		}

		if (getSessionObject == NULL)
		{
			getSessionObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getSessionFieldID);
			if (getSessionObject == NULL) return NULL;
		}

		SessionInstance = Session(getSessionObject);
	}

	return SessionInstance;
}

void Minecraft::SetLeftClickDelay(int count)
{
	if (GetCurrentClass() == NULL) return;

	if (leftClickFieldID == NULL)
	{
		leftClickFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71429_W" : "ag", "I");
		if (leftClickFieldID == NULL) return;
	}

	JNIHelper::env->SetIntField(GetCurrentObject(), leftClickFieldID, count);
}

void Minecraft::SetRightClickDelay(int count)
{
	if (GetCurrentClass() == NULL) return;

	if (rightClickFieldID == NULL)
	{
		rightClickFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71467_ac" : "ap", "I");
		if (rightClickFieldID == NULL) return;
	}

	JNIHelper::env->SetIntField(GetCurrentObject(), rightClickFieldID, count);
}

void Minecraft::LeftClick()
{
	if (GetCurrentClass() == NULL) return;

	if (leftClickMethodID == NULL)
	{
		leftClickMethodID = JNIHelper::env->GetMethodID(GetCurrentClass(), JNIHelper::IsForge() ? "func_147116_af" : "aw", "()V");
		if (leftClickMethodID == NULL) return;
	}

	JNIHelper::env->CallVoidMethod(GetCurrentObject(), leftClickMethodID);
}

void Minecraft::RightClick()
{
	if (GetCurrentClass() == NULL) return;

	if (rightClickMethodID == NULL)
	{
		rightClickMethodID = JNIHelper::env->GetMethodID(GetCurrentClass(), JNIHelper::IsForge() ? "func_147121_ag" : "ax", "()V");
		if (rightClickMethodID == NULL) return;
	}

	JNIHelper::env->CallVoidMethod(GetCurrentObject(), rightClickMethodID);
}

bool Minecraft::InGameHasFocus()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (hasIngameFocusBool == NULL)
	{
		if (gameHasFocusFieldID == NULL)
		{
			gameHasFocusFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71415_G" : "w", "Z");
			if (gameHasFocusFieldID == NULL) return NULL;
		}

		hasIngameFocusBool = JNIHelper::env->GetBooleanField(GetCurrentObject(), gameHasFocusFieldID);
	}

	return hasIngameFocusBool;
}

int Minecraft::GetFPS()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (getfpsCounterInt == NULL)
	{
		if (fpsCounterFieldID == NULL)
		{
			fpsCounterFieldID = JNIHelper::env->GetStaticFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71470_ab" : "ao", "I");
			if (fpsCounterFieldID == NULL) return NULL;
		}

		getfpsCounterInt = JNIHelper::env->GetStaticIntField(GetCurrentClass(), fpsCounterFieldID);
	}

	return getfpsCounterInt;
}

void Minecraft::SetFPS(jint FPS)
{
	if (GetCurrentClass() == NULL) return;

	if (fpsCounterFieldID == NULL)
	{
		fpsCounterFieldID = JNIHelper::env->GetStaticFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71470_ab" : "ao", "I");
		if (fpsCounterFieldID == NULL) return;
	}

	JNIHelper::env->SetStaticIntField(GetCurrentClass(), fpsCounterFieldID, FPS);
}

int Minecraft::GetDisplayHeight()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (displayHeightInt == NULL)
	{
		if (displayHeightFieldID == NULL)
		{
			displayHeightFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71440_d" : "e", "I");
			if (displayHeightFieldID == NULL) return NULL;
		}

		displayHeightInt = JNIHelper::env->GetIntField(GetCurrentClass(), displayHeightFieldID);
	}

	return displayHeightInt;
}

int Minecraft::GetDisplayWidth()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (displayWidthInt == NULL)
	{
		if (displayWidthFieldID == NULL)
		{
			displayWidthFieldID = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71443_c" : "d", "I");
			if (displayWidthFieldID == NULL) return NULL;
		}

		displayWidthInt = JNIHelper::env->GetIntField(GetCurrentClass(), displayWidthFieldID);
	}

	return displayWidthInt;
}