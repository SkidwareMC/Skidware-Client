#pragma once
#include <map>
#include <string>
#include "../../SDK/EntityPlayer.hpp"
#include "Module.hpp"
class AntiBot : Module
{
	AntiBot();
private:
	static std::map<std::string, int> PossibleBots;
	static void FlagBot(EntityPlayer);
	static bool IsNameValid(EntityPlayer);
	static bool IsPingValid(EntityPlayer);
	static bool IsUUIDValid(EntityPlayer);

public:
	static void OnTick();
};