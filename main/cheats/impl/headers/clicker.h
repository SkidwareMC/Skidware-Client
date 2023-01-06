#pragma once

#include "impl.h"

namespace clicker
{
	void invoke(std::shared_ptr<c_context>);

	inline auto m_enabled = true;
	float m_delay = {};
	float m_random = {};
	float f_cps = {};
}