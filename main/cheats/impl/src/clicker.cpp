#include "../headers/clicker.h"
#include "../../../../sdk/minecraft/player/player.h"
void clicker::invoke(std::shared_ptr<c_context> ctx)
{

	long delay = (long)(1000 / (f_cps - 3));

	HWND hwnd = FindWindowA("LWJGL", nullptr);

	bool click = false;

	int cps = 20;

	int cp_seconds = cps * 10;

	if (GetAsyncKeyState(VK_LBUTTON) < 0)
	{
		if (clicker::m_enabled == true)
		{

			if (f_cps <= 0)
				return;

			f_cps += m_random;



			POINT pt;
			GetCursorPos(&pt);
			SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
			//swingItem();
			Sleep(delay / 2 );
		}
	}
}