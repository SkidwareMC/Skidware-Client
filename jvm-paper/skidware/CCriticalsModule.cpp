#include "CCriticalsModule.hpp"
#include "CCheat.hpp"

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
	CMinecraft* mc = CCheat::theMinecraft;
	if (crits_current_mode == "Mini-Jump") {
		if (mc->thePlayer->onGround)
			mc->thePlayer->motionY = 0.31;
	}
}

void CCriticalsModule::renderSettings()
{
	return;
}
