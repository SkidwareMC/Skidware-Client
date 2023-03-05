#include "Settings.hpp"

//GENERAL
bool Settings::ShouldUninject = false;
int Settings::DebugFPS = 0;
int Settings::DebugPing = 0;
int Settings::DebugWidth = 0;
int Settings::DebugHeight = 0;
bool Settings::CanRenderMenu = false;

//MOVEMENT
bool Settings::AutoSprint = false;
bool Settings::Speed = false;
float Settings::multiplier = 1.0f;
bool Settings::NCPYPort = false;
bool Settings::Fly = false;
float Settings::flySpeed = 0.5;
bool Settings::NCPBHop = false;
bool Settings::VanillaSpeed = false;
bool Settings::Strafe = false;
bool Settings::Timer = false;
float Settings::timerspeed = 1.2f;

//COMBAT
bool Settings::NoHitDelay = false;
bool Settings::NoBuildDelay = false;
bool Settings::Autoclicker = false;
bool Settings::RightClick = false;
int Settings::AutoclickerCount = 16;
int Settings::RightClickSpeed = 16;
bool Settings::BlockHit = true;
bool Settings::HitBoxExtender = false;
float Settings::HitBoxWidth = 0.4f;
float Settings::HitBoxHeight = 0.2f;
bool Settings::Velocity = false;
float Settings::vert = 1;
float Settings::hori = .75;
bool Settings::groundSpoof = true;
int Settings::VeloTicks = 0;
bool Settings::Killaura = false;
float Settings::range = 3.5;
bool Settings::NoSlow = false;
bool Settings::Reach = false;
float Settings::dist = 3.2;


//PROTECTION
bool Settings::AntiBot = false;
bool Settings::AntiBotNameFlag = false;
bool Settings::AntiBotPingFlag = false;
bool Settings::AntiBotRiskyPingFlag = false;
bool Settings::AntiBotUUIDFlag = false;

//Visual
bool Settings::FrameSpoof = false;
int Settings::FrameSpoofValue = 999;
bool Settings::PingSpoof;
int Settings::PingSpoofValue = 999;
bool Settings::NoFire = false;

//ESP
bool Settings::PlayerESP = false;
bool Settings::ChestESP = false;

//MISC
bool Settings::NameSpoof = false;
char Settings::NameSpoofValue = (const char)"Skidware";
bool Settings::LegitScaffold = false;
int Settings::sneak_delay = 100;
bool Settings::Disabler = false;
bool Settings::FrequencyFly = true;
bool Settings::TimerDisable;
bool Settings::OldAAC = false;
//HYPIXEL
bool Settings::MurderExpose = false;