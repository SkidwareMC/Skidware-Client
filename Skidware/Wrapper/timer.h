#pragma once
#include <Windows.h>
class timer 
{
private:
	unsigned long long time;
public:
	timer();
	timer(unsigned long long time) : time(time) {}

	void reset();
	unsigned long long get_time();
	bool has_passed(long ms);
};