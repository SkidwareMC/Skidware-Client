#pragma once

#include "includes.h"
#include "module.h"

namespace killaura {

	void invoke(std::shared_ptr<c_context>);

	inline bool m_enabled = false;
	inline bool m_anti_bot = true;
	inline bool m_ignore_behind_walls = false;
	inline bool m_mobs = true;
	inline int m_max_targets = 5;
	inline double m_delay = 250;
	inline bool m_hit_closest = false;
	inline double m_range = 4.f;

	inline c_timer timer;

}
