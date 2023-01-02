#pragma once
#include "module.h"

namespace fly {

	void invoke(std::shared_ptr<c_context> ctx);

	inline bool m_enabled = false;

}
