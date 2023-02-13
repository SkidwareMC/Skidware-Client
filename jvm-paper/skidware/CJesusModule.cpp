#include "CJesusModule.hpp"
#include "CCheat.hpp"

CJesusModule::CJesusModule() : CModule("Jesus", 'L', MOVEMENT, "Walk on water", displayName)
{
}

void CJesusModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CJesusModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CJesusModule::onEvent(const CSimpleEvent*)
{
	displayName = (char*)jesus_current_mode;
	this->displayName = displayName;
	double jumpfactor = 0.0336;
	CMinecraft* mc = CCheat::theMinecraft;
	if (jesus_current_mode == "NCP") {
		if (mc->thePlayer->inWater) {
			mc->thePlayer->motionY = jumpfactor;
			mc->thePlayer->onGround = false;
		}
	}
	else if (jesus_current_mode == "Dolphin") {
		if (mc->thePlayer->inWater) mc->thePlayer->motionY = mc->thePlayer->motionY + 0.03999999910593033;
	}
}

void CJesusModule::renderSettings()
{
	ImGui::Separator();
	if (ImGui::BeginCombo("##kombo2", jesus_current_mode)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(jesus_modes); n++)
		{
			bool is_selected = (jesus_current_mode == jesus_modes[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(jesus_modes[n], is_selected))
				jesus_current_mode = jesus_modes[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
}
