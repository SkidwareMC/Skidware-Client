#include "CAntiKBModule.hpp"

CAntiKBModule::CAntiKBModule() : CModule("AntiKB", 'K', COMBAT, "NoKB Hack")
{
}

void CAntiKBModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CAntiKBModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CAntiKBModule::onEvent(const CSimpleEvent*)
{
	displayName = (char*)velo_current_mode;
	this->displayName = displayName;
	CMinecraft* mc = CCheat::theMinecraft;
	if (velo_current_mode == "Motion") {
		if (mc->thePlayer->IsHurt()) {
			mc->thePlayer->motionX = 0;
			mc->thePlayer->motionX = 0;
			mc->thePlayer->motionX = 0;

		}
	}
	else if (velo_current_mode == "Jump") {
		if (mc->thePlayer->IsHurt()) {
			if (!mc->thePlayer->onGround) {
				// mc->thePlayer->jump();
			}
			mc->thePlayer->onGround = true;
		}

	}
}

void CAntiKBModule::renderSettings()
{
	ImGui::Separator();
	if (ImGui::BeginCombo("##combo", velo_current_mode)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(velo_modes); n++)
		{
			bool is_selected = (velo_current_mode == velo_modes[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(velo_modes[n], is_selected))
				velo_current_mode = velo_modes[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
}
