#include "includes.h"
#include "machip.h"

long __stdcall machip::hooks::wndproc_hk(const HWND hwnd, unsigned int usermsg, uintptr_t wparam, long lparam)
{
	if (WM_KEYDOWN == usermsg)
		if (wparam == VK_INSERT)
			machip::instance->is_open = !machip::instance->is_open;

	// IMGUI OPEN HERE

	return CallWindowProcA(hooks::original_wndproc, hwnd, usermsg, wparam, lparam);
}