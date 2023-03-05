#include "Disabler.hpp"

Disabler::Disabler() : Module("Disabler", 'U', "Disables some anticheats")
{
}

void Disabler::OnTick()
{
	if (Settings::Disabler) {
		if (Settings::FrequencyFly) {
			LaunchWrapper::getMinecraft().getLocalPlayer().setHurt(1);
		}
		if (Settings::OldAAC) {
			LaunchWrapper::getMinecraft().setTimer(1.5);
		}
	}
}
