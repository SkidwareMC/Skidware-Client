#include "CCheat.hpp"
#include "CModuleManager.hpp"
#include "CClickGUIModule.hpp"
#include "wrapper.h"

namespace ImGui {
	void setColors() {
		ImColor mainColor = ImColor(int(15), int(135), int(105), 255);
		ImColor bodyColor = ImColor(int(24), int(24), int(24), 255);
		ImColor fontColor = ImColor(int(255), int(255), int(255), 255);

		ImGuiStyle& style = ImGui::GetStyle();

		ImVec4 mainColorHovered = ImVec4(mainColor.Value.x + 0.1f, mainColor.Value.y + 0.1f, mainColor.Value.z + 0.1f, mainColor.Value.w);
		ImVec4 mainColorActive = ImVec4(mainColor.Value.x + 0.2f, mainColor.Value.y + 0.2f, mainColor.Value.z + 0.2f, mainColor.Value.w);
		ImVec4 menubarColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w - 0.8f);
		ImVec4 frameBgColor = ImVec4(bodyColor.Value.x + 0.1f, bodyColor.Value.y + 0.1f, bodyColor.Value.z + 0.1f, bodyColor.Value.w + .1f);
		ImVec4 tooltipBgColor = ImVec4(bodyColor.Value.x, bodyColor.Value.y, bodyColor.Value.z, bodyColor.Value.w + .05f);

		style.Alpha = 1.0f;
		style.WindowPadding = ImVec2(8, 8);
		style.WindowMinSize = ImVec2(32, 32);
		style.WindowRounding = 0.0f;
		style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style.ChildRounding = 0.0f;
		style.FramePadding = ImVec2(4, 3);
		style.FrameRounding = 2.0f;
		style.ItemSpacing = ImVec2(4, 3);
		style.ItemInnerSpacing = ImVec2(4, 4);
		style.TouchExtraPadding = ImVec2(0, 0);
		style.IndentSpacing = 21.0f;
		style.ColumnsMinSpacing = 3.0f;
		style.ScrollbarSize = 8.f;
		style.ScrollbarRounding = 0.0f;
		style.GrabMinSize = 1.0f;
		style.GrabRounding = 0.0f;
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
		style.DisplayWindowPadding = ImVec2(22, 22);
		style.DisplaySafeAreaPadding = ImVec2(4, 4);
		style.AntiAliasedLines = true;
		style.CurveTessellationTol = 1.25f;

		style.Colors[ImGuiCol_Text] = fontColor;

		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style.Colors[ImGuiCol_WindowBg] = bodyColor;
		style.Colors[ImGuiCol_ChildBg] = ImVec4(.0f, .0f, .0f, .0f);
		style.Colors[ImGuiCol_PopupBg] = tooltipBgColor;
		style.Colors[ImGuiCol_Border] = ImColor(200, 200, 200, 220);
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		style.Colors[ImGuiCol_FrameBg] = frameBgColor;
		style.Colors[ImGuiCol_FrameBgHovered] = mainColorHovered;
		style.Colors[ImGuiCol_FrameBgActive] = mainColorActive;
		style.Colors[ImGuiCol_TitleBg] = mainColor;
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		style.Colors[ImGuiCol_TitleBgActive] = mainColor;
		style.Colors[ImGuiCol_MenuBarBg] = menubarColor;
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(frameBgColor.x + .05f, frameBgColor.y + .05f, frameBgColor.z + .05f, frameBgColor.w);
		style.Colors[ImGuiCol_ScrollbarGrab] = mainColor;
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = mainColorHovered;
		style.Colors[ImGuiCol_ScrollbarGrabActive] = mainColorActive;
		style.Colors[ImGuiCol_CheckMark] = mainColor;
		style.Colors[ImGuiCol_SliderGrab] = mainColorHovered;
		style.Colors[ImGuiCol_SliderGrabActive] = mainColorActive;
		style.Colors[ImGuiCol_Button] = mainColor;
		style.Colors[ImGuiCol_ButtonHovered] = mainColorHovered;
		style.Colors[ImGuiCol_ButtonActive] = mainColorActive;
		style.Colors[ImGuiCol_Header] = mainColor;
		style.Colors[ImGuiCol_HeaderHovered] = mainColorHovered;
		style.Colors[ImGuiCol_HeaderActive] = mainColorActive;


		style.Colors[ImGuiCol_ResizeGrip] = mainColor;
		style.Colors[ImGuiCol_ResizeGripHovered] = mainColorHovered;
		style.Colors[ImGuiCol_ResizeGripActive] = mainColorActive;
		style.Colors[ImGuiCol_PlotLines] = mainColor;
		style.Colors[ImGuiCol_PlotLinesHovered] = mainColorHovered;
		style.Colors[ImGuiCol_PlotHistogram] = mainColor;
		style.Colors[ImGuiCol_PlotHistogramHovered] = mainColorHovered;
		style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
		style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
	}
	LRESULT wndproc(const HWND a1, unsigned int a2, unsigned long long a3, long a4) {
		ImGuiIO& io = ImGui::GetIO();
		switch (a3) {
		case WM_LBUTTONDOWN:
			io.MouseDown[0] = true;
			return true;
		case WM_LBUTTONUP:
			io.MouseDown[0] = false;
			return true;
		case WM_RBUTTONDOWN:
			io.MouseDown[1] = true;
			return true;
		case WM_RBUTTONUP:
			io.MouseDown[1] = false;
			return true;
		case WM_MBUTTONDOWN:
			io.MouseDown[2] = true;
			return true;
		case WM_MBUTTONUP:
			io.MouseDown[2] = false;
			return true;
		case WM_XBUTTONDOWN:
			if ((GET_KEYSTATE_WPARAM(a3) & MK_XBUTTON1) == MK_XBUTTON1)
				io.MouseDown[3] = true;
			else if ((GET_KEYSTATE_WPARAM(a3) & MK_XBUTTON2) == MK_XBUTTON2)
				io.MouseDown[4] = true;
			return true;
		case WM_XBUTTONUP:
			if ((GET_KEYSTATE_WPARAM(a3) & MK_XBUTTON1) == MK_XBUTTON1)
				io.MouseDown[3] = false;
			else if ((GET_KEYSTATE_WPARAM(a3) & MK_XBUTTON2) == MK_XBUTTON2)
				io.MouseDown[4] = false;
			return true;
		case WM_MOUSEWHEEL:
			io.MouseWheel += GET_WHEEL_DELTA_WPARAM(a3) > 0 ? +1.0f : -1.0f;
			return true;
		case WM_MOUSEMOVE:
			io.MousePos.x = (signed short)(a4);
			io.MousePos.y = (signed short)(a4 >> 16);
			return true;
		case WM_KEYDOWN:
			if (a3 < 256)
				io.KeysDown[a3] = 1;
			return true;
		case WM_KEYUP:
			if (a3 < 256)
				io.KeysDown[a3] = 0;
			return true;
		case WM_CHAR:
			if (a3 > 0 && a3 < 0x10000)
				io.AddInputCharacter((unsigned short)a3);
			return true;
		}
		return 0;
	}
} //namespace ImGui

WNDPROC ORIG_wndproc;

extern IMGUI_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

long __stdcall HOOKED_wndproc(const HWND a1, unsigned int a2, unsigned long long a3, long a4) {
	if (a2 == WM_KEYDOWN) {
		unsigned long long new_a3 = a3;
		unsigned int scancode = (a4 & 0x00ff0000) >> 16;
		bool extended = (a4 & 0x01000000 /* EXTENDED_KEYMASK */) != 0;
		if (a3 == VK_SHIFT) new_a3 = MapVirtualKey(scancode, MAPVK_VSC_TO_VK_EX);
		if (a3 == VK_MENU) if (extended) new_a3 = VK_RMENU;
		if (a3 == VK_CONTROL) if (extended) new_a3 = VK_RCONTROL;
		for (CModule* module : CCheat::moduleManager->modules) {
			if (new_a3 == module->keyBind || a4 == module->keyBind) module->toggle();
		}
	}

	if (CCheat::moduleManager->getModule<CClickGUIModule>()->state && ImGui_ImplWin32_WndProcHandler(a1, a2, a3, a4) && ImGui::wndproc(a1, a2, a3, a4))
		return true;
	
	if (a3 == VK_ESCAPE && CCheat::moduleManager->getModule<CClickGUIModule>()->state) CCheat::moduleManager->getModule<CClickGUIModule>()->toggle();

	return CallWindowProcA(ORIG_wndproc, a1, a2, a3, a4);
}

bool firstRun = true;

typedef int(__stdcall* _wglSwapBuffers)(HDC);
_wglSwapBuffers ORIG_wglSwapBuffers;

JNIEnv* swapBuffers_env;

int __stdcall HOOKED_wglSwapBuffers(HDC a1) {
	if (swapBuffers_env == nullptr) {
		CCheat::getInstance()->javavm->AttachCurrentThread(reinterpret_cast<void**>(&swapBuffers_env), nullptr);
	}
	//if (CCheat::theMinecraft->fontRendererObj == nullptr) {
		CIntelligentMappedClass minecraftClass = CIntelligentMappings::getClass("net.minecraft.client.Minecraft");
		CIntelligentMappedField fontRendererField = minecraftClass.getField("fontRenderer");
		jclass minecraftKlass = swapBuffers_env->FindClass(minecraftClass.name().data());
		while (!minecraftKlass) minecraftKlass = swapBuffers_env->FindClass(minecraftClass.name().data());
		jmethodID getMinecraft = swapBuffers_env->GetStaticMethodID(minecraftKlass, minecraftClass.getMethod("getMinecraft").name().data(), minecraftClass.getMethod("getMinecraft").signature().data());
		while (!getMinecraft) getMinecraft = swapBuffers_env->GetStaticMethodID(minecraftKlass, minecraftClass.getMethod("getMinecraft").name().data(), minecraftClass.getMethod("getMinecraft").signature().data());
		jobject minecraft = swapBuffers_env->CallStaticObjectMethod(minecraftKlass, getMinecraft);
		while (!minecraft) minecraft = swapBuffers_env->CallStaticObjectMethod(minecraftKlass, getMinecraft);
		jfieldID fontRendererFD = swapBuffers_env->GetFieldID(minecraftKlass, minecraftClass.getField("fontRenderer").name().data(),
			minecraftClass.getField("fontRenderer").signature().data());
		while (!fontRendererFD) fontRendererFD = swapBuffers_env->GetFieldID(minecraftKlass, minecraftClass.getField("fontRenderer").name().data(),
			minecraftClass.getField("fontRenderer").signature().data());
		jobject a = swapBuffers_env->GetObjectField(minecraft, fontRendererFD);
		while (!a) a = swapBuffers_env->GetObjectField(minecraft, fontRendererFD);
		if (a) {
			CCheat::theMinecraft->fontRendererObj = new MinecraftFontRenderer(a, swapBuffers_env);
		}
	//}
	if (firstRun) {
		HWND minecraftWindow = FindWindowA("LWJGL", nullptr);
		
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::setColors();
		ImGui_ImplWin32_Init(minecraftWindow);
		ImGui_ImplOpenGL2_Init();
		
		firstRun = false;

		return ORIG_wglSwapBuffers(a1);
	}

	CFontRenderer fontRenderer;
	if (a1 != fontRenderer.fontHDC || !fontRenderer.builtFonts) {
		fontRenderer.setup();
	}
	CCheat::theMinecraft->fontRenderer = &fontRenderer;

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushMatrix();
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glViewport(0, 0, viewport[2], viewport[3]);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_DEPTH_TEST);

	/*for (CModule* module : CCheat::moduleManager->modules) {
		if (module->state) {
			module->onRender2D(a1);
		}
	}*/

	CCheat::eventBus->callEvent(new Render2DEvent(a1));

	glPopMatrix();
	glPopAttrib();

	return ORIG_wglSwapBuffers(a1);
}

typedef int(__stdcall* _WSASend)(_In_ SOCKET, _In_ WSABUF*, _In_ unsigned long, _Out_ unsigned long*, _In_ unsigned long, _In_ OVERLAPPED*, 
	LPWSAOVERLAPPED_COMPLETION_ROUTINE);
_WSASend ORIG_WSASend;

int __stdcall HOOKED_WSASend(_In_ SOCKET _Socket, _In_ WSABUF* _Buffer, _In_ unsigned long _BufferCount, _Out_ unsigned long* _NumberOfBytesSent,
	_In_ unsigned long _Flags, _In_ OVERLAPPED* _Overlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE _CompletionRoutine) {
	int result = ORIG_WSASend(_Socket, _Buffer, _BufferCount, _NumberOfBytesSent, _Flags, _Overlapped, _CompletionRoutine);

	return result;
}

CCheat::CCheat(JNIEnv* env, JavaVM* javavm) {
	//
	//Yes
	//
	theCheat = this;
	std::cout << "[Debug] Env Created" << "\n";

	this->env = env;
	this->javavm = javavm;
	this->minecraftType = this->setMinecraftType();
	std::cout << "[Dubug] Minecraft Type Initialized" << "\n";

	//
	//Set Up Mappings
	//
	// HWND mc_one_twelve_two = ;
	/*	inline HWND find_window(const char* name)
	{
		auto res = BADLION_CLIENT ? FindWindowA("LWJGL", nullptr) : FindWindowA(nullptr, name);

		if (handle_issue(name, res))
			std::exit(0);

		return res;
	}*/
	if (FindWindowA(nullptr, "Minecraft 1.12.2"))
		CIntelligentMappings::init(ONE_TWELVE_TWO);
	else {
		std::cout << "1.8.9 Client support isnt ready yet" << "\n";
		Sleep(1000);
		exit(-1);
	}

	std::cout << "[Debug] Mappings Created" << "\n";;

	std::cout << "[Debug] Creating MC instance" << "\n";;

	this->theMinecraft = new CMinecraft();
	std::cout << "[Debug] Minecraft Created" << "\n";
	this->moduleManager = new CModuleManager();
	out::display("Module Manager");
	Sleep(500);
	this->eventBus = new CSimpleEventManager();
	out::display("EventManager... ");
	Sleep(500);
	this->moduleManager->registerModules();

	//Modules Setup

	std::cout << "[Debug] Event Manager and Modules Setup" << "\n";

	//I HATE HOOKS

	ORIG_wndproc = reinterpret_cast<WNDPROC>(SetWindowLongPtrA(FindWindowA("LWJGL", nullptr), 
		GWLP_WNDPROC, reinterpret_cast<long long>(HOOKED_wndproc)));
	std::cout << "[Null] WndProc Created" << "\n";
	ORIG_wglSwapBuffers = reinterpret_cast<_wglSwapBuffers>(GetProcAddress(GetModuleHandleA("opengl32"), "wglSwapBuffers"));
	ORIG_WSASend = reinterpret_cast<_WSASend>(GetProcAddress(GetModuleHandleA("ws2_32"), "WSASend"));
	std::cout << "[Null] SwapBuffers Created" << "\n";
	std::cout << "Creating Hooks..." << "\n";
	MH_CreateHook(ORIG_WSASend, HOOKED_WSASend, reinterpret_cast<void**>(&ORIG_WSASend));
	MH_CreateHook(ORIG_wglSwapBuffers, HOOKED_wglSwapBuffers, reinterpret_cast<void**>(&ORIG_wglSwapBuffers));
	MH_EnableHook(MH_ALL_HOOKS);

	//HOOKS!

	std::cout << "Hooks Created" << "\n";
	Sleep(1500);
	printf("51squad. Minecraft type: %s\nJNIEnv: 0x%p\nMinecraft klass: %s\n", 
		this->getMinecraftType() == EMinecraftType::FORGE ? "FORGE" : "VANILLA", this->env,
		CIntelligentMappings::getClass("net.minecraft.client.Minecraft").name().c_str());
}