#include "CTowerModule.hpp"
#include <Windows.h>
#include "CCheat.hpp"
#include "wrapper.h"
float pitch;
//hi
CTowerModule::CTowerModule() : CModule("TowerHack", 'Z', MISC, "Tower up quickly", "Tower")
{
}

void CTowerModule::onEnable()
{
	CMinecraft* mc = CCheat::theMinecraft;
	pitch = mc->thePlayer->rotationPitch;
	CCheat::eventBus->registerListener(this);
}

void CTowerModule::onDisable()
{
	CMinecraft* mc = CCheat::theMinecraft;
	mc->thePlayer->rotationPitch = pitch;
	CCheat::eventBus->unregisterListener(this);
}

void CTowerModule::onEvent(const CSimpleEvent* event)
{
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;
		mc->thePlayer->rotationPitch = 90;
		mc->thePlayer->motionY = speed;
		misc::thread(misc::PlaceBlock);
	}
}

void CTowerModule::renderSettings()
{
	ImGui::Separator();
	ImGui::SliderFloat("Speed", &speed, 0.1, 1.0, "%.1f");
}
