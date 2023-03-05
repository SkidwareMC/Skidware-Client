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
	static bool Velocity;
	static int VeloTicks;
	static bool VanillaSpeed;
	static float hori;
	static float vert;
	static const char* velo_modes[2];
	static const char* velo_current_mode;
	static char NameSpoofValue;
	static bool Speed;
	static float multiplier;
	static bool LegitScaffold;
	static int sneak_delay;
	static bool Killaura;
	static float range;
	static bool NCPYPort;
	static float force;
	static bool Fly;
	static float flySpeed;
	static bool NCPBHop;
	static bool groundSpoof;
	static bool Disabler;
	static bool FrequencyFly;
	static bool TimerDisable;
	static bool NoSlow;
	static bool OldAAC;
	static bool Reach;
	static float dist;
	static bool Strafe;
	static bool Timer;
	static float timerspeed;
	static bool RightClick;
	static bool BlockHit;
	static int RightClickSpeed;
};