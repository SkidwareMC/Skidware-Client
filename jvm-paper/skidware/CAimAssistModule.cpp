#include "CAimAssistModule.hpp"

CAimAssistModule::CAimAssistModule() : CModule("Rotation", 'I', COMBAT, "Silent Rotation test", "AimTest")
{
	float yaw = 0.0;
}

void CAimAssistModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CAimAssistModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CAimAssistModule::onEvent(const CSimpleEvent*)
{
	CMinecraft* mc = CCheat::theMinecraft;
	//for (CPlayer* entityPlayer : mc->theWorld->getPlayers()) {

	//}
		mc->thePlayer->headRotationYaw = 90;
}

void CAimAssistModule::renderSettings()
{
	ImGui::Separator();

}


