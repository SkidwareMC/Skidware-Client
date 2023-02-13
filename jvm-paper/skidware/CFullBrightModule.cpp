#include "CFullBrightModule.hpp"
#include "CCheat.hpp"
float originalGammaSetting;
CFullBrightModule::CFullBrightModule() : CModule("FullBright", VK_DOWN, RENDER, "Make your game brighter", "FullBright")
{
}

void CFullBrightModule::onEnable()
{
	CMinecraft* mc = CCheat::theMinecraft;
	originalGammaSetting = mc->gameSettings->gammaSetting;
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
	if (auto e = dynamic_cast<const Render2DEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;
		mc->gameSettings->gammaSetting = 100;
	}
}

void CFullBrightModule::renderSettings()
{
}
