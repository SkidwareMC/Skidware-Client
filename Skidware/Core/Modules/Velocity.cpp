#include "Velocity.hpp"
#include "../Wrapper/Utils.hpp"
void Velocity::OnTick()
{
	if (Settings::Velocity == true) {
		Minecraft mc = LaunchWrapper::getMinecraft();
		vector3 currentVelo = mc.getLocalPlayer().Velocity();
		if (mc.getLocalPlayer().isHurt()) {
			double newHorizontalVeloX = currentVelo.x * (double)Settings::horizontal;
			double newHorizontalVeloZ = currentVelo.z * (double)Settings::horizontal;
			double newVertizalVeloY = currentVelo.y * (double)Settings::vertical;
			//mc.getLocalPlayer().setOnGround((jboolean)true);
		}
	}
}

