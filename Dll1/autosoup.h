#pragma once
#include "module.h"

namespace autosoup {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline float m_life_required = 14.f;

	static std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();

}
