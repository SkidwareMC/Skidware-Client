#include "CClickGUIModule.hpp"
#include "CCheat.hpp"

void ChromaticTab(char* label, int& tabhandler, int tab)
{
	if (tabhandler == tab)
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(ImColor(35, 35, 35)));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(ImColor(35, 35, 35)));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(ImColor(35, 35, 35)));
		//ImGui::PushStyleColor(ImGuiCol_Text, gui::clear_col);
		if (ImGui::Button(label, ImVec2(150, 40))) { tabhandler = tab; }
		ImGui::PopStyleColor(3);
	}
	else
	{
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(ImColor(25, 25, 25)));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(ImColor(25, 25, 25)));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(ImColor(25, 25, 25)));
		if (ImGui::Button(label, ImVec2(150, 40))) { tabhandler = tab; }
		ImGui::PopStyleColor(3);
	}
}



CClickGUIModule::CClickGUIModule() : CModule("ClickGUI", VK_RSHIFT, RENDER) {
	//this->toggle();

}

void CClickGUIModule::onEnable() {
	ImGuiIO& io = ImGui::GetIO();
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
	Style->Colors[ImGuiCol_ButtonHovered] = ImColor(gui::clear_col);
	Style->Colors[ImGuiCol_ButtonActive] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_Button] = ImColor(26, 29, 174);
	Style->Colors[ImGuiCol_FrameBg] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_FrameBgActive] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_FrameBgHovered] = ImColor(35, 35, 35);
	Style->Colors[ImGuiCol_SliderGrab] = ImColor(gui::clear_col);
	Style->Colors[ImGuiCol_SliderGrabActive] = ImColor(gui::clear_col);


	ImGui::GetStyle().ScrollbarRounding = 5.0f;
	Style->GrabMinSize = 15.0f;
	Style->ScrollbarSize = 50.0f;
	Style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);

	io.IniFilename = NULL; // GET RID OF IMGUI.INI
	CMinecraft* mc = CCheat::theMinecraft;

	io.MouseDrawCursor = true;

	CCheat::eventBus->registerListener(this);
}

void CClickGUIModule::onDisable() {
	CMinecraft* mc = CCheat::theMinecraft;
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = false;

	CCheat::eventBus->unregisterListener(this);
}

void CClickGUIModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const Render2DEvent*>(event)) {
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(650, 400));

		ImGui::Begin("Skidware", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
		ImGui::Text("Skidware b0.3");
		
		ImGui::Separator();
		ChromaticTab("Combat", gui::tab, 0); ImGui::SameLine();
		ChromaticTab("Movement", gui::tab, 1); ImGui::SameLine();
		ChromaticTab("Render", gui::tab, 2); ImGui::SameLine();
		ChromaticTab("Misc", gui::tab, 3); ImGui::SameLine();
		ImGui::Separator();
		for (CModule* module : CCheat::moduleManager->modules) {
			//ImGui::Checkbox(module->name.c_str(), &module->state);
			if (gui::tab == 0) {
				if (module->catagory == COMBAT) {
					ImGui::Text(module->name.c_str()); ImGui::SameLine();
					if (ImGui::Button("Toggle")) module->toggle();
					module->renderSettings();
					HelpMarker(module->desc);
				}
			}
			else if (gui::tab == 1) {
				if (module->catagory == MOVEMENT) {
					ImGui::Text(module->name.c_str()); ImGui::SameLine();
					if (ImGui::Button("Toggle")) module->toggle();
					module->renderSettings();
					HelpMarker(module->desc);
				}
			}
			else if (gui::tab == 2) {
				if (module->catagory == RENDER) {
					ImGui::Text(module->name.c_str()); ImGui::SameLine();
					if (ImGui::Button("Toggle")) module->toggle();
					module->renderSettings();
					HelpMarker(module->desc);
				}
			}
			else if (gui::tab == 3) {
				if (module->catagory == MISC) {
					ImGui::Text(module->name.c_str()); ImGui::SameLine();
					if (ImGui::Button("Toggle")) module->toggle();
					module->renderSettings();
					HelpMarker(module->desc);
				}
			}
			/*
			if (gui::tab == 3) {
				ImGuiStyle* Style = &ImGui::GetStyle();
				ImGui::ColorPicker3("Color", gui::color);
				ImVec4 x;
				x.x = gui::color[0];
				x.y = gui::color[1];
				x.z = gui::color[2];
				Style->Colors[ImGuiCol_WindowBg] = x;
			}
			*/

			// if (ImGui::Button(module->name.c_str())) module->toggle();
		}

		ImGui::End();
		ImGui::Render();
		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
		glViewport(0, 0, viewport[2], viewport[3]);
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	}

}

void CClickGUIModule::renderSettings()
{
	return;
}