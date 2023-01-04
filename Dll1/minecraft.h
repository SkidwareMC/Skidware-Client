#pragma once

#include "includes.h"

namespace sdk 
{
	class c_minecraft 
	{
	public:
		jobject get_minecraft();
		jobject get_player(jobject);
		jobject get_world(jobject mc);
		jobject get_current_screen(jobject mc);
		bool hasTick = false;
		bool blockMovement = false;
		double mx = 0;
		double mz = 0;
	};

	extern std::unique_ptr<c_minecraft> instance;
}