#include "CAutoSprintModule.hpp"
#include "wrapper.h"

CAutoSprintModule::CAutoSprintModule() : CModule("AutoSprint", '[', MOVEMENT, "Crashes after a couple hundred ticks. idk why")
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
	if (mc->gameSettings->keyBindForward->isKeyDown()) {
		mc->thePlayer->setSprint(true);
		out::display("Sprint\n");
	}
}

void CAutoSprintModule::renderSettings()
{
}
