#include "CTimerModule.hpp"
#include "CCheat.hpp"

CTimerModule::CTimerModule() : CModule("Timer", '\0', MISC, "TimerHack")
{
}

void CTimerModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CTimerModule::onDisable()
{
	CCheat::eventBus->unregisterListener(this);
}

void CTimerModule::onEvent(const CSimpleEvent*)
{
	CMinecraft* mc = CCheat::theMinecraft;
	mc->timer->tickLength = millsEachTick;
}

void CTimerModule::renderSettings()
{
	ImGui::Separator();
	ImGui::SliderInt("Milliseconds between each tick", &millsEachTick, 1, 1000);
}
