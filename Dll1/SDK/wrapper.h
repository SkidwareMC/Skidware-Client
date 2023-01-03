#pragma once

#include <iostream>

namespace wrapper 
{

	/// Simple wrapper for CreateThread
	inline HANDLE create_thread(LPTHREAD_START_ROUTINE routine)
	{
		return CreateThread(0, 0, routine, 0, 0, 0);
	}

	inline void output(std::string msg)
	{
		std::cout << msg << std::endl;
		Sleep(10);
	}

	const inline void show_message(std::string msg) 
	{
		MessageBoxA(nullptr, msg.c_str(), xorstr_("Error"), MB_OK);
	}

	/// Simple wrapper to handle issues
	const inline bool handle_issue(const char* name, void* ptr)
	{
		/// Constant formatting message
		const auto s_formatting = xorstr_("%s not intialized, value -> 0x%X");

		/// Value isn't initialized
		if (!ptr)
		{
			size_t len = std::snprintf(nullptr, 0, s_formatting, name, ptr) + 1; /// Had issues with terminator

			if (len <= 0)
				show_message(xorstr_("Issue formatting issue_handler wrapper::#handle_issue#26"));

			/// Allocate buffer with lenght of message 
			auto buffer = std::make_unique<char[]>(len);

			/// Format the message to buffer
			std::snprintf(buffer.get(), len, s_formatting, name, ptr);

			/// Show the message
			show_message(std::string(buffer.get(), buffer.get() + len - 1));

			/// Show that an issue occured
			return true;
		}

		/// Everything gucci
		return false;
	}

	inline void* get_module_handle(const char* name) 
	{
		auto h_module = GetModuleHandleA(name);

		if (h_module == nullptr)
			std::exit(0);

		return h_module;
	}

	inline HWND find_window(const char* name)
	{
		auto res = FindWindowA("LWJGL", nullptr);

		if (handle_issue(name, res))
			std::exit(0);

		return res;
	}

	inline RECT get_window_rect(const char* name)
	{
		RECT res;
		GetWindowRect(find_window(name), &res);

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

	inline std::shared_ptr<c_context> create_gl_context()
	{
		std::shared_ptr<c_context> res = std::make_shared<c_context>();

		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
		};

		res->m_hdc_devicectx = GetDC(find_window(xorstr_("Minecraft 1.8.9")));

		int pixel_format = ChoosePixelFormat(res->m_hdc_devicectx, &pfd);
		SetPixelFormat(res->m_hdc_devicectx, pixel_format, &pfd);

		res->m_oglrenderctx = wglGetCurrentContext();
		res->m_glrenderctx = wglCreateContext(res->m_hdc_devicectx);
		return res;
	}
}