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
#include "Modules/LegitScaffold.hpp"
#include "Modules/Killaura.hpp"
#include "Modules/NCPYPort.hpp"
#include "Modules/Fly.hpp"
#include "Modules/NCPBhop.hpp"
#include "Modules/Disabler.hpp"
#include "Modules/NoSlow.hpp"
#include "Modules/Reach.hpp"
#include "Modules/Strafe.hpp"
#include "GUI.hpp"
#include <mutex>


int Handler::speed_modes = 1; // vanilla, y-port
int Handler::tick = 0;

void Handler::OnTick()
{
	
	// std::thread thread_obj(DoKeyBinds);
		// CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DoKeyBinds(), 0, 0, 0);
	SetSettings();
	if (tick == 1)
	{
		tick = 0;
		DoKeyBinds();
	}
	else {
		tick++;
	}

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
	Disabler::OnTick();
	VanillaSpeed::OnTick();
	NCPBHop::OnTick();
	NCPYPort::OnTick();
	Flight::OnTick();
	LegitScaffold::OnTick();
	Aura::OnTick();
	NoSlow::OnTick();
	Strafe::OnTick();
	//Reach::OnTick();
}


void Handler::DoKeyBinds()
{
	
	//if (!timer.has_passed(50)) return;
	if (GetAsyncKeyState(VK_END)) Settings::ShouldUninject = true; 
	if ((GetAsyncKeyState(VK_RSHIFT) & 0x8000)) GUI::Enabled = !GUI::Enabled;
	if (!LaunchWrapper::getMinecraft().InGameHasFocus()) return;
	if ((GetAsyncKeyState('U') & 0x8000)) { 
		Settings::Fly = !Settings::Fly; 
		Settings::Disabler = !Settings::Disabler;
	}
	// if ((GetAsyncKeyState('Y') & 0x8000)) Settings::LegitScaffold = !Settings::LegitScaffold; Sleep(0);
	//if ((GetAsyncKeyState('G') & 0x8000)) Settings::Killaura = !Settings::Killaura; Sleep(0);
	//
	
	AutoSprint::OnTick();
	Autoclicker::OnTick();
	//timer.reset();
	
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