#pragma once
#include "module.h"

namespace scaffold {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline bool m_rage = false;
	inline bool m_sneak = true;
	inline long m_sneak_delay = 100L;

	static std::shared_ptr<c_timer> timer = std::make_shared<c_timer>();

}
