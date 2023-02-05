#include "CSpeedModule.hpp"
#include "CCheat.hpp"

CSpeedModule::CSpeedModule() : CModule("Speed", 'B', MOVEMENT, "Fast legs hack") {

}

void CSpeedModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}


void CSpeedModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

void CSpeedModule::onEvent(const CSimpleEvent* event) {
	
	displayName = (char*)speed_current_mode;
	this->displayName = displayName;
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;

		if (speed_current_mode == "Spartan BHop") {
			if (mc->thePlayer->onGround && mc->gameSettings->isAnyKeyDown()) {
				mc->thePlayer->jump();
				mc->thePlayer->strafe(mc->thePlayer->getSpeed() * 1.05);
			}
		}
		else if (speed_current_mode == "AAC BHop") {
			if (mc->thePlayer->onGround && mc->gameSettings->isAnyKeyDown()) {
				mc->thePlayer->jump();
				mc->thePlayer->strafe(mc->thePlayer->getSpeed() * 1.003);
			}
		}

		else if (speed_current_mode == "MineGuard Y-Port") {
			if (mc->thePlayer->onGround) {
				mc->thePlayer->jump();
			} else {
				mc->thePlayer->motionY = -0.203;
			}
		}
		/*
		        if (mc.thePlayer.onGround) {
					MovementUtils.strafe(1.1F);
					mc.thePlayer.motionY = 0.44D;
					return;
				}
		*/

		else if (speed_current_mode == "Spectre BHop") {
			if (mc->thePlayer->onGround) {
				mc->thePlayer->strafe(1.1);
				mc->thePlayer->motionY = 0.44;
			}
		}
		else if (speed_current_mode == "Vanilla BHop") {
			if (mc->thePlayer->onGround) {
				mc->thePlayer->setSprint(true);
				mc->thePlayer->jump();
			}
		}
		else if (speed_current_mode == "Jump Boost") {
			if (mc->gameSettings->keyBindJump) {
				mc->thePlayer->motionY = mc->thePlayer->motionY * boost;
			}
		}
		else if (speed_current_mode == "OnGround") {
			if (mc->thePlayer->onGround && mc->gameSettings->isAnyKeyDown()) {
				mc->thePlayer->motionX = mc->thePlayer->motionX * 1.2;
				mc->thePlayer->motionZ = mc->thePlayer->motionZ * 1.2;
			}
		}
		else if (speed_current_mode == "Frequency OnGround") {
			mc->thePlayer->motionX = 0;
			mc->thePlayer->motionZ = 0;

			if (mc->gameSettings->isAnyKeyDown()) {
				if (mc->thePlayer->isMovingForwardOrBackwards() || mc->thePlayer->isStrafing()) {
					mc->thePlayer->strafe(freqMulti);
				}
			}
		}
	}
}

void CSpeedModule::renderSettings()
{
	ImGui::Separator();
	if (ImGui::BeginCombo("##combo", speed_current_mode)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(speed_modes); n++)
		{
			bool is_selected = (speed_current_mode == speed_modes[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(speed_modes[n], is_selected))
				speed_current_mode = speed_modes[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
	if (speed_current_mode == "Jump Boost")
		ImGui::SliderFloat("Boost", &boost, 1, 10, "%.1f");
	if (speed_current_mode == "Frequency OnGround")
		ImGui::SliderFloat("Speed", &freqMulti, 1, 10, "%.1f");
}
