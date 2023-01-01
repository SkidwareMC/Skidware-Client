#pragma once
#include "impl.h"
namespace velocity {
	int m_horizontal = 0;
	int m_vertical = 0;
	bool m_enabled;
	void invoke(std::shared_ptr<c_context> ctx);
}