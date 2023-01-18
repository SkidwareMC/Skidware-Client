#include "CClickerModule.hpp"

CClickerModule::CClickerModule() : CModule("Clicker", 'O', COMBAT) {

}

void CClickerModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		long delay = (long)(1000 / (f_cps - 3));

		HWND hwnd = FindWindowA("LWJGL", nullptr);

		bool click = false;

		int cps = 20;

		int cp_seconds = cps * 10;

		if (GetAsyncKeyState(VK_LBUTTON) < 0)
		{

				if (f_cps <= 0)
					return;

				f_cps += m_random;



				POINT pt;
				GetCursorPos(&pt);
				SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
				SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(pt.x, pt.y));
				//swingItem();
				Sleep(delay / 2);
			}
		}
	}


void CClickerModule::renderSettings()
{
	return;
}

void CClickerModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}

void CClickerModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

