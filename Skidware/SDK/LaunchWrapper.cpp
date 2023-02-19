#include "LaunchWrapper.hpp"
#include "JNIHelper.hpp"
#include "../Wrapper/Logger.hpp"

Minecraft LaunchWrapper::getMinecraft()
{
	if (MinecraftInstance.GetCurrentClass() == NULL)
	{
		if (minecraftClass == NULL)
		{
			minecraftClass = JNIHelper::IsForge() ? JNIHelper::ForgeFindClass("net.minecraft.client.Minecraft") : JNIHelper::env->FindClass("ave");
			if (minecraftClass == NULL) return NULL;
		}

		if (getMinecraftFieldID == NULL)
		{
			getMinecraftFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetStaticFieldID(minecraftClass, "field_71432_P", "Lnet/minecraft/client/Minecraft;") : JNIHelper::env->GetStaticFieldID(minecraftClass, "S", "Lave;");
			if (getMinecraftFieldID == NULL) return NULL;
		}

		if (getMinecraftObject == NULL)
		{
			getMinecraftObject = JNIHelper::env->GetStaticObjectField(minecraftClass, getMinecraftFieldID);
			if (getMinecraftObject == NULL) return NULL;
		}

		MinecraftInstance = Minecraft(getMinecraftObject);
	}

	return MinecraftInstance;
}

ActiveRenderInfo LaunchWrapper::getActiveRenderInfo()
{
	if (ActiveRenderInfoInstance.GetCurrentClass() == NULL)
	{
		if (ActiveRenderInfoClass == NULL)
		{
			ActiveRenderInfoClass = JNIHelper::IsForge() ? JNIHelper::ForgeFindClass("net.minecraft.client.renderer.ActiveRenderInfo") : JNIHelper::env->FindClass("auz");
			if (ActiveRenderInfoClass == NULL) return NULL;
		}

		ActiveRenderInfoInstance = ActiveRenderInfo(ActiveRenderInfoClass);
	}

	return ActiveRenderInfoInstance;
}