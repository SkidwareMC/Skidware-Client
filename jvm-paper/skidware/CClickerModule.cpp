#include "CClickerModule.hpp"

CClickerModule::CClickerModule() : CModule("RClicker", 'O', COMBAT, "Don't use", "RClicker") {

}

void CClickerModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const UpdateEvent*>(event)) {
		long delay = (long)(2000 / f_cps) / 1;;
		

		HWND hwnd = FindWindowA("LWJGL", nullptr);

		bool click = false;

		int cps = 20;

		int cp_seconds = cps * 10;

		if (GetAsyncKeyState(VK_RBUTTON) < 0)
		{

				if (f_cps <= 0)
					return;

				f_cps += m_random;



				POINT pt;
				GetCursorPos(&pt);
				if (FindWindowA(("LWJGL"), nullptr) == GetForegroundWindow()) {
					SendMessageW(GetForegroundWindow(), WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
					SendMessageW(GetForegroundWindow(), WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
					Sleep(rand() % delay); // Sleep Delay Time
				}
				//swingItem();
				// Sleep(delay / 2);
			}
		}
	}


void CClickerModule::renderSettings()
{
	ImGui::Separator();
}

void CClickerModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}

void CClickerModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

