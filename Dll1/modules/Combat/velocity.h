#pragma once
#include "module.h"

namespace velocity {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;
	inline double m_horizontal_multiplier = 0.5;
	inline double m_vertical_multiplier = 1.0;

}
