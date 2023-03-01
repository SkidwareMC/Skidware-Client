#pragma once
#include "../Wrapper/timer.h"
class Handler
{
	
private:
	static void DoKeyBinds();
	static void SetSettings();

public:
	static int speed_modes; // vanilla, y-port
	static void HandlerInit();
	static void OnTick();
	static void OnJoinedWorld();
	static bool oldState;
	static timer timere;
	static int tick;
	static bool flywason;
};