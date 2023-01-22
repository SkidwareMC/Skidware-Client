#include "CClickGUIModule.hpp"
#include "CCheat.hpp"

CClickGUIModule::CClickGUIModule() : CModule("ClickGUI", VK_RSHIFT, RENDER) {
	//this->toggle();
}

void CClickGUIModule::onEnable() {
	CMinecraft* mc = CCheat::theMinecraft;

	mc->isGameHasFocus = false;
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = true;

	CCheat::eventBus->registerListener(this);
}

void CClickGUIModule::onDisable() {
	CMinecraft* mc = CCheat::theMinecraft;
	mc->isGameHasFocus = true;
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = false;

	CCheat::eventBus->unregisterListener(this);
}

void CClickGUIModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const Render2DEvent*>(event)) {
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		ImGui::Text("Skidware");

		ImGui::Begin("Movement", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);

		for (CModule* module : CCheat::moduleManager->modules) {
			//ImGui::Checkbox(module->name.c_str(), &module->state);
			if (module->catagory == MOVEMENT) {
				if (ImGui::Button(module->name.c_str())) module->toggle();
				module->setState(module->state);
				module->renderSettings();
			}

				// if (ImGui::Button(module->name.c_str())) module->toggle();
		}

		ImGui::End();

		ImGui::Begin("Misc", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);

		for (CModule* module : CCheat::moduleManager->modules) {
			//ImGui::Checkbox(module->name.c_str(), &module->state);
			if (module->catagory == MISC) {
				if (ImGui::Button(module->name.c_str())) module->toggle();
				module->setState(module->state);
				module->renderSettings();
			}
		}

		ImGui::End();

		ImGui::Begin("Render", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);

		for (CModule* module : CCheat::moduleManager->modules) {
			//ImGui::Checkbox(module->name.c_str(), &module->state);
			if (module->catagory == RENDER) {
				if (ImGui::Button(module->name.c_str())) module->toggle();
				module->setState(module->state);
				module->renderSettings();
			}
				// if (ImGui::Button(module->name.c_str())) module->toggle();
		}

		ImGui::End();

		ImGui::Begin("Combat", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);

		for (CModule* module : CCheat::moduleManager->modules) {
			//ImGui::Checkbox(module->name.c_str(), &module->state);
			if (module->catagory == COMBAT) {
				if (ImGui::Button(module->name.c_str())) module->toggle();
				module->setState(module->state);
				module->renderSettings();
			}
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
