#include "CVelocityModule.hpp"


void CVelocityModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}
void CVelocityModule::onEvent(const CSimpleEvent*)
{
	CMinecraft* mc = CCheat::theMinecraft;
	mc->thePlayer->motionX = 0;
	mc->thePlayer->motionZ = 0;
	mc->thePlayer->motionY = 0;
}

void CVelocityModule::renderSettings()
{
}

void CVelocityModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}