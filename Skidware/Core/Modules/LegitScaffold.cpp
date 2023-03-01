#include "LegitScaffold.hpp"
#include "../../Wrapper/Logger.hpp"
void KeyDown(int vk, bool bExtended) {

	KEYBDINPUT  kb = { 0 };
	INPUT       Input = { 0 };

	if (bExtended) { kb.dwFlags = KEYEVENTF_EXTENDEDKEY; }
	kb.wVk = vk;
	Input.type = INPUT_KEYBOARD;
	Input.ki = kb;
	SendInput(1, &Input, sizeof(Input));

	return;
}

void KeyUp(int vk, bool bExtended) {

	KEYBDINPUT  kb = { 0 };
	INPUT       Input = { 0 };

	ZeroMemory(&kb, sizeof(KEYBDINPUT));
	ZeroMemory(&Input, sizeof(INPUT));
	kb.dwFlags = KEYEVENTF_KEYUP;
	if (bExtended) { kb.dwFlags |= KEYEVENTF_EXTENDEDKEY; }
	kb.wVk = vk;
	Input.type = INPUT_KEYBOARD;
	Input.ki = kb;
	SendInput(1, &Input, sizeof(Input));
	return;
}

void GenerateKey(int vk, BOOL bExtended) {


	KEYBDINPUT  kb = {
		0
	}
	;
	INPUT       Input = {
		0
	}
	;

	/* Generate a "key down" */
	if (bExtended) {
		kb.dwFlags = KEYEVENTF_EXTENDEDKEY;
	}

	kb.wVk = vk;
	Input.type = INPUT_KEYBOARD;
	Input.ki = kb;
	SendInput(1, &Input, sizeof(Input));

	/* Generate a "key up" */
	ZeroMemory(&kb, sizeof(KEYBDINPUT));
	ZeroMemory(&Input, sizeof(INPUT));
	kb.dwFlags = KEYEVENTF_KEYUP;
	if (bExtended) {
		kb.dwFlags |= KEYEVENTF_EXTENDEDKEY;
	}

	kb.wVk = vk;
	Input.type = INPUT_KEYBOARD;
	Input.ki = kb;
	SendInput(1, &Input, sizeof(Input));

	return;

}

void LegitScaffold::OnTick()
{
	auto hMcWindow = FindWindow(nullptr, "Minecraft 1.8.9");
	timer timere = timer();
	Minecraft mc = LaunchWrapper::getMinecraft();
	LocalPlayer theplayer = mc.getLocalPlayer();
	vector3 temp = vector3(5, 3, 2);//LaunchWrapper::getMinecraft().getLocalPlayer().GetVelocity();
	
	if (!Settings::LegitScaffold) {
		return;
	}
	
	if ((temp.x != 0 && temp.z != 0) && LaunchWrapper::getMinecraft().getWorld().isBlockAir(theplayer.GetPositionX(), theplayer.GetPositionY() - 1.0, theplayer.GetPositionZ())) {
		if (!LaunchWrapper::getMinecraft().getLocalPlayer().isSneaking()) {
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_x(0);
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_z(0);
			Logger::LogDebug("Sneaked");
		}


	}
	else {
		if (LaunchWrapper::getMinecraft().getLocalPlayer().isSneaking()) {

		}
	}
}
