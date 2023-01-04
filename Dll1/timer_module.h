#pragma once
#include "module.h"

namespace timer 
{

	void invoke(std::shared_ptr<c_context> ctx);
	inline bool m_enabled = false;
	inline float m_multiplier = 2.0f;

	void reset(std::shared_ptr<c_context> ctx);

}
