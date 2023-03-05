#include "NCPBhop.hpp"

void NCPBHop::OnTick()
{
	int jumps = 0;
	Minecraft mc = LaunchWrapper::getMinecraft();
	LocalPlayer player = LaunchWrapper::getMinecraft().getLocalPlayer();
	jclass playerclass = JNIHelper::env->GetObjectClass(LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject());
	jfieldID speedairfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_71102_ce" : "bF", "F");
	if (Settings::NCPBHop) {
		
		if (player.isMoving()) {
			
			double x = player.get_motion_x();
			double z = player.get_motion_z();
			double y = player.get_motion_y();
			
			if (jumps == 7) {
				player.strafe(player.getSpeed() * 1.0);
				jumps = 0;
			}
			else {
				player.strafe(player.getSpeed() * 1.01);
				player.set_motion_x(x * 1.01);
				player.set_motion_z(z * 1.01);
				jumps++;
			}
			mc.setTimer(1.0005);
			JNIHelper::env->SetFloatField(player.GetCurrentObject(), speedairfid, 0.0201f);
			if (player.getOnGround() == false) {
				player.strafe(player.getSpeed());
			}
			
		}
		
		
	}
	else {
		JNIHelper::env->SetFloatField(player.GetCurrentObject(), speedairfid, 0.02f);
		mc.setTimer(1);
	}
}
