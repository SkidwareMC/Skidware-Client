#include "CModuleManager.hpp"
#include "CAirJumpModule.hpp"
#include "CHUDModule.hpp"
#include "CStrafeModule.hpp"
#include "CFlyModule.hpp"
#include "CClickGUIModule.hpp"
#include "CKillauraModule.hpp"

void CModuleManager::registerModules() {
	std::cout << "[1/6] Airjump" << "\n";
	Sleep(1500);
	this->registerModule(new CAirJumpModule());
	std::cout << "[2/6] HUD" << "\n";
	Sleep(1500);
	this->registerModule(new CHUDModule());
	std::cout << "[3/6] Stafe" << "\n";
	Sleep(1500);
	this->registerModule(new CStrafeModule());
	std::cout << "[4/6] Fly" << "\n";
	Sleep(1500);
	this->registerModule(new CFlyModule());
	std::cout << "[5/6] ClickGUI" << "\n";
	Sleep(1500);
	this->registerModule(new CClickGUIModule());
	std::cout << "[6/6] Killaura (crashes)" << "\n";
	Sleep(1500);
	this->registerModule(new CKillauraModule());
}