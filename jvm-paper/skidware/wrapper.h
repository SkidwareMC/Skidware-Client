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

float randf(float lo, float hi) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = hi - lo;
	float r = random * diff;
	return lo + r;
}
int randi(int lo, int hi)
{
	int n = hi - lo + 1;
	int i = rand() % n;
	if (i < 0) i = -i;
	return lo + i;
}

namespace misc {
	float yaw, pitch;
	void thread(void* x) {

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)x, 0, 0, 0);

	}
	void Rclick() {
		HWND minecraftWindow = FindWindowA("LWJGL", nullptr);
		SendMessageW(minecraftWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
		SendMessageW(minecraftWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
		Sleep(1000 / cps::cps);
	}
	void Lclick() {
		HWND minecraftWindow = FindWindowA("LWJGL", nullptr);
		SendMessageW(minecraftWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
		SendMessageW(minecraftWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
		Sleep(1000 / cps::cps);
	}	
	void PlaceBlock() {
		HWND minecraftWindow = FindWindowA("LWJGL", nullptr);
		SendMessageW(minecraftWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
		SendMessageW(minecraftWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
		Sleep(1000 / 15 + (randi(-2, 3)));
	}
	void auraRotate() {

		CMinecraft* mc = CCheat::theMinecraft;
		yaw = mc->thePlayer->rotationYaw;
		pitch = mc->thePlayer->rotationPitch;
		mc->thePlayer->rotationPitch = 0;
		mc->thePlayer->rotationYaw = 90;
		misc::thread(misc::Lclick);
		Sleep(10);
		mc->thePlayer->rotationPitch = pitch;
		mc->thePlayer->rotationYaw = yaw;
	}
	void silentRotate(float yaw) {
		CMinecraft* mc = CCheat::theMinecraft;
		mc->thePlayer->headRotationYaw = yaw;
	}
	inline short get_keystate(int key)
	{
		return GetAsyncKeyState(key) & 0x8000;
	}


}