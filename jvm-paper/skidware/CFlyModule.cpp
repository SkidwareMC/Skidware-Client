#include "CFlyModule.hpp"
#include "CCheat.hpp"

CFlyModule::CFlyModule() : CModule("Fly", 'V') {

}

void CFlyModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}

void CFlyModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

void CFlyModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		CMinecraft* mc = CCheat::theMinecraft;

		mc->thePlayer->motionX = 0;
		mc->thePlayer->motionY = -0.1;
		mc->thePlayer->motionZ = 0;

		if (mc->gameSettings->isAnyKeyDown()) {
			if (mc->thePlayer->isMovingForwardOrBackwards() || mc->thePlayer->isStrafing()) {
				mc->thePlayer->strafe(2);
			}
		}

		if (mc->gameSettings->keyBindJump->pressed) {
			mc->thePlayer->motionY = 0.7;
		}
		if (mc->gameSettings->keyBindSneak->pressed) {
			mc->thePlayer->motionY = -0.5;
		}
	}
}