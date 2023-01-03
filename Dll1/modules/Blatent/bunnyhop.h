#pragma once

#include "includes.h"
#include "module.h"

namespace bunnyhop {

	void invoke(std::shared_ptr<c_context>);

	inline bool m_enabled = false;
	inline float multiplier = 1.0f;

	void reset(std::shared_ptr<c_context> ctx);

}
