#pragma once

#include "minecraft.h"
#include "player.h"

class c_world 
{
private:
	jobject world_obj;
public:
	c_world(jobject obj);
	~c_world();

	const jobject get_object()
	{
		return world_obj;
	}

	jobjectArray get_world_players();
	jobjectArray get_world_entities();
	bool is_air_block(double x, double y, double z);

};