#pragma once

#include "minecraft.h"
#include "itemstack.h"

class c_player 
{
private:
	jobject player_obj;
public:
	c_player(jobject obj);
	~c_player();

	const jobject get_object()
	{
		return player_obj;
	}

	bool is_blocking();
	bool is_breaking_blocks();
	bool is_hovering_entity();
	bool is_moving();
	bool is_sneaking();
	bool is_sprinting();
	bool is_jumping();
	bool is_airborne();
	bool is_hurt();
	bool is_on_ground();

	void set_on_ground(bool val);
	void set_sneaking(bool val);
	void attackEntity(jobject entity);
	void update_player_controller();
	void drop_current_item(bool drop_all);
	void drop_item(itemstack item, bool dropAround);

	void window_click(int windowID, int slotID, int mouseButtonClicked, int mode);

	int get_entity_id();
	int get_item_index(std::string name);

	float get_health();

	float get_fall_distance();
	void set_fall_distance(float val);

	sdk::vec3 get_location();

	double get_motion_x();
	void set_motion_x(double x);


	double get_motion_y();
	void set_motion_y(double y);

	double get_motion_z();
	void set_motion_z(double z);

	jobject get_player_controller();
	jobject get_open_container();
	jobject get_inventory_container();
	jobject get_inventory();

	itemstack get_current_item();

	void send_use_item(jobject world, jobject itemstack);

	int get_current_item_index();
	void set_current_item_index(int idx);

	jobject raytrace(float distance);

};