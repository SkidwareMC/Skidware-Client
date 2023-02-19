#pragma once

class Handler
{
private:
	static void DoKeyBinds();
	static void SetSettings();

public:
	static void OnTick();
	static void OnJoinedWorld();
	static bool oldState;

	static bool flywason;
};