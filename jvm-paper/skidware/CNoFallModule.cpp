#include "CNoFallModule.hpp"
#include "CCheat.hpp"

CNoFallDamageModule::CNoFallDamageModule() : CModule("NoFall", 'N', MISC, "Strong bones hack. No fall damage")
{
}

void CNoFallDamageModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CNoFallDamageModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CNoFallDamageModule::onEvent(const CSimpleEvent*)
{
	displayName = (char*)nofall_current_mode;
	this->displayName = displayName;
	CMinecraft* mc = CCheat::theMinecraft;
	if (nofall_current_mode == "AAC 3.3.7") {
		if (mc->thePlayer->onGround) {
			mc->thePlayer->motionY = force;
		}
	}
	else if (nofall_current_mode == "Spoof") {
		if (mc->thePlayer->fallDistance > 2.5) {
			mc->thePlayer->motionY = 0;
		}
	}
}

void CNoFallDamageModule::renderSettings()
{
	ImGui::Separator();
	if (ImGui::BeginCombo("##combo8", nofall_current_mode)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(nofall_modes); n++)
		{
			bool is_selected = (nofall_current_mode == nofall_modes[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(nofall_modes[n], is_selected))
				nofall_current_mode = nofall_modes[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
	if (nofall_current_mode == "AAC 3.3.7") {
		ImGui::SliderInt("Force", &force, -3, -21);
	}
}
