#include "CNoFallModule.hpp"
#include "CCheat.hpp"

CNoFallDamageModule::CNoFallDamageModule() : CModule("NoFall", 'N', MISC)
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
	CMinecraft* mc = CCheat::theMinecraft;
	if (mc->thePlayer->onGround) {
	 	mc->thePlayer->motionY = -6;
	}
}

void CNoFallDamageModule::renderSettings()
{
	return;
}
