#pragma once
#include <iostream>
#include <Windows.h>
#include "xorstr.hpp"

namespace out {
	void display(const char* str) {
		std::cout << str << std::endl;
	}
}