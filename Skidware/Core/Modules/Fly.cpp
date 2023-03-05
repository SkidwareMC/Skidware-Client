#include "Fly.hpp"
#include "../../Wrapper/Logger.hpp"
void Flight::OnTick()
{
	//spartan fly
	Minecraft mc = LaunchWrapper::getMinecraft();
	LocalPlayer player = mc.getLocalPlayer();

	if (Settings::Fly) {
		if (player.ticksExisted() % 3 != 0) return;
		player.set_motion_y(0);
		if (player.get_fall_distance() > 0) {
			player.set_motion_y(0.2);
			player.setFallDist(0);
		}
		player.strafe(Settings::flySpeed);
		if (player.getMoveForward() == 0) {
			//pasted cause lazy lol
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_x(0);
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_z(0);
		}
	}
}
