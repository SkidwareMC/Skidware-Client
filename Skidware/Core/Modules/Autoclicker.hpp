#pragma once
#include "Module.hpp"
class Autoclicker : Module
{
private:
	static int TickCount;

public:
	Autoclicker();
	static void OnTick();
};