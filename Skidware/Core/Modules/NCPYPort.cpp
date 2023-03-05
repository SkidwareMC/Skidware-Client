#include "NCPYPort.hpp"
#include "../../Wrapper/Logger.hpp"
#include <xtree>
void NCPYPort::OnTick()
{
	if (!Settings::NCPYPort == true) {
		return;
	}
	float speed = 1.01;
	/*
	if (!(GetAsyncKeyState('W') & 0x8000)) return;
	if (LaunchWrapper::getMinecraft().getLocalPlayer().getOnGround()) {
		LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_y(0.42);
		LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_x(LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_x() * 1.12);
		LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_z(LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_z() * 1.12);
	}
	else if (LaunchWrapper::getMinecraft().getLocalPlayer().get_fall_distance() < 0.25) {
		LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_y(-63);
		Logger::Log("StrafeUpdate");
		LaunchWrapper::getMinecraft().getLocalPlayer().setMoveStrafing(LaunchWrapper::getMinecraft().getLocalPlayer().getMoveStrafing() * 2);
		LaunchWrapper::getMinecraft().getLocalPlayer().strafe(speed);
	}
	*/
	if (!LaunchWrapper::getMinecraft().getLocalPlayer().getOnGround())
		LaunchWrapper::getMinecraft().getLocalPlayer().strafe(LaunchWrapper::getMinecraft().getLocalPlayer().getSpeed() * speed);
	
	

}
