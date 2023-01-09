#include "CClickGUIModule.hpp"
#include "CCheat.hpp"

CClickGUIModule::CClickGUIModule() : CModule("ClickGUI", VK_RSHIFT) {
	//this->toggle();
}

void CClickGUIModule::onEnable() {
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = true;

	CCheat::eventBus->registerListener(this);
}

void CClickGUIModule::onDisable() {
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = false;

	CCheat::eventBus->unregisterListener(this);
}

void CClickGUIModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const Render2DEvent*>(event)) {
		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Lightning", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);

		for (CModule* module : CCheat::moduleManager->modules) {
			//ImGui::Checkbox(module->name.c_str(), &module->state);
			if (ImGui::Button(module->name.c_str())) module->toggle();
		}

		ImGui::End();

		ImGui::Render();
		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
		glViewport(0, 0, viewport[2], viewport[3]);
		ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	}
}