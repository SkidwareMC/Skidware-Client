#include "NoFire.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

void NoFire::OnTick()
{
	if (Settings::NoFire) LaunchWrapper::getMinecraft().getLocalPlayer().SetImmuneToFire(true);
}