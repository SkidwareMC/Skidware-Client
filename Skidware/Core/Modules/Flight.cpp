#include "Flight.hpp"

void Fly::OnTick()
{
	if (Settings::fly) {
		LaunchWrapper::getMinecraft().getLocalPlayer().setFly((jboolean)true);
	}
}

