#include "CFullBrightModule.hpp"
#include "CCheat.hpp"
float originalGammaSetting = 0;
CFullBrightModule::CFullBrightModule() : CModule("FullBright", VK_DOWN, RENDER, "Make your game brighter", "FullBright")
{
}

void CFullBrightModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CFullBrightModule::onDisable()
{
	CMinecraft* mc = CCheat::theMinecraft;
	mc->gameSettings->gammaSetting = originalGammaSetting;
	CCheat::eventBus->unregisterListener(this);
	
}

void CFullBrightModule::onEvent(const CSimpleEvent* event)
{
	CMinecraft* mc = CCheat::theMinecraft;
	if (auto e = dynamic_cast<const Render2DEvent*>(event)) {
		originalGammaSetting = mc->gameSettings->gammaSetting;
		mc->gameSettings->gammaSetting = 100;
	}
}

void CFullBrightModule::renderSettings()
{
}
