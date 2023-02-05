#include "CTimerModule.hpp"
#include "CCheat.hpp"

CTimerModule::CTimerModule() : CModule("Timer", '\0', MISC, "TimerHack", "Timer")
{
}

void CTimerModule::onEnable()
{
	CCheat::eventBus->registerListener(this);
}

void CTimerModule::onDisable()
{
	CMinecraft* mc = CCheat::theMinecraft;
	CCheat::eventBus->unregisterListener(this);
	mc->timer->tickLength = 50;
	CCheat::timerDelay = 50;
}

void CTimerModule::onEvent(const CSimpleEvent*)
{
	CMinecraft* mc = CCheat::theMinecraft;
	int delay = (1000 / tps);
	CCheat::timerDelay = delay;
	mc->timer->tickLength = delay;
}

void CTimerModule::renderSettings()
{
	ImGui::Separator();
	ImGui::SliderInt("Ticks Per Second (default 20)", &tps, 1, 1000);
}
