#include "Strafe.hpp"

void Strafe::OnTick()
{
	if (!Settings::Strafe) return;
	if (LaunchWrapper::getMinecraft().getLocalPlayer().isHurt(0)) return;
	if (!LaunchWrapper::getMinecraft().getLocalPlayer().getOnGround())
		LaunchWrapper::getMinecraft().getLocalPlayer().strafe(LaunchWrapper::getMinecraft().getLocalPlayer().getSpeed());
}
