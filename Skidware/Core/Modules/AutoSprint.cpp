#include "AutoSprint.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

void AutoSprint::OnTick()
{
	if (Settings::AutoSprint && ((GetAsyncKeyState('W') & 0x8000) || (GetAsyncKeyState('E') & 0x8000))) LaunchWrapper::getMinecraft().getLocalPlayer().setSprinting(true);
}