#pragma once
#include "module.h"

namespace noslowdown {

	void invoke(std::shared_ptr<c_context> ctx);
	inline bool m_enabled = false;

}
