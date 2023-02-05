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
}

void CCriticalsModule::renderSettings()
{
	return;
}
