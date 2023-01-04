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


#include "includes.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_opengl2.h"


bool machip::c_machip::attach()
{
	wrapper::output(xorstr_("Attaching started"));
	Sleep(1500);
	jsize count;
	if (JNI_GetCreatedJavaVMs(&vm, 1, &count) != JNI_OK || count == 0)
		return false;

	wrapper::output(xorstr_("JVM created"));
	Sleep(2000);

	jint res = vm->GetEnv((void**)&env, JNI_VERSION_1_6);

	wrapper::output(xorstr_("JNI env initialised"));

	if (res == JNI_EDETACHED)
		res = vm->AttachCurrentThread((void**)&env, nullptr);

	wrapper::output(xorstr_("Attached to current thread"));
	Sleep(1000);

	if (res != JNI_OK)
		return false;

	sdk::instance = std::make_unique<sdk::c_minecraft>();
	modules::instance = std::make_unique<modules::c_modules>();

	hook();

	is_running = true;

	wrapper::output(xorstr_("Attaching finished"));
	Sleep(1000);

	return true;
}

void machip::c_machip::run()
{
	wrapper::output(xorstr_("Creating Cheats..."));
	modules::instance->create(keep_sprint::invoke);
	wrapper::output(xorstr_("KeepSprint"));
	Sleep(500);
	modules::instance->create(fastplace::invoke);
	wrapper::output(xorstr_("Fastplace"));
	Sleep(500);
	modules::instance->create(fullbright::invoke);
	wrapper::output(xorstr_("Fullbright"));
	Sleep(500);
	modules::instance->create(antiafk::invoke);
	wrapper::output(xorstr_("AntiAfk"));
	Sleep(500);
	modules::instance->create(bunnyhop::invoke);
	wrapper::output(xorstr_("BHop"));
	Sleep(500);
	modules::instance->create(killaura::invoke);
	wrapper::output(xorstr_("Killaura (broken)"));
	Sleep(500);
	modules::instance->create(timer::invoke);
	wrapper::output(xorstr_("Timer"));
	Sleep(500);
	modules::instance->create(velocity::invoke);
	wrapper::output(xorstr_("Velocity"));
	Sleep(500);
	modules::instance->create(scaffold::invoke);
	wrapper::output(xorstr_("Scaffold"));
	Sleep(500);
	modules::instance->create(nofall::invoke);
	wrapper::output(xorstr_("NoFall"));
	Sleep(500);
	modules::instance->create(noslowdown::invoke);
	wrapper::output(xorstr_("NoSlow"));
	Sleep(500);
	modules::instance->create(fly::invoke);
	wrapper::output(xorstr_("Fly"));
	Sleep(500);
	modules::instance->create(chest_steal::invoke);
	wrapper::output(xorstr_("Stealer"));
	Sleep(500);
	modules::instance->create(autoclick::invoke);
	wrapper::output(xorstr_("Autoclicker"));
	Sleep(500);
	modules::instance->create(autosoup::invoke);
	wrapper::output(xorstr_("AutoPot"));
	Sleep(500);
	modules::instance->create(refill::invoke);
	wrapper::output(xorstr_("Refill"));
	Sleep(500);
	modules::instance->create(reach::invoke);
	wrapper::output(xorstr_("Reach"));
	Sleep(3000);

	wrapper::output(xorstr_("Creating resets..."));
	modules::instance->create_reset(bunnyhop::reset);
	wrapper::output(xorstr_("BHop"));
	Sleep(500);
	modules::instance->create_reset(timer::reset);
	wrapper::output(xorstr_("Timer"));
	Sleep(500);
	Sleep(3000);

	wrapper::output(xorstr_("Finding window..."));
	Sleep(500);
	//ImGui Setup
	static auto mc_window = wrapper::find_window();
	auto window_rect = wrapper::get_rect();

	wrapper::output(xorstr_("Creating ImGui Context"));
	Sleep(500);
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(mc_window);
	ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark();

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
#endif

			first = false;
		}

		if (GetAsyncKeyState(VK_RSHIFT))
			machip::instance->is_open = !machip::instance->is_open;

		if (machip::instance->is_open) 
		{

			ImGuiIO& io = ImGui::GetIO();
			io.MouseDrawCursor = true;
			
			ImGui::Begin(xorstr_("Skidware b0.2 - 1.8.9"), NULL);
			ImGui::Separator();
			bunnyhop::renderSets();
			ImGui::Separator();
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();

			ImGui::Render();

			glViewport(0, 0, window_rect.right, window_rect.top);
			ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
		}

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDrawCursor = false;

		/*
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
		*/

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