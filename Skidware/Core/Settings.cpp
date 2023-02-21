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

//COMBAT
bool Settings::NoHitDelay = false;
bool Settings::NoBuildDelay = false;
bool Settings::Autoclicker = false;
int Settings::AutoclickerCount = 16;
bool Settings::HitBoxExtender = false;
float Settings::HitBoxWidth = 0.4f;
float Settings::HitBoxHeight = 0.2f;
bool Settings::Velocity = false;
int Settings::VeloTicks = 0;


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

//HYPIXEL
bool Settings::MurderExpose = false;