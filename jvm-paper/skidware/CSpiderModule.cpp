#include "CSpiderModule.hpp"
#include "CCheat.hpp"

CSpiderModule::CSpiderModule() : CModule("Spider", 'P', MOVEMENT, "Climb up walls") {

}

void CSpiderModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}

void CSpiderModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

void CSpiderModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;
		if (mc->thePlayer->isCollidedHorizontally())
			mc->thePlayer->motionY = 0.3;

			
		// if (mc->thePlayer->isMovingForwardOrBackwards() && mc->thePlayer->motionX == 0 || mc->thePlayer->motionZ == 0) 
	}
}

void CSpiderModule::renderSettings()
{
	ImGui::Separator();
}
