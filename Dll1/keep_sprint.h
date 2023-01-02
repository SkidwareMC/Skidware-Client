#pragma once

#include "includes.h"
#include "module.h"

namespace keep_sprint {

	void invoke(std::shared_ptr<c_context>);

	inline bool m_enabled = false;

}
