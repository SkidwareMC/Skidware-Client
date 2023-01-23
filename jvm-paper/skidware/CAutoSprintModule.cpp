#include "CAutoSprintModule.hpp"

CAutoSprintModule::CAutoSprintModule() : CModule("AutoSprint", '[', MOVEMENT)
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

void CAutoSprintModule::onEvent(const CSimpleEvent*)
{
	CMinecraft* mc = CCheat::theMinecraft;
	if (mc->gameSettings->keyBindForward->pressed == true) {
		mc->thePlayer->setSprint(true);
	}
}

void CAutoSprintModule::renderSettings()
{
}
