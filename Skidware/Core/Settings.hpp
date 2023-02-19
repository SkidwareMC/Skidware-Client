#pragma once
#include <string>

class Settings
{
public:
	static bool ShouldUninject;
	static int DebugFPS;
	static int DebugPing;
	static int DebugWidth;
	static int DebugHeight;
	static bool CanRenderMenu;
	static bool AutoSprint;
	static bool NoHitDelay;
	static bool NoBuildDelay;
	static bool Autoclicker;
	static int AutoclickerCount;
	static bool HitBoxExtender;
	static float HitBoxWidth;
	static float HitBoxHeight;
	static bool AntiBot;
	static bool AntiBotNameFlag;
	static bool AntiBotPingFlag;
	static bool AntiBotRiskyPingFlag;
	static bool AntiBotUUIDFlag;
	static bool FrameSpoof;
	static bool PingSpoof;
	static int FrameSpoofValue;
	static int PingSpoofValue;
	static bool NoFire;
	static bool PlayerESP;
	static bool ChestESP;
	static bool MurderExpose;
	static bool NameSpoof;
	static bool fly;
	static char NameSpoofValue;
};