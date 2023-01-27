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

namespace gui {
	static int tab;
	extern ImVec4 clear_col;
	float color[3];
}

#endif //CCLICKGUIMODULE_HPP_GUARD
