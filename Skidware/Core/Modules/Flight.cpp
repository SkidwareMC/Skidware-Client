#include "Flight.hpp"
#include "../../Wrapper/Logger.hpp"
#include "../../Wrapper/Utils.hpp"
Fly::Fly() : Module("Velocity", NULL, "Makes you take less knockback")
{
}
void Fly::OnTick()
{
	if (Settings::Velocity) {

		if (LaunchWrapper::getMinecraft().getLocalPlayer().isHurt(Settings::VeloTicks) == true) {
			if (Settings::groundSpoof)
				LaunchWrapper::getMinecraft().getLocalPlayer().setOnGround(true);
			double motionx = LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_x();
			double motionz = LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_z();
			double motiony = LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_y();
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_x(motionx * Settings::hori);
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_z(motionz * Settings::hori);
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_y(motiony * Settings::vert);
		}

			
	}
}

