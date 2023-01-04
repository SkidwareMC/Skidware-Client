#pragma once

#include "includes.h"

namespace machip 
{
	class c_machip 
	{
	private:
		JNIEnv* env;
		JavaVM* vm;
	public:
		bool is_running;
		bool is_open = false;

		std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();

		bool attach();
		void run();
		void destroy();
		void hook();

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
		using swap_buffers_fn = int(__stdcall*)(HDC);
		inline swap_buffers_fn oswap_buffers = nullptr;
		extern std::shared_ptr<wrapper::c_context> gl_context;
		int __stdcall swap_buffers_hk(HDC);
		inline WNDPROC original_wndproc = nullptr;
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
