#include "Autoclicker.hpp"
#include <Windows.h>
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

int Autoclicker::TickCount = 0;
auto hMcWindow = FindWindow("LWJGL", nullptr);
Autoclicker::Autoclicker() : Module("Autoclicker", NULL, "Clicks for you")
{
}

void Autoclicker::OnTick()
{
	if (Settings::Autoclicker && (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
	{
		if ((Settings::AutoclickerCount - TickCount++) >= 0) LaunchWrapper::getMinecraft().LeftClick();
		if (Settings::BlockHit) {
			SendMessage(hMcWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
			SendMessage(hMcWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
		}
		if (TickCount >= 20) TickCount = 0;
	}

	if (Settings::RightClick && (GetAsyncKeyState(VK_RBUTTON) & 0x8000))
	{
		if ((Settings::RightClickSpeed - TickCount++) >= 0) {
			SendMessage(hMcWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
			SendMessage(hMcWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
		}
		if (TickCount >= 20) TickCount = 0;
	}
}