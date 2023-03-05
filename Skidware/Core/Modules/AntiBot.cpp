#include "AntiBot.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"
#include "../../Wrapper/Logger.hpp"
#include "../../Wrapper/ClientConsole.hpp"
#include "../../SDK/Utils/MCHelper.hpp"
#include "../../ImGui/imgui.h"

std::map<std::string, int> AntiBot::PossibleBots;
AntiBot::AntiBot() : Module("Antibot", NULL, "Removes Anticheat Bots") {
	
}

void AntiBot::OnTick()
{
	if (Settings::AntiBot)
	{
		for (std::map<std::string, int>::iterator iter = PossibleBots.begin(); iter != PossibleBots.end(); ++iter)
		{
			std::string Name = iter->first;

			auto player = MCHelper::getEntityPlayerByName(Name);
			if (player.GetCurrentClass() == NULL)
			{
				PossibleBots.erase(Name);
				continue;
			}

			jint Ping = player.getNetworkPlayerInfo().GetPing();
			if (Ping > 3)
			{
				PossibleBots.erase(Name);
				continue;
			}

			if (iter->second++ == 200)
			{
				FlagBot(player);
				PossibleBots.erase(Name);
			}
		}

		for (auto& player : LaunchWrapper::getMinecraft().getWorld().getPlayerList())
		{
			if (JNIHelper::env->IsSameObject(player.GetCurrentObject(), LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject())) continue;

			if (Settings::AntiBotNameFlag && !IsNameValid(player)) FlagBot(player);

			else if (Settings::AntiBotUUIDFlag && !IsUUIDValid(player)) FlagBot(player);

			else if (Settings::AntiBotPingFlag && !IsPingValid(player)) FlagBot(player);

			else if (Settings::AntiBotRiskyPingFlag)
			{
				jint Ping = player.getNetworkPlayerInfo().GetPing();
				if (Ping < 3)
				{
					std::string DisplayName = MCHelper::JstringToString(player.GetDisplayName());
					if (!PossibleBots.count(DisplayName)) PossibleBots.insert({ DisplayName, 0 });
				}
			}
		}
	}
}

bool AntiBot::IsNameValid(EntityPlayer player)
{
	std::string DisplayName = MCHelper::JstringToString(player.GetDisplayName());
	bool ContainsIllegalChars = DisplayName.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890_") != std::string::npos;
	return !ContainsIllegalChars;
}

bool AntiBot::IsPingValid(EntityPlayer player)
{
	jint Ping = player.getNetworkPlayerInfo().GetPing();
	if (Ping < 0 || Ping > 9999) return false;
	return true;
}

bool AntiBot::IsUUIDValid(EntityPlayer player)
{
	// needs code
	return false;
}

bool AntiBot::TicksExistedFlag(EntityPlayer player)
{
	if (player.ticksExisted() < 3)
		return true;
	return false;
}

void AntiBot::FlagBot(EntityPlayer player)
{
	std::string DisplayName = MCHelper::JstringToString(player.GetDisplayName());
	bool ContainsIllegalChars = DisplayName.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890_") != std::string::npos;
	if (ContainsIllegalChars) DisplayName = "[INVALID NAME]";

	Logger::Log(DisplayName + " got detected as Bot");
	ClientConsole::Log(DisplayName + " got detected as Bot");

	LaunchWrapper::getMinecraft().getWorld().RemoveEntity(player);
}

void AntiBot::renderSetts() {
	ImGui::Checkbox("Anti Bot", &Settings::AntiBot);
	if (Settings::AntiBot)
	{
		ImGui::Checkbox("Name Flag", &Settings::AntiBotNameFlag);
		ImGui::Checkbox("Ping Flag", &Settings::AntiBotPingFlag);
		ImGui::Checkbox("Risky Ping Flag", &Settings::AntiBotRiskyPingFlag);
		ImGui::Checkbox("UUID Flag", &Settings::AntiBotUUIDFlag);
	}
}