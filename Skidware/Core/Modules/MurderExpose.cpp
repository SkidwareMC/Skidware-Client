#include "MurderExpose.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"
#include "../../Wrapper/Logger.hpp"
#include "../../Wrapper/ClientConsole.hpp"
#include "../../SDK/Utils/MCHelper.hpp"

std::vector<std::string> MurderExpose::MurderItems =
{
	"item.swordGold",
	"item.swordDiamond",
	"item.swordIron",
	"item.swordStone",
	"item.swordWood",
	"item.shovelGold",
	"item.shovelDiamond",
	"item.shovelIron",
	"item.shovelStone",
	"item.shovelWood",
	"item.hatchedGold",
	"item.hatchedDiamond",
	"item.hatchedIron",
	"item.hatchedStone",
	"item.hatchedWood",
	"item.pickaxeGold",
	"item.pickaxeDiamond",
	"item.pickaxeIron",
	"item.pickaxeStone",
	"item.pickaxeWood",
	"item.hoeGold",
	"item.hoeDiamond",
	"item.hoeIron",
	"item.hoeStone",
	"item.hoeWood",
	"item.feather",
	"item.carrotGolden",
	"item.nameTag",
	"item.carrotOnAStick",
	"item.blazeRod",
	"tile.notGate",
	"tile.torch",
	"item.bone",
	"item.cookie",
	"item.stick",
	"item.prismarineShard",
	"item.apple",
	"item.speckledMelon",
	"item.beefCooked",
	"item.pumpkinPie",
	"item.carrots",
	"item.shears",
	"item.fish.salmon.raw",
	"tile.doublePlant.rose",
	"tile.deadbush",
	"item.appleGold",
	"tile.sponge.dry",
	"tile.sponge.wet",
	"item.boath",
	"tile.dragonEgg",
	"item.netherbrick",
	"item.netherquartz",
	"item.dyePowder.red",
	"item.book"
};

void MurderExpose::OnTick()
{
	if (!Settings::MurderExpose) return;

	for (auto& player : LaunchWrapper::getMinecraft().getWorld().getPlayerList())
	{
		if (JNIHelper::env->IsSameObject(player.GetCurrentObject(), LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject())) continue;

		if (player.getCurrentEquipedItem().getUnlocalizedName() == NULL) continue;
		if (player.getCurrentEquipedItem().getDisplayName() == NULL) continue;

		std::string ItemName = MCHelper::JstringToString(player.getCurrentEquipedItem().getDisplayName());

		if (!ItemName.contains("§a")) continue;

		std::string ItemRealName = MCHelper::JstringToString(player.getCurrentEquipedItem().getUnlocalizedName());

		if (std::find(MurderItems.begin(), MurderItems.end(), ItemRealName) != MurderItems.end())
		{
			std::string DisplayName = MCHelper::JstringToString(player.GetDisplayName());

			Logger::Log(DisplayName + " got detected as Murder");
			ClientConsole::Log(DisplayName + " got detected as Murder");
		}
	}
}