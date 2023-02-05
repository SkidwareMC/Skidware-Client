#include "CAirJumpModule.hpp"

CAirJumpModule::CAirJumpModule() : CModule("AirJump", 'F', MOVEMENT, "Jump in the air", "AirJump") {
}

void CAirJumpModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;
		mc->thePlayer->onGround = true;
	}
}

void CAirJumpModule::renderSettings()
{
	ImGui::Separator();
}

void CAirJumpModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}

void CAirJumpModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

