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
#include "../../../Skidware-Client-main/Skidware-Client-main/sdk/libraries/imgui/imgui.h"
#include "../../../Skidware-Client-main/Skidware-Client-main/sdk/libraries/imgui/imgui_impl_win32.h"
#include "../../../Skidware-Client-main/Skidware-Client-main/sdk/libraries/imgui/imgui_impl_opengl2.h"

jvmtiEnv* jvmti_env;

bool machip::c_machip::attach()
{

	wrapper::output(xorstr_("Attaching started"));

	auto jvm_dll = wrapper::get_module_handle(xorstr_("jvm.dll"));

	auto created_java_vms = reinterpret_cast<sdk::t_createdvms>(wrapper::get_proc_address(xorstr_("JNI_GetCreatedJavaVMs"), jvm_dll));

	auto ret = created_java_vms(&vm, 1, nullptr);

	wrapper::output(xorstr_("JVM created"));

	if (ret != JNI_OK)
		return false;

	ret = get_vm()->AttachCurrentThread(reinterpret_cast<void**>(&env), nullptr);

	wrapper::output(xorstr_("JNI env initialised"));

	wrapper::output(xorstr_("Attached to current thread"));

	if (ret != JNI_OK)
		return false;

	get_vm()->GetEnv(reinterpret_cast<void**>(&jvmti_env), JVMTI_VERSION_1_1);

	if (!jvmti_env)
		return false;

	/// Get the launchwrapper instance so that we can use findClass
	//get_launchwrapper();

	/// Hook our shizzle
	hook();

	/// Now we can begin business
	is_running = true;

	wrapper::output(xorstr_("Attaching finished"));

	return true;
}

void machip::c_machip::run()
{

	// Spawn an instance of our SDK
	sdk::instance = std::make_unique<sdk::c_minecraft>();

	/// Spawn an instance of our "cheats"
	modules::instance = std::make_unique<modules::c_modules>();

	// Register all our cheats
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

	// Other things idek
	modules::instance->create_reset(bunnyhop::reset);
	modules::instance->create_reset(timer::reset);

	//Give it a console for debugging purposes
	AllocConsole();

	//Allow you to close the console without the host process closing too
	SetConsoleCtrlHandler(NULL, true);
	//Assign console in and out to pass to the create console rather than minecraft's
	FILE* fIn;
	FILE* fOut;
	freopen_s(&fIn, "conin$", "r", stdin);
	freopen_s(&fOut, "conout$", "w", stdout);
	freopen_s(&fOut, "conout$", "w", stderr);

	while (is_running)
	{
		/// "Self-destruct" button
		if (wrapper::get_keystate(VK_HOME))
			is_running = false;

		/// Le epic flag for le epic modern C++
		static std::once_flag flag;

		/// Keep references simple so that we can easily dispose of them later (they're all localref btw)
		/// but they last for one cycle of this thread so we shouldn't worry about them being accidentally destroyed suddenly
		auto minecraft_inst = sdk::instance->get_minecraft();

		/// Notify of injection (this is for testing)
		/// Note to self: release mode currently contains pretty much the same debug info as debug config
		/// so if you want to sell this piece of shit you better change that or else you'll get crackalacked in a minute
		std::call_once(flag, [&]() { wrapper::show_message(xorstr_("Injected.")); });


		/// NOTE: the player and world class already dispose of the references themselves
		auto local = std::make_shared<c_player>(sdk::instance->get_player(minecraft_inst));
		auto world = std::make_shared<c_world>(sdk::instance->get_world(minecraft_inst));
		modules::instance->invoke(std::make_shared<c_context>(local, world, !sdk::instance->get_current_screen(minecraft_inst), false));


		/// Delete the reference
		get_env()->DeleteLocalRef(minecraft_inst);
		
		/// Let's save the CPU some processing powerz
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	if (!is_running)
	{
		auto minecraft_inst = sdk::instance->get_minecraft();
		auto local = std::make_shared<c_player>(sdk::instance->get_player(minecraft_inst));
		auto world = std::make_shared<c_world>(sdk::instance->get_world(minecraft_inst));
		modules::instance->reset(std::make_shared<c_context>(local, world, !sdk::instance->get_current_screen(minecraft_inst)));
		get_env()->DeleteLocalRef(minecraft_inst);
	}

	machip::instance->timer->reset();
	sdk::instance->hasTick = false;

}

// This is called when we're supposed to dispose of our mineman hackery
void machip::c_machip::dispose()
{
	get_env()->DeleteGlobalRef(classloader_obj);
	get_vm()->DetachCurrentThread();

	wrapper::output(xorstr_("Uninjecting..."));

	ImGui_ImplOpenGL2_Shutdown();
	wglDeleteContext(hooks::gl_context->m_glrenderctx);
	ImGui::DestroyContext();
	ImGui_ImplWin32_Shutdown();

	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	SetWindowLongPtrA(wrapper::find_window(xorstr_("Minecraft 1.8.9")), GWLP_WNDPROC, (LONG_PTR)hooks::original_wndproc);
	//std::cout << "[Test] WindowProc set" << std::endl;
	//Sleep(1000);
	//std::cout << "[Test] Injected :)" << std::endl;

	env = nullptr;
	hooks::gl_context = nullptr;
	vm = nullptr;

#if DEBUG
	FreeConsole();
	fclose(stdout);
#endif
}

void machip::c_machip::get_launchwrapper()
{
	jclass launchwrapper_cls = get_env()->FindClass(xorstr_("net/minecraft/launchwrapper/LaunchClassLoader"));
	jclass launch_cls = get_env()->FindClass(xorstr_("net/minecraft/launchwrapper/Launch"));

	if (wrapper::handle_issue(xorstr_("launchwrapper"), launchwrapper_cls) ||
		wrapper::handle_issue(xorstr_("launch_cls"), launch_cls))
		std::exit(0);

	auto classloader_fid = get_env()->GetStaticFieldID(launch_cls, xorstr_("classLoader"), xorstr_("Lnet/minecraft/launchwrapper/LaunchClassLoader;"));

	findclass_md = get_env()->GetMethodID(launchwrapper_cls, xorstr_("findClass"), xorstr_("(Ljava/lang/String;)Ljava/lang/Class;"));
	classloader_obj = get_env()->NewGlobalRef(get_env()->GetStaticObjectField(launch_cls, classloader_fid));

	get_env()->DeleteLocalRef(launchwrapper_cls);
	get_env()->DeleteLocalRef(launch_cls);
}

void machip::c_machip::hook()
{

	wrapper::output(xorstr_("Starting hooks"));
	
	MH_Initialize();

	auto swap_buffers_ptr = wrapper::get_proc_address(xorstr_("SwapBuffers"), wrapper::get_module_handle(xorstr_("Gdi32.dll")));

	MH_CreateHook(swap_buffers_ptr, hooks::swap_buffers_hk, reinterpret_cast<void**>(&hooks::oswap_buffers));
	MH_EnableHook(MH_ALL_HOOKS);
	
	wrapper::output(xorstr_("Hooked Swapbuffers"));

	/// Set the WndProc
	hooks::original_wndproc = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(wrapper::find_window(xorstr_("Minecraft 1.8.9")), GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(hooks::wndproc_hk)));
	
	wrapper::output(xorstr_("WindowProc set"));

	hooks::jhooks::apply_jtickhook();
	hooks::jhooks::apply_moveEntityHook();
	hooks::jhooks::apply_jreachhook();

	wrapper::output(xorstr_("Hooks finished"));

}

std::unique_ptr<machip::c_machip> machip::instance;