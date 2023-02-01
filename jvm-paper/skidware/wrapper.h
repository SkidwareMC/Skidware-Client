#pragma once
#include <iostream>
#include <Windows.h>
#include "xorstr.hpp"
#include "CKillauraModule.hpp"

namespace out {
	void display(const char* str) {
		std::cout << str << std::endl;
	}
}

namespace misc {
	void thread(void* x) {

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)x, 0, 0, 0);

	}
	void Rclick() {
		SendMessageW(GetForegroundWindow(), WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
		SendMessageW(GetForegroundWindow(), WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
		Sleep(1000 / cps::cps);
	}
	void Lclick() {
		SendMessageW(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
		SendMessageW(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
		Sleep(1000 / cps::cps);
	}
}