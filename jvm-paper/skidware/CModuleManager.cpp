#include "CModuleManager.hpp"
#include "CAirJumpModule.hpp"
#include "CHUDModule.hpp"
#include "CSpeedModule.hpp"
#include "CFlyModule.hpp"
#include "CClickGUIModule.hpp"
#include "CKillauraModule.hpp"
#include "CSpiderModule.hpp"
#include "CClickerModule.hpp"
#include "CStrafeModule.hpp"
#include "CAimAssistModule.hpp"
#include "CAntiKBModule.hpp"
#include "CAutoSprintModule.hpp"
#include "CNoFallModule.hpp"

void CModuleManager::registerModules() {
	this->registerModule(new CAirJumpModule()); //Airjump
	this->registerModule(new CHUDModule());
	this->registerModule(new CSpeedModule());
	this->registerModule(new CFlyModule());
	this->registerModule(new CClickGUIModule());
	this->registerModule(new CKillauraModule());
	this->registerModule(new CSpiderModule());
	this->registerModule(new CClickerModule());
	this->registerModule(new CStrafeModule());
	// this->registerModule(new CAimAssistModule());
	this->registerModule(new CAntiKBModule());
	//Fix this Smellon
	// this->registerModule(new CAutoSprintModule());
	this->registerModule(new CNoFallDamageModule());
	
}