#include "CAutoSprintModule.hpp"
#include "wrapper.h"

CAutoSprintModule::CAutoSprintModule() : CModule("AutoSprint", '[', MOVEMENT, "Crashes after a couple hundred ticks. idk why", "Sprint")
{
}

void CAutoSprintModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CAutoSprintModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CAutoSprintModule::onEvent(const CSimpleEvent* event)
{
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {}
	CMinecraft* mc = CCheat::theMinecraft;
	if (mc->gameSettings->keyBindForward->isKeyDown())
		mc->gameSettings->keyBindSprint->setKeyBindState(mc->gameSettings->keyBindSprint->keyCode, true);
}

void CAutoSprintModule::renderSettings()
{
	ImGui::Separator();
	return;
}
