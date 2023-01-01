#pragma once
#include "impl.h"

namespace fly {

	void invoke(std::shared_ptr<c_context>);

	inline auto m_enabled = false;

}