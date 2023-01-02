#pragma once

#include "includes.h"
#include "module.h"

namespace fullbright {

	void invoke(std::shared_ptr<c_context>);

	inline bool m_enabled = false;

}
