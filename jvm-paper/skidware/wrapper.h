#pragma once
#include <iostream>
#include <Windows.h>
#include "xorstr.hpp"

namespace out {
	void display(const char* str) {
		std::cout << str << std::endl;
	}
}

namespace misc {
	void thread(void* x) {

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)x, 0, 0, 0);

	}
}