#include "CNoSlowModule.hpp"
float val = (100 - 100) / 100;
CNoSlowModule::CNoSlowModule() : CModule("NoSlowDown", NULL, MISC, "Removes Slowdown")
{
}

void CNoSlowModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CNoSlowModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CNoSlowModule::onEvent(const CSimpleEvent*)
{
	CMinecraft* mc = CCheat::theMinecraft;
	if (noslow_current_mode == "Sprint") {
		if (misc::get_keystate(VK_RBUTTON))
			if (mc->thePlayer->isMovingForwardOrBackwards())
				mc->thePlayer->setSprint(true);
	}
	else if (noslow_current_mode == "Move") {
		if (misc::get_keystate(VK_RBUTTON)) {
			mc->thePlayer->movementInput->moveStrafe = mc->thePlayer->movementInput->moveStrafe * val;
			mc->thePlayer->movementInput->moveForward = mc->thePlayer->movementInput->moveForward * val;
		}
	}

}

void CNoSlowModule::renderSettings()
{
	ImGui::Separator();
	if (ImGui::BeginCombo("##combo10", noslow_current_mode)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(noslow_modes); n++)
		{
			bool is_selected = (noslow_current_mode == noslow_modes[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(noslow_modes[n], is_selected))
				noslow_current_mode = noslow_modes[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
}
