#include "CSpeedModule.hpp"
#include "CCheat.hpp"

CSpeedModule::CSpeedModule() : CModule("Spartan Speed", 'B', MOVEMENT) {

}

void CSpeedModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}


void CSpeedModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

void CSpeedModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;

		if (!mc->thePlayer->onGround && mc->gameSettings->isAnyKeyDown()) {
			mc->thePlayer->strafe(mc->thePlayer->getSpeed() * 1.1);
		}
	}
}

void CSpeedModule::renderSettings()
{
	ImGui::Separator();
}
