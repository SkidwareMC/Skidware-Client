#pragma once

#include "includes.h"
#include "module.h"


namespace antiafk {

	void invoke(std::shared_ptr<c_context>);

	inline bool m_enabled = false;
	inline c_timer timer;

}
