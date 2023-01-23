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

		

		ImGui::Begin("Skidware", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Text("Skidware");
		ImGui::Text("Smellon#8460");
		ImGui::Text("NoSword#8418");
		for (CModule* module : CCheat::moduleManager->modules) {
			if (ImGui::Button(module->name.c_str())) module->toggle();
			module->renderSettings();
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
