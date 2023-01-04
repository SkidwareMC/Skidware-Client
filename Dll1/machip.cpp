#include "machip.h"
#include <iostream>
#include "minecraft.h"
#include "player.h"
#include "world.h"
#include "module.h"

// include individual modules
#include "keep_sprint.h"
#include "fastplace.h"
#include "fullbright.h"
#include "antiafk.h"
#include "bunnyhop.h"
#include "killaura.h"
#include "timer_module.h"
#include "velocity.h"
#include "scaffold.h"
#include "nofall.h"
#include "noslowdown.h"
#include "fly.h"
#include "chest_steal.h"
#include "autoclick.h"
#include "autosoup.h"
#include "refill.h"
#include "reach.h"


bool machip::c_machip::attach()
{
	wrapper::output(xorstr_("Attaching started"));

	jsize count;
	if (JNI_GetCreatedJavaVMs(&vm, 1, &count) != JNI_OK || count == 0)
		return false;

	wrapper::output(xorstr_("JVM created"));

	jint res = vm->GetEnv((void**)&env, JNI_VERSION_1_6);

	wrapper::output(xorstr_("JNI env initialised"));

	if (res == JNI_EDETACHED)
		res = vm->AttachCurrentThread((void**)&env, nullptr);

	wrapper::output(xorstr_("Attached to current thread"));

	if (res != JNI_OK)
		return false;

	sdk::instance = std::make_unique<sdk::c_minecraft>();
	modules::instance = std::make_unique<modules::c_modules>();

	hook();

	is_running = true;

	wrapper::output(xorstr_("Attaching finished"));

	return true;
}

void machip::c_machip::run()
{

	modules::instance->create(keep_sprint::invoke);
	modules::instance->create(fastplace::invoke);
	modules::instance->create(fullbright::invoke);
	modules::instance->create(antiafk::invoke);
	modules::instance->create(bunnyhop::invoke);
	modules::instance->create(killaura::invoke);
	modules::instance->create(timer::invoke);
	modules::instance->create(velocity::invoke);
	modules::instance->create(scaffold::invoke);
	modules::instance->create(nofall::invoke);
	modules::instance->create(noslowdown::invoke);
	modules::instance->create(fly::invoke);
	modules::instance->create(chest_steal::invoke);
	modules::instance->create(autoclick::invoke);
	modules::instance->create(autosoup::invoke);
	modules::instance->create(refill::invoke);
	modules::instance->create(reach::invoke);

	modules::instance->create_reset(bunnyhop::reset);
	modules::instance->create_reset(timer::reset);

	bool first = true;

	while (is_running)
	{
		if (first)
		{
			wrapper::output(xorstr_("Injection concluded"));

			std::this_thread::sleep_for(std::chrono::milliseconds(500));

#if DEBUG
			wrapper::clear();
#else
			FreeConsole();
			fclose(stdout);
#endif

			first = false;
		}

		if (wrapper::get_keystate(VK_END))
			is_running = false;

		if (wrapper::get_keystate(VK_HOME))
			bunnyhop::m_enabled = !bunnyhop::m_enabled;

		if (wrapper::get_keystate(VK_INSERT)) {
			reach::m_enabled = !reach::m_enabled;
			wrapper::output("switch: " + std::to_string(reach::m_enabled));
		}

		if (wrapper::get_keystate(VK_F10))
		{
			killaura::m_enabled = !killaura::m_enabled;
			wrapper::output("switch killaura! " + std::to_string(killaura::m_enabled));
		}

		if (wrapper::get_keystate(VK_F8))
		{
			chest_steal::m_enabled = !chest_steal::m_enabled;
			wrapper::output("switch chest steal! " + std::to_string(chest_steal::m_enabled));
		}

		if (!is_running)
		{
			auto minecraft_inst = sdk::instance->get_minecraft();
			auto local = std::make_shared<c_player>(sdk::instance->get_player(minecraft_inst));
			auto world = std::make_shared<c_world>(sdk::instance->get_world(minecraft_inst));
			modules::instance->reset(std::make_shared<c_context>(local, world, !sdk::instance->get_current_screen(minecraft_inst)));
			get_env()->DeleteLocalRef(minecraft_inst);
			break;
		}

		if (!sdk::instance->hasTick)
		{
			/*if (machip::instance->timer->has_passed(200))
			{
				machip::hooks::jhooks::rehook_tick();
				machip::instance->timer->reset();
			}*/
			continue;
		}

		machip::instance->timer->reset();
		sdk::instance->hasTick = false;

		auto minecraft_inst = sdk::instance->get_minecraft();
		auto local = std::make_shared<c_player>(sdk::instance->get_player(minecraft_inst));
		auto world = std::make_shared<c_world>(sdk::instance->get_world(minecraft_inst));

		modules::instance->invoke(std::make_shared<c_context>(local, world, !sdk::instance->get_current_screen(minecraft_inst)));

		get_env()->DeleteLocalRef(minecraft_inst);

	}
}

void machip::c_machip::destroy()
{
	wrapper::clear();
	wrapper::output(xorstr_("Uninjecting..."));
	std::this_thread::sleep_for(std::chrono::seconds(1));

	SetWindowLongPtrA(FindWindow("LWJGL", nullptr), GWLP_WNDPROC, (LONG_PTR)hooks::original_wndproc);

	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	get_vm()->DetachCurrentThread();

#if DEBUG
	FreeConsole();
	fclose(stdout);
#endif
}

void machip::c_machip::hook()
{
	wrapper::output(xorstr_("Starting hooks"));

	MH_Initialize();

	// auto swap_buffers_ptr = wrapper::get_proc_address(xorstr_("SwapBuffers"), wrapper::get_module_handle(xorstr_("Gdi32.dll")));

	// MH_CreateHook(swap_buffers_ptr, hooks::swap_buffers_hk, reinterpret_cast<void**>(&hooks::oswap_buffers));
	// MH_EnableHook(MH_ALL_HOOKS);

	// wrapper::output(xorstr_("Hooked Swapbuffers"));

	hooks::original_wndproc = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(wrapper::find_window(), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hooks::wndproc_hk)));

	wrapper::output(xorstr_("WindowProc set"));

	wrapper::output(xorstr_("Setting up jhooks"));
	hooks::jhooks::apply_jtickhook();
	hooks::jhooks::apply_moveEntityHook();
	//hooks::jhooks::apply_jreachhook();

	wrapper::output(xorstr_("Hooks finished"));
}

std::unique_ptr<machip::c_machip> machip::instance;