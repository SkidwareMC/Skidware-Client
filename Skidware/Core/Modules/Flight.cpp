#include "Flight.hpp"
#include "../../Wrapper/Logger.hpp"
#include "../../Wrapper/Utils.hpp"
void Fly::OnTick()
{
	if (Settings::Velocity) {

	if (LaunchWrapper::getMinecraft().getLocalPlayer().isHurt(Settings::VeloTicks) == true)
		LaunchWrapper::getMinecraft().getLocalPlayer().setOnGround(true);
	// Logger::LogDebug("Spoofed Ground");

			
	}
}

