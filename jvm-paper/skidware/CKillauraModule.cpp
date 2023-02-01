#include "CKillauraModule.hpp"
#include "CCheat.hpp"
#include "wrapper.h"
float yaw, pitch;
CKillauraModule::CKillauraModule() : CModule("Aura", '-', MISC, "generic killaura") {
	
}

void CKillauraModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}

void CKillauraModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

void CKillauraModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;
		/*
		for (CPlayer* entityPlayer : mc->theWorld->getPlayers()) {
			mc->playerController->attackEntity(mc->thePlayer, entityPlayer);
		}
		*/
		yaw = mc->thePlayer->rotationYaw;
		pitch = mc->thePlayer->rotationPitch;
		misc::thread(misc::Rclick);
		mc->thePlayer->rotationPitch = pitch;
		mc->thePlayer->rotationYaw = yaw;
	}
}

void CKillauraModule::renderSettings()
{
	ImGui::Separator();
	ImGui::SliderFloat("APS", &cps::cps, 1, 20);
}

