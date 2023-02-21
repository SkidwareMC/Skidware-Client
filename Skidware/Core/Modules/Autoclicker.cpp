#include "Autoclicker.hpp"
#include <Windows.h>
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

int Autoclicker::TickCount = 0;

void Autoclicker::OnTick()
{
	if (Settings::Autoclicker && (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
	{
		if ((Settings::AutoclickerCount - TickCount++) >= 0) LaunchWrapper::getMinecraft().LeftClick();
		if (TickCount >= 20) TickCount = 0;
	}
}