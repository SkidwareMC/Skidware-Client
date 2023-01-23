#include "CKillauraModule.hpp"
#include "CCheat.hpp"

CKillauraModule::CKillauraModule() : CModule("KillAura", 'G', MISC) {

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
		
		for (CPlayer* entityPlayer : mc->theWorld->getPlayers()) {
			continue;
		}
	}
}

void CKillauraModule::renderSettings()
{
	ImGui::Separator();
}
