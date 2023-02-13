#include "CCriticalsModule.hpp"
#include "CCheat.hpp"
#include "wrapper.h"
CCriticalsModule::CCriticalsModule() : CModule("Criticals", '+', COMBAT, "Crits")
{
}

void CCriticalsModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CCriticalsModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CCriticalsModule::onEvent(const CSimpleEvent*)
{

	displayName = (char*)crits_current_mode;
	this->displayName = displayName;
	CMinecraft* mc = CCheat::theMinecraft;
	if (crits_current_mode == "Mini-Jump") {
		if (mc->thePlayer->onGround)
			mc->thePlayer->motionY = 0.31;
	}
	else if (crits_current_mode == "Jump") {
		if (mc->thePlayer->onGround)
			mc->thePlayer->jump();
	}
	else if (crits_current_mode == "NoGround") {
		if (misc::get_keystate(VK_LBUTTON))
			mc->thePlayer->onGround = false;
	}
}

void CCriticalsModule::renderSettings()
{
	ImGui::Separator();
	ImGui::Separator();
	if (ImGui::BeginCombo("##e", crits_current_mode)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(crits_modes); n++)
		{
			bool is_selected = (crits_current_mode == crits_modes[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(crits_modes[n], is_selected))
				crits_current_mode = crits_modes[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
}
