#include "Handler.hpp"
#include <Windows.h>
#include "Settings.hpp"
#include "../Wrapper/Logger.hpp"
#include "../Wrapper/ClientConsole.hpp";
#include "../SDK/LaunchWrapper.hpp"
#include "Modules/Flight.hpp"
#include "Modules/Autoclicker.hpp"
#include "Modules/NoHitDelay.hpp"
#include "Modules/NoBuildDelay.hpp"
#include "Modules/FrameSpoof.hpp"
#include "Modules/AntiBot.hpp"
#include "Modules/AutoSprint.hpp"
#include "Modules/HitBoxExtender.hpp"
#include "Modules/NoFire.hpp"
#include "Modules/PlayerESP.hpp"
#include "Modules/PingSpoof.hpp"
#include "Modules/MurderExpose.hpp"
#include "Modules/VanillaSpeed.hpp"
#include "GUI.hpp"

int speed_modes = { 0 }; // vanilla, y-port

void Handler::OnTick()
{
	SetSettings();
	DoKeyBinds();

	NoHitDelay::OnTick();
	NoBuildDelay::OnTick();
	FrameSpoof::OnTick();
	AntiBot::OnTick();
	HitBoxExtender::OnTick();
	NoFire::OnTick();
	PlayerESP::OnTick();
	PingSpoof::OnTick();
	MurderExpose::OnTick();
	Fly::OnTick(); //actually velocity
	if (speed_modes == 0)
	{
		VanillaSpeed::OnTick();
	}
}

void Handler::DoKeyBinds()
{
	if (GetAsyncKeyState(VK_END)) Settings::ShouldUninject = true;
	if ((GetAsyncKeyState(VK_RSHIFT) & 0x8000)) GUI::Enabled = !GUI::Enabled; Sleep(50);

	if (!LaunchWrapper::getMinecraft().InGameHasFocus()) return;
	
	AutoSprint::OnTick();
	Autoclicker::OnTick();
}

void Handler::SetSettings()
{
	Settings::DebugFPS = LaunchWrapper::getMinecraft().GetFPS();
	Settings::DebugPing = LaunchWrapper::getMinecraft().getLocalPlayer().getNetworkPlayerInfo().GetPing();
	Settings::CanRenderMenu = LaunchWrapper::getMinecraft().getWorld().GetCurrentClass() != NULL;
	Settings::DebugHeight = LaunchWrapper::getMinecraft().GetDisplayHeight();
	Settings::DebugWidth = LaunchWrapper::getMinecraft().GetDisplayWidth();
}

void Handler::OnJoinedWorld()
{
	ClientConsole::ClearLogs();
}