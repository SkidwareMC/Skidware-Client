#include "CModuleManager.hpp"
#include "CAirJumpModule.hpp"
#include "CHUDModule.hpp"
#include "CStrafeModule.hpp"
#include "CFlyModule.hpp"
#include "CClickGUIModule.hpp"
#include "CKillauraModule.hpp"
#include "CSpiderModule.hpp"
#include "CClickerModule.hpp"

void CModuleManager::registerModules() {
	this->registerModule(new CAirJumpModule());
	this->registerModule(new CHUDModule());
	this->registerModule(new CStrafeModule());
	this->registerModule(new CFlyModule());
	this->registerModule(new CClickGUIModule());
	this->registerModule(new CKillauraModule());
	this->registerModule(new CSpiderModule());
	this->registerModule(new CClickerModule());
}