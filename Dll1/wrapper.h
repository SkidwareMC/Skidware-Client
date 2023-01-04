#pragma once

#include <iostream>

namespace wrapper 
{
	inline void output(std::string msg)
	{
		std::cout << msg << std::endl;
		Sleep(10);
	}

	inline HANDLE create_thread(LPTHREAD_START_ROUTINE routine) 
	{
		return CreateThread(0, 0, routine, 0, 0, 0);
	}

	const inline void show_message(std::string msg) 
	{
		MessageBoxA(nullptr, msg.c_str(), xorstr_("Error"), MB_OK);
	}

	inline void* get_module_handle(const char* name) 
	{
		auto h_module = GetModuleHandleA(name);

		if (h_module == nullptr)
			std::exit(0);

		return h_module;
	}

	inline HWND find_window()
	{
		auto res = FindWindowA("LWJGL", nullptr);

		if (res == nullptr)
			std::exit(0);

		return res;
	}

	inline RECT get_rect()
	{
		RECT res;
		GetWindowRect(find_window(), &res);

		return res;
	}

	inline void* get_proc_address(const char* name, void* handle)
	{
		auto p_procedure = GetProcAddress(reinterpret_cast<HMODULE>(handle), name);

		if (p_procedure == nullptr)
			std::exit(0);

		return p_procedure;
	}

	inline short get_keystate(int key)
	{
		return GetAsyncKeyState(key) & 0x8000;
	}

	inline void clear() 
	{
		COORD topLeft = { 0, 0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;

		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(
			console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		FillConsoleOutputAttribute(
			console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		SetConsoleCursorPosition(console, topLeft);
	}

	struct c_context 
	{
		HDC m_hdc_devicectx;
		HGLRC m_glrenderctx;
		HGLRC m_oglrenderctx;
	};
}