#pragma once
#include "Minecraft.hpp"
#include "ActiveRenderInfo.hpp"

class LaunchWrapper
{
private:
	inline static jclass minecraftClass = NULL;
	inline static jfieldID getMinecraftFieldID = NULL;
	inline static jobject getMinecraftObject = NULL;
	inline static Minecraft MinecraftInstance = NULL;

	inline static jclass ActiveRenderInfoClass = NULL;
	inline static ActiveRenderInfo ActiveRenderInfoInstance = NULL;
public:
	static Minecraft getMinecraft();
	static ActiveRenderInfo getActiveRenderInfo();
};