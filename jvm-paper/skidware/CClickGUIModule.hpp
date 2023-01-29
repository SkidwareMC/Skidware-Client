#ifndef CCLICKGUIMODULE_HPP_GUARD
#define CCLICKGUIMMODULE_HPP_GUARD
#pragma once

#include "CModule.hpp"

typedef struct CClickGUIModule : CModule {
	CClickGUIModule();
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void onEvent(const CSimpleEvent*) override;
	virtual void renderSettings();
};

static void HelpMarker(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

namespace gui {
	static int tab;
	extern ImVec4 clear_col;
	float color[3];
}

#endif //CCLICKGUIMODULE_HPP_GUARD
