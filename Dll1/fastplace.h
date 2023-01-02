#pragma once

#include "includes.h"
#include "module.h"

namespace fastplace {

	void invoke(std::shared_ptr<c_context>);

	inline bool m_enabled = true;
	inline bool m_only_blocks = false;
	inline float m_delay = 1.0f; // max 6 min 0

}
