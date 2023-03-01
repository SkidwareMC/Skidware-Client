#include "Fly.hpp"
#include "../../Wrapper/Logger.hpp"
void Flight::OnTick()
{
	if (Settings::Fly) {
		// LaunchWrapper::getMinecraft().getLocalPlayer().strafe(Settings::flySpeed);
		LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_y(0);
		if (LaunchWrapper::getMinecraft().getLocalPlayer().get_fall_distance() > 0.0) {
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_y(0.1);
			LaunchWrapper::getMinecraft().getLocalPlayer().setFallDist(0);
			LaunchWrapper::getMinecraft().getLocalPlayer().setOnGround(true);
		}
		// LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_x(LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_x() * 0.5);
		// LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_z(LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_z() * 0.5);
		LaunchWrapper::getMinecraft().getLocalPlayer().strafe(Settings::flySpeed);
		if ((LaunchWrapper::getMinecraft().getLocalPlayer().getMoveForward() == 0)) {
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_x(0); 
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_z(0);
			LaunchWrapper::getMinecraft().getLocalPlayer().setOnGround(true);
		}
	}
}
