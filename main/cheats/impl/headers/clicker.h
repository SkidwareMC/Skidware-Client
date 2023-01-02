#pragma once
#include "impl.h"

namespace clicker {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline float m_cps = 15.f;
	inline bool m_randomize = false;

	static std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();
	inline int clicks = 0;
	inline int step = 0;
	inline int rstep = 0;

}