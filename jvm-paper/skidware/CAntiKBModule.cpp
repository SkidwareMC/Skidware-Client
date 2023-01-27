#include "CAntiKBModule.hpp"

CAntiKBModule::CAntiKBModule() : CModule("AntiKB", 'K', COMBAT)
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
	CMinecraft* mc = CCheat::theMinecraft;
	if (mc->thePlayer->IsHurt()) {
		mc->thePlayer->motionX = 0;
		mc->thePlayer->motionX = 0;
		mc->thePlayer->motionX = 0;

	}
}

void CAntiKBModule::renderSettings()
{
	ImGui::Separator();
}
