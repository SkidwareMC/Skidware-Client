#pragma once

class HitBoxExtender
{
private:
	static bool NeedReset;
	static float DefaultWidth;
	static float DefaultHeight;

public:
	static void OnTick();
};