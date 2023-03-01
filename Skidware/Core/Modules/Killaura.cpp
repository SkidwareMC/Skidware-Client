#include "Killaura.hpp"

void Aura::OnTick()
{
	LocalPlayer thePlayer = LaunchWrapper::getMinecraft().getLocalPlayer();
	if (Settings::Killaura) {
		for (EntityPlayer player : LaunchWrapper::getMinecraft().getWorld().getPlayerList()) {
			if ((bool)JNIHelper::env->IsSameObject(player.GetCurrentObject(), LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject())) {
				Logger::LogDebug("Skipped PlayerSP");
				continue;
				
			}
			if (util::distance(thePlayer.GetPositionX(), thePlayer.GetPositionY(), thePlayer.GetPositionZ(), player.GetPositionX(), player.GetPositionY(), player.GetPositionZ()) <= Settings::range) {
				Logger::LogDebug("Attacking");
				LaunchWrapper::getMinecraft().getLocalPlayer().attackEntity(player);
				thePlayer.swingItem();
			}
		}
	}
}
