#include "MCHelper.hpp"
#include "../LaunchWrapper.hpp"

EntityPlayer MCHelper::getEntityPlayerByName(std::string name)
{
	for (auto& player : LaunchWrapper::getMinecraft().getWorld().getPlayerList())
	{
		if (JstringToString(player.GetDisplayName()) == name) return player;
	}
	
	return NULL;
}

Entity MCHelper::getEntityByName(std::string name)
{
	for (auto& entity : LaunchWrapper::getMinecraft().getWorld().getEntityList())
	{
		if (JstringToString(entity.GetDisplayName()) == name) return entity;
	}

	return NULL;
}

std::string MCHelper::JstringToString(jstring original)
{
	if (original == NULL) return "";
	return JNIHelper::env->GetStringUTFChars(original, 0);
}

jstring MCHelper::StringToJstring(const char* original)
{
	return JNIHelper::env->NewStringUTF(original);
}