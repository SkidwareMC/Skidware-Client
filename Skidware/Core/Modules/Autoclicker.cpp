#include "Autoclicker.hpp"
#include <Windows.h>
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"
#include <random>

int Autoclicker::TickCount = 0;

int rand_range(int min_n, int max_n)
{
	return rand() % (max_n - min_n + 1) + min_n;
}

void click() {
	HWND mcWindow = FindWindowA("LWJGL", NULL);
	SendMessageW(mcWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0)); SendMessageW(mcWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
}

void Autoclicker::OnTick()
{
	
	if (Settings::Autoclicker && (GetAsyncKeyState(VK_LBUTTON) & 0x8000))
	{
		
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)click, 0, 0, 0); 
		
		// Sleep(1000 / (Settings::AutoclickerCount + rand_range(-1, -2)));
		TickCount++;
	}
}

