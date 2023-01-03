#pragma once

#include "../includes.h"

namespace machip 
{
	class c_machip 
	{
	private:
		JNIEnv* env;
		JavaVM* vm;

		jmethodID findclass_md;
		jobject classloader_obj;
	public:
		bool is_running;
		bool is_open = false;

		std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();

		bool attach();
		void run();
		void hook();
		void get_launchwrapper();
		void dispose();

		const auto get_env() 
		{
			return env;
		}

		const auto get_vm() 
		{
			return vm;
		}
	};

	namespace hooks 
	{
		// Function template of SwapBuffers
		using swap_buffers_fn = int(__stdcall*)(HDC);

		// Store pointer to the original SwapBuffers function
		inline swap_buffers_fn oswap_buffers = nullptr;

		// Simple glcontext wrapper to make life easy
		extern std::shared_ptr<wrapper::c_context> gl_context;

		// The actual hook
		int __stdcall swap_buffers_hk(HDC);

		// Original WndProc of the Window we're hooking
		inline WNDPROC original_wndproc = nullptr;

		// Actual "hook", this really isn't a hook but it's whatever
		long __stdcall wndproc_hk(const HWND hwnd, unsigned int usermsg, uintptr_t wparam, long lparam);

		namespace jhooks
		{
			bool apply_jtickhook(bool create = true);
			void rehook_tick();
			bool apply_moveEntityHook();
			bool apply_jreachhook();
		}
	}

	extern std::unique_ptr<c_machip> instance;
}
