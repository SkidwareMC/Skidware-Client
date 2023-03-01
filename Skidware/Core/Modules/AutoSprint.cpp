#include "AutoSprint.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

void AutoSprint::OnTick()
{
	if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_RSHIFT) & 0x8000) return;
	if (Settings::AutoSprint && ((GetAsyncKeyState('W') & 0x8000) || (GetAsyncKeyState('E') & 0x8000))) LaunchWrapper::getMinecraft().getLocalPlayer().setSprinting(true);
}