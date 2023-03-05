#include "NoSlow.hpp"
#include "../../SDK/Utils/MCHelper.hpp"
std::vector<std::string> MurderItems =
{
	"item.swordGold",
	"item.swordDiamond",
	"item.swordIron",
	"item.swordStone",
	"item.swordWood",
	"item.appleGold",
	"item.steak"
};
void NoSlow::OnTick()
{
	if (Settings::NoSlow != true) return;
	LocalPlayer player = LaunchWrapper::getMinecraft().getLocalPlayer();
	if (player.isBlocking())
	{
		if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000)) {
			if (!player.isMoving()) return;
			double x = player.get_motion_x();
			double z = player.get_motion_z();
			if (player.getOnGround())
				player.strafe(0.2);
		}
	}
}
