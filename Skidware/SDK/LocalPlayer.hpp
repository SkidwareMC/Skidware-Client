#pragma once
#include "JNIHelper.hpp"
#include "NetHandlerPlayClient.hpp"
#include "EntityPlayer.hpp"
#include "../Wrapper/Utils.hpp"
class LocalPlayer : public EntityPlayer
{
private:
	jobject CurrentObject = NULL;
	jclass CurrentClass = NULL;

	jfieldID getNetHandlerPlayClientFieldID = NULL;
	jfieldID motionXfd = NULL;
	jfieldID motionYfd = NULL;
	jfieldID motionZfd = NULL;
	jfieldID playerCapablitiesfd = NULL;
	jfieldID hurttimefd = NULL;
	jfieldID ongroundfd = NULL;
	jfieldID speedinairfd = NULL;

	jobject getNetHandlerPlayClientObject = NULL;
	NetHandlerPlayClient NetHandlerPlayClientInstance = NULL;

	jmethodID setSprintingMethodID = NULL;
	jmethodID swingItemMethodID = NULL;


public:
	LocalPlayer(jobject);
	jobject GetCurrentObject();
	jclass GetCurrentClass();

	NetHandlerPlayClient getNetHandlerPlayClient();
	void setSprinting(jboolean);
	void swingItem();
	jobject getPlayerCapabilites();
	void setFly(jboolean);
	double get_motion_x();
	void set_motion_x(double x);
	double get_motion_y();
	void set_motion_y(double y);
	double get_motion_z();
	void set_motion_z(double z);
	float get_fall_distance();
	bool isHurt(int ticks);
	void setHurt(int ticks);
	void setOnGround(jboolean onGround);
	bool getOnGround();
	bool isSneaking();
	void setMoveStrafing(float value);
	void setMoveForward(float value);
	jobject get_player_controller();
	void attackEntity(Entity entity);
	double getDirection();
	bool isStrafing();
	bool isMovingForwardOrBackwards();
	void strafe(float speed);
	bool isMoving();
	void setSneak(bool state);
	float getRotationYaw();
	void setRotationYaw(float yaw);
	float getMoveStrafing();
	float getMoveForward();
	double getSpeed();
	void setFallDist(float);
	bool isBlocking();
	jobject raytrace(float dist);
};