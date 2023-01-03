#pragma once
#include "module.h"

namespace refill {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline bool m_soups = true;
	inline bool m_clear_hotbar = false;
	inline long long m_clear_delay = 100L;
	inline bool m_keep_open = false;
	inline bool m_random = false;

	static bool was_running = false;
	static std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();
	static std::shared_ptr<std::vector<int>> idxsToLoop = std::make_shared<std::vector<int>>();

}
