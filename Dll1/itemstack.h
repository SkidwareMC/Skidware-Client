#pragma once

#include "minecraft.h"

using std::string;

class itemstack {

private:
	jobject item_obj;

public:
	itemstack(jobject obj);
	~itemstack();

	jobject get_object();

	string get_name();

	jobject get_item();

	int get_item_damage();

};
