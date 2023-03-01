#include "GUI.hpp"
#include <vector>
#include <gl/GL.h>
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_win32.h"
#include "../ImGui/imgui_impl_opengl3.h"
#include "Settings.hpp"
#include "../Wrapper/Logger.hpp"
#include "../Wrapper/ClientConsole.hpp"
#include "../Core/Modules/NameSpoofer.hpp"
#include "Handler.hpp"
#include <iostream>
#include "font.hpp"
#include <mutex>
#include "../SDK/LaunchWrapper.hpp"
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
#pragma comment(lib, "opengl32.lib")
static const char* speed_modes[] = { "VerusHop", "NCPBHop", "Vanilla", "Spartan", "AAC3"};
static const char* speed_current_mode = "NCPBHop";
extern ImVec4 clear_col;
WNDPROC originalWNDPROC;

bool GUI::IsInitialized = false;
bool GUI::Enabled = false;

void GUI::Create()
{
	HWND minecraftWindow = FindWindowA("LWJGL", nullptr);

	originalWNDPROC = (WNDPROC)SetWindowLongPtrW(minecraftWindow, GWLP_WNDPROC, (LONG_PTR)patchedWNDPROC);

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(minecraftWindow);
	ImGui_ImplOpenGL3_Init();


	ImGuiStyle* Style = &ImGui::GetStyle();
	ImGui::StyleColorsDark();
	ImFont* mainfont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Bahnschrift.ttf", 20);
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	Style->WindowRounding = 0;
	Style->WindowBorderSize = 0;
	Style->GrabRounding = 2;
	Style->FrameRounding = 2;
	Style->ChildRounding = 0;
	Style->FrameBorderSize = 0;
	Style->Colors[ImGuiCol_WindowBg] = ImColor(25, 25, 25);
	Style->Colors[ImGuiCol_ChildBg] = ImColor(25, 25, 25);
	Style->Colors[ImGuiCol_Button] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_Text] = ImColor(52, 247, 213);
	Style->Colors[ImGuiCol_ButtonHovered] = ImColor(clear_col);
	Style->Colors[ImGuiCol_ButtonActive] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_Button] = ImColor(26, 29, 174);
	Style->Colors[ImGuiCol_FrameBg] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_FrameBgActive] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_FrameBgHovered] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_SliderGrab] = ImColor(clear_col);
	Style->Colors[ImGuiCol_SliderGrabActive] = ImColor(clear_col);


	ImGui::GetStyle().ScrollbarRounding = 5.0f;
	Style->GrabMinSize = 15.0f;
	Style->ScrollbarSize = 20.0f;
	Style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);

	io.IniFilename = NULL; // GET RID OF IMGUI.INI

    IsInitialized = true;
	Enabled = false;
}

void GUI::Delete()
{
	HWND minecraftWindow = FindWindowA("LWJGL", nullptr);
    Enabled = false;
    IsInitialized = false;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
	SetWindowLongPtrW(minecraftWindow, GWLP_WNDPROC, (LONG_PTR)originalWNDPROC);
}

void GUI::RenderMain()
{


	ImGui::SetNextWindowSize(ImVec2(800, 600));
	ImGui::Begin("Skidware");

	if (ImGui::CollapsingHeader("MOVEMENT"))
	{
		ImGui::Checkbox("Auto Sprint", &Settings::AutoSprint);
/*		ImGui::Checkbox("Speed", &Settings::Speed);
		if (Settings::Speed) {
			
			if (ImGui::BeginCombo("##combo", speed_current_mode)) // The second parameter is the label previewed before opening the combo.
			{
				for (int n = 0; n < IM_ARRAYSIZE(speed_modes); n++)
				{
					bool is_selected = (speed_current_mode == speed_modes[n]); // You can store your selection however you want, outside or inside your objects
					if (ImGui::Selectable(speed_modes[n], is_selected))
						speed_current_mode = speed_modes[n];
					if (is_selected)
						ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
				}
				ImGui::EndCombo();
			}
			if (speed_current_mode == "VerusHop") {
				Handler::speed_modes = 3;
				
			}
			if (speed_current_mode == "NCPBHop") {
				Handler::speed_modes = 2;
				
			}
			if (speed_current_mode == "Vanilla") {
				Handler::speed_modes = 1;
				
			}
			Logger::LogDebug(std::to_string(Handler::speed_modes));
		}*/
		ImGui::Checkbox("Vanilla", &Settings::VanillaSpeed);
		ImGui::SliderFloat("Multiplier", &Settings::multiplier, 0.0f, 6.0f);
		ImGui::Checkbox("VerusBHop", &Settings::NCPYPort);
		ImGui::Checkbox("NCP BHop", &Settings::NCPBHop);
		ImGui::Checkbox("Fly", &Settings::Fly);
		if (Settings::Fly) {
			ImGui::SliderFloat("Speed", &Settings::flySpeed, 0.0, 5.0);
		}

		
	}

	if (ImGui::CollapsingHeader("COMBAT"))
	{
		ImGui::Checkbox("Autoclicker", &Settings::Autoclicker);
		if (Settings::Autoclicker)
		{
			ImGui::SliderInt("CPS", &Settings::AutoclickerCount, 1, 20);
		}

		ImGui::Checkbox("No Hit Delay", &Settings::NoHitDelay);

		ImGui::Checkbox("Hitboxes (Blatent)", &Settings::HitBoxExtender);
		if (Settings::HitBoxExtender)
		{
			ImGui::SliderFloat("Width", &Settings::HitBoxWidth, 0, 5);
			ImGui::SliderFloat("Height", &Settings::HitBoxHeight, 0, 5);
		}

		ImGui::Checkbox("Anti Bot", &Settings::AntiBot);
		if (Settings::AntiBot)
		{
			ImGui::Checkbox("Name Flag", &Settings::AntiBotNameFlag);
			ImGui::Checkbox("Ping Flag", &Settings::AntiBotPingFlag);
			ImGui::Checkbox("Risky Ping Flag", &Settings::AntiBotRiskyPingFlag);
			ImGui::Checkbox("UUID Flag", &Settings::AntiBotUUIDFlag);
		}
		ImGui::Checkbox("Velocity", &Settings::Velocity);
		if (Settings::Velocity) {
			ImGui::Checkbox("Groundspoof", &Settings::groundSpoof);
			ImGui::SliderInt("Ticks (higher = more kb, lower = less)", &Settings::VeloTicks, 0, 10);
			ImGui::SliderFloat("Horizontal", &Settings::hori, -1, 1);
			ImGui::SliderFloat("Vertical", &Settings::vert, -1, 1);
		}
		ImGui::Checkbox("Aura", &Settings::Killaura);
		if (Settings::Killaura)
			ImGui::SliderFloat("Range", &Settings::range, 3.0, 6.0f);
	}

	if (ImGui::CollapsingHeader("VISUAL"))
	{
		ImGui::Checkbox("PlayerESP", &Settings::PlayerESP);
		ImGui::Checkbox("ChestESP", &Settings::ChestESP);
	}

	if (ImGui::CollapsingHeader("MINIGAMES"))
	{
		ImGui::Checkbox("Murder Expose", &Settings::MurderExpose);
	}

	if (ImGui::CollapsingHeader("MISC"))
	{
		if (ImGui::Checkbox("Alt manager (cracked)", &Settings::NameSpoof)) NameSpoofer::Toggle();
		ImGui::InputText("Name", &Settings::NameSpoofValue, 15);

		if (ImGui::Button("Uninject")) Settings::ShouldUninject = true;

		ImGui::Checkbox("FastPlace", &Settings::NoBuildDelay);

		ImGui::Checkbox("Frame Spoof", &Settings::FrameSpoof);
		if (Settings::FrameSpoof)
		{
			ImGui::SliderInt("Frames", &Settings::FrameSpoofValue, -1337, 1337);
		}

		ImGui::Checkbox("Ping Spoof", &Settings::PingSpoof);
		if (Settings::PingSpoof)
		{
			ImGui::SliderInt("Latency", &Settings::PingSpoofValue, -1337, 1337);
		}

		ImGui::Checkbox("No Fire", &Settings::NoFire);


		ImGui::Checkbox("LegitScaffold", &Settings::LegitScaffold);
	}

	ImGui::End();
}

void GUI::RenderConsole()
{
	ImGui::SetNextWindowSize(ImVec2(400, 300));
	ImGui::SetNextWindowBgAlpha(0.25f);
	ImGui::Text("Console");
	ImGui::Separator();
	bool* debug_open = (bool*)0;
	if (ImGui::Begin("Debug", debug_open, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{

		std::vector<std::string> logs = ClientConsole::GetLogs();

		int size = logs.size();
		for (int i = size - 1; i >= 0; i--)
		{
			ImGui::Text(logs[i].c_str());
		}

	}

	ImGui::End();
}

void GUI::RenderInfo()
{
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
	ImGui::SetNextWindowPos(ImVec2(1640, 0));
	ImGui::SetNextWindowBgAlpha(0.25f);
	bool* info_open = (bool*)0;
	ImGui::Begin("Info", info_open, window_flags);
	ImGui::Text(("Skidware B0.5 | FPS: " + std::to_string(Settings::DebugFPS) + " Ping: " + std::to_string(Settings::DebugPing)).c_str());
	ImGui::Separator();
	//ImGuiStyle* style = &ImGui::GetStyle();
	//style->Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
	
	//if (current_mode == "Green")
	//	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
	/*
	else if (current_mode == "Red")
		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
	else if (current_mode == "Yellow")
		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
	else if (current_mode == "Blue")
		ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 0, 255, 255));
	*/
	if (Settings::AntiBot) {
		ImGui::Text("AntiBot");
	}
	if (Settings::Autoclicker) {
		ImGui::Text("AutoClicker");
	}
	if (Settings::AutoSprint) {
		ImGui::Text("AutoSprint");
	}
	if (Settings::NoFire) {
		ImGui::Text("NoFire");
	}
	if (Settings::NoBuildDelay) {
		ImGui::Text("FastPlace");
	}
	if (Settings::NoHitDelay) {
		ImGui::Text("NoHitDelay");
	}
	if (Settings::MurderExpose) {
		ImGui::Text("MurderExpose");
	}

	if (Settings::HitBoxExtender) {
		ImGui::Text("HitBoxes");
	}
	if (Settings::FrameSpoof) {
		ImGui::Text("FrameSpoof");
	}
	if (Settings::PlayerESP) {
		ImGui::Text("PlayerESP");
	}
	if (Settings::Velocity) {
		ImGui::Text(("Velocity - " + std::to_string(Settings::VeloTicks)).c_str());
	}
	if (Settings::VanillaSpeed) {
		ImGui::Text(("Speed - Vanilla"));
	}

	if (Settings::LegitScaffold) {
		ImGui::Text(("Scaffold - " + std::to_string(Settings::sneak_delay)).c_str());
	}

	if (Settings::NCPYPort) {
		ImGui::Text(("Speed - VerusHop"));
	}
	if (Settings::NCPBHop) {
		ImGui::Text(("Speed - NCPHop"));
	}
	if (Settings::Fly) {
		ImGui::Text(("Fly - " + std::to_string(Settings::flySpeed)).c_str());
	}
	ImGui::End();
}

void GUI::RenderESP()
{
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImVec2(Settings::DebugWidth, Settings::DebugHeight));
	ImGui::Begin("ESP", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoBackground);

	auto pDrawList = ImGui::GetWindowDrawList();

	if (Settings::PlayerESP)
	{
		pDrawList->AddRect(ImVec2(10, 10), ImVec2(100, 100), ImColor(255, 0, 0));
		pDrawList->AddText(ImVec2(10, 10), ImColor(255, 0, 0), "test");
	}

	if (Settings::ChestESP)
	{

	}

	ImGui::End();
}

void GUI::Render()
{
	std::once_flag flag1, flag2;

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	if (Enabled)
	{
		RenderMain();
		// RenderConsole();
		
		//LaunchWrapper::getMinecraft().setIsGameHasFocus(false);
		//io.MouseDrawCursor = true;
	}
	RenderInfo();
	RenderESP();
	
	if (!Enabled)
	{
		//io.MouseDrawCursor = false;
		//LaunchWrapper::getMinecraft().setIsGameHasFocus(true);
	}

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::OnSwapBuffers(HDC hdc)
{
    if (!IsInitialized)
    {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glViewport(0, 0, viewport[2], viewport[3]);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glDisable(GL_DEPTH_TEST);

        Create();
    }
	else if (Settings::CanRenderMenu) Render();
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall GUI::patchedWNDPROC(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (!IsInitialized) return CallWindowProcA(originalWNDPROC, hWnd, msg, wParam, lParam);

	if (msg == WM_KEYDOWN && wParam == VK_F12) Enabled = !Enabled;

	if (Enabled && ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) return true;

	return CallWindowProcA(originalWNDPROC, hWnd, msg, wParam, lParam);
}