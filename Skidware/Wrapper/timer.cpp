#include "timer.h"

timer::timer()
{
	this->time = GetTickCount64();
}

void timer::reset()
{
	this->time = GetTickCount64();
}

unsigned long long timer::get_time()
{
	return this->time;
}

bool timer::has_passed(long ms)
{
	return (GetTickCount64() - this->get_time() > ms);
}
