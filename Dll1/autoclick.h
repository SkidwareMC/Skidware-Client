#pragma once
#include "module.h"

namespace autoclick {
	
	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = true;
	inline float m_cps = 15.f;
	inline float m_blockhit_chance = 0.0f;
	inline bool m_randomize = false;
	inline bool m_break_blocks = true;
	inline bool m_inventory_check = false;
	inline bool m_triggerbot = true;

	static std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();
	inline int clicks = 0;
	inline int step = 0;
	inline int rstep = 0;

}
