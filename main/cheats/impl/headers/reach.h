#pragma once
#include "impl.h"

namespace reach {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline float m_distance = 3.0f;
	inline float m_yesnt = 0.0f;

}