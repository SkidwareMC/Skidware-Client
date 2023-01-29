#include "CFlyModule.hpp"
#include "CCheat.hpp"
#include "wrapper.h"

CFlyModule::CFlyModule() : CModule("Fly", 'V', MOVEMENT, "Zoom") {

}

void CFlyModule::onEnable() {
	CMinecraft* mc = CCheat::theMinecraft;
	mc->thePlayer->onGround = false;
	CCheat::eventBus->registerListener(this);
}

void CFlyModule::onDisable() {
	CMinecraft* mc = CCheat::theMinecraft;
	mc->thePlayer->onGround = true;
	CCheat::eventBus->unregisterListener(this);
}

void CFlyModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;

		if (fly_current_mode == "Spartan")
			mc->thePlayer->motionX = 0;
			mc->thePlayer->motionY = -0.1;
			mc->thePlayer->motionZ = 0;
			
			if (mc->gameSettings->isAnyKeyDown()) {
				if (mc->thePlayer->isMovingForwardOrBackwards() || mc->thePlayer->isStrafing()) {
					mc->thePlayer->strafe(2);
				}
			}

			if (mc->gameSettings->keyBindJump->pressed) {
				mc->thePlayer->motionY = 0.7;
			}
			if (mc->gameSettings->keyBindSneak->pressed) {
				mc->thePlayer->motionY = -0.5;
			}

		else if (fly_current_mode == "Keep-Y")
		{
				mc->thePlayer->motionX = mc->thePlayer->motionX * 0;
				mc->thePlayer->motionY = 0;
				mc->thePlayer->motionZ = mc->thePlayer->motionZ * 0;
		}
	} 

	
}

void CFlyModule::renderSettings()
{
	ImGui::Separator();
	if (ImGui::BeginCombo("##kombo", fly_current_mode)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(fly_modes); n++)
		{
			bool is_selected = (fly_current_mode == fly_modes[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(fly_modes[n], is_selected))
				fly_current_mode = fly_modes[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
}
