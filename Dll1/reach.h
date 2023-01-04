#pragma once
#include "module.h"
#include "machip.h"

namespace reach {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline float m_distance = 6.0f;

}
