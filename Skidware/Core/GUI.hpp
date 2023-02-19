#pragma once
#include <Windows.h>

class GUI
{
private:
	static LRESULT __stdcall patchedWNDPROC(HWND, UINT, WPARAM, LPARAM);
	static void Create();
	static void Render();
	static void RenderMain();
	static void RenderConsole();
	static void RenderInfo();
	static void RenderESP();

public:
	static bool IsInitialized;
	static bool Enabled;
	static void Delete();
	static void OnSwapBuffers(HDC);
};
