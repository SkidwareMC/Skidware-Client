#include "LocalPlayer.hpp"
#include "../Wrapper/Utils.hpp"
#include "LaunchWrapper.hpp"
#include "../Wrapper/Logger.hpp"
LocalPlayer::LocalPlayer(jobject obj) : EntityPlayer(obj)
{
	CurrentObject = obj;
}

jobject LocalPlayer::GetCurrentObject()
{
	return CurrentObject;
}

jclass LocalPlayer::GetCurrentClass()
{
	if (CurrentObject == NULL) return NULL;
	if (CurrentClass == NULL) CurrentClass = JNIHelper::env->GetObjectClass(CurrentObject);

	return CurrentClass;
}

NetHandlerPlayClient LocalPlayer::getNetHandlerPlayClient()
{
	if (GetCurrentClass() == NULL) return NULL;

	if (NetHandlerPlayClientInstance.GetCurrentClass() == NULL)
	{
		if (getNetHandlerPlayClientFieldID == NULL)
		{
			getNetHandlerPlayClientFieldID = JNIHelper::IsForge() ? JNIHelper::env->GetFieldID(GetCurrentClass(), "field_71174_a", "Lnet/minecraft/client/network/NetHandlerPlayClient;") : JNIHelper::env->GetFieldID(GetCurrentClass(), "a", "Lbcy;");
			if (getNetHandlerPlayClientFieldID == NULL) return NULL;
		}

		if (getNetHandlerPlayClientObject == NULL)
		{
			getNetHandlerPlayClientObject = JNIHelper::env->GetObjectField(GetCurrentObject(), getNetHandlerPlayClientFieldID);
			if (getNetHandlerPlayClientObject == NULL) return NULL;
		}

		NetHandlerPlayClientInstance = NetHandlerPlayClient(getNetHandlerPlayClientObject);
	}

	return NetHandlerPlayClientInstance;
}

void LocalPlayer::setSprinting(jboolean sprinting)
{
	if (GetCurrentClass() == NULL) return;

	if (setSprintingMethodID == NULL)
	{
		setSprintingMethodID = JNIHelper::env->GetMethodID(GetCurrentClass(), JNIHelper::IsForge() ? "func_70031_b" : "d", "(Z)V");
		if (setSprintingMethodID == NULL) return;
	}

	JNIHelper::env->CallVoidMethod(GetCurrentObject(), setSprintingMethodID, sprinting);
}

void LocalPlayer::swingItem()
{
	if (GetCurrentClass() == NULL) return;

	if (swingItemMethodID == NULL)
	{
		swingItemMethodID = JNIHelper::env->GetMethodID(GetCurrentClass(), JNIHelper::IsForge() ? "func_71038_i" : "bw", "()V");
		if (swingItemMethodID == NULL) return;
	}

	JNIHelper::env->CallVoidMethod(GetCurrentObject(), swingItemMethodID);
}


jobject LocalPlayer::getPlayerCapabilites()
{
	if (GetCurrentClass() == NULL) return NULL;

	jfieldID fid = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_71075_bZ" : "bA", "Lwl;");
	jobject ret = JNIHelper::env->GetObjectField(GetCurrentClass(), fid);

	return ret;
}

void LocalPlayer::setFly(jboolean state)
{
	jobject capabilities = this->getPlayerCapabilites();
	if (!capabilities)
	{
		JNIHelper::env->DeleteLocalRef(capabilities);
		return;
	}

	jclass capabilitiesClass = JNIHelper::IsForge() ? JNIHelper::ForgeFindClass("net/minecraft/entity/player/PlayerCapabilities") : JNIHelper::env->GetObjectClass(capabilities);

	jfieldID fid = JNIHelper::env->GetFieldID(capabilitiesClass, JNIHelper::IsForge() ? "field_75100_b" : "b", "Z");
	JNIHelper::env->SetBooleanField(capabilities, fid, state);

	JNIHelper::env->DeleteLocalRef(capabilitiesClass);
	JNIHelper::env->DeleteLocalRef(capabilities);
}

double LocalPlayer::get_motion_x()
{
	if (GetCurrentClass() == NULL) return NULL;
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID xfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70159_w" : "v", "D");
	double x = (double)JNIHelper::env->GetDoubleField(CurrentObject, xfid);
	JNIHelper::env->DeleteLocalRef(playerclass);
	return x;
}

void LocalPlayer::set_motion_x(double x)
{
	if (GetCurrentClass() == NULL) return;
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID xfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70159_w" : "v", "D");
	JNIHelper::env->SetDoubleField(CurrentObject, xfid, (jdouble)x);
	JNIHelper::env->DeleteLocalRef(playerclass);
}

double LocalPlayer::get_motion_y()
{
	if (GetCurrentClass() == NULL) return NULL;
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID yfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70181_x" : "w", "D");
	double y = (double)JNIHelper::env->GetDoubleField(CurrentObject, yfid);
	JNIHelper::env->DeleteLocalRef(playerclass);
	return y;
}

void LocalPlayer::set_motion_y(double y)
{
	if (GetCurrentClass() == NULL) return;
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID yfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70181_x" : "w", "D");
	JNIHelper::env->SetDoubleField(CurrentObject, yfid, (jdouble)y);
	JNIHelper::env->DeleteLocalRef(playerclass);
}

double LocalPlayer::get_motion_z()
{
	if (GetCurrentClass() == NULL) return NULL;
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID xfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70179_y" : "x", "D");
	double z = (double)JNIHelper::env->GetDoubleField(CurrentObject, xfid);
	JNIHelper::env->DeleteLocalRef(playerclass);
	return z;
}

void LocalPlayer::set_motion_z(double z)
{
	if (GetCurrentClass() == NULL) return;
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID xfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70179_y" : "x", "D");
	JNIHelper::env->SetDoubleField(CurrentObject, xfid, (jdouble)z);
	JNIHelper::env->DeleteLocalRef(playerclass);
}

float LocalPlayer::get_fall_distance() {
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID falldfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70143_R" : "O", "F");
	JNIHelper::env->DeleteLocalRef(playerclass);
	return JNIHelper::env->GetFloatField(CurrentObject, falldfid);
}

bool LocalPlayer::isHurt(int ticks)
{
	if (GetCurrentClass() == NULL) return NULL;
	if (hurttimefd == NULL)
		hurttimefd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70737_aN" : "au", "I");
	int hurtTime = (int)JNIHelper::env->GetIntField(GetCurrentObject(), hurttimefd);
	return (hurtTime > ticks);
}

void LocalPlayer::setHurt(int ticks)
{
	if (GetCurrentClass() == NULL) return;
	if (hurttimefd == NULL)
		hurttimefd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70737_aN" : "au", "I");
	 JNIHelper::env->SetIntField(GetCurrentObject(), hurttimefd, ticks);
}

void LocalPlayer::setOnGround(jboolean onGround)
{
	if (GetCurrentClass() == NULL) return;
	if (ongroundfd == NULL)
		ongroundfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70122_E" : "C", "Z");
	JNIHelper::env->SetBooleanField(CurrentObject, ongroundfd, onGround);
}

bool LocalPlayer::getOnGround()
{
	if (GetCurrentClass() == NULL) return -1;
	if (ongroundfd == NULL)
		ongroundfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70122_E" : "C", "Z");
	JNIHelper::env->GetBooleanField(CurrentObject, ongroundfd);
}

bool LocalPlayer::isSneaking()
{
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID fid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_71158_b" : "b", "Lbeu;");

	jobject mvinput_obj = JNIHelper::env->GetObjectField(CurrentObject, fid);
	jclass mvclass = JNIHelper::env->GetObjectClass(mvinput_obj);
	jfieldID sfid = JNIHelper::env->GetFieldID(mvclass, JNIHelper::IsForge() ? "field_78899_d" : "d", "Z");
	auto res = JNIHelper::env->GetBooleanField(mvinput_obj, sfid);

	JNIHelper::env->DeleteLocalRef(playerclass);
	JNIHelper::env->DeleteLocalRef(mvclass);
	JNIHelper::env->DeleteLocalRef(mvinput_obj);

	return res;
}

void LocalPlayer::setSneak(bool state)
{
	jobject mc = CurrentObject;
	jclass mc_class = JNIHelper::env->GetObjectClass(mc);
	jfieldID settings_fid = JNIHelper::env->GetFieldID(mc_class, JNIHelper::IsForge() ? "field_71474_y" : "t", "Lavh;");

	jobject settings_obj = JNIHelper::env->GetObjectField(mc, settings_fid);
	jclass settings_class = JNIHelper::env->GetObjectClass(settings_obj);
	jfieldID binding_fid = JNIHelper::env->GetFieldID(settings_class, JNIHelper::IsForge() ? "field_74311_E" : "ac", "Lavb;");

	jobject sneak_binding = JNIHelper::env->GetObjectField(settings_obj, binding_fid);
	jclass keybind_class = JNIHelper::env->GetObjectClass(sneak_binding);
	jfieldID pressed_fid = JNIHelper::env->GetFieldID(keybind_class, JNIHelper::IsForge() ? "field_74513_e" : "h", "Z");

	JNIHelper::env->SetBooleanField(sneak_binding, pressed_fid, state);

	JNIHelper::env->DeleteLocalRef(mc);
	JNIHelper::env->DeleteLocalRef(mc_class);
	JNIHelper::env->DeleteLocalRef(settings_obj);
	JNIHelper::env->DeleteLocalRef(settings_class);
	JNIHelper::env->DeleteLocalRef(sneak_binding);
	JNIHelper::env->DeleteLocalRef(keybind_class);
}

float LocalPlayer::getRotationYaw()
{
	jfieldID yaw = JNIHelper::env->GetFieldID(CurrentClass, JNIHelper::IsForge() ? "field_70177_z" : "y", "F");
	return JNIHelper::env->GetFloatField(CurrentObject, yaw);
}

void LocalPlayer::setRotationYaw(float yaw)
{
	jfieldID yawfd = JNIHelper::env->GetFieldID(CurrentClass, JNIHelper::IsForge() ? "field_70177_z" : "y", "F");
	return JNIHelper::env->SetFloatField(CurrentObject, yawfd, yaw);
}

float LocalPlayer::getMoveStrafing()
{
	if (GetCurrentClass() == NULL) return NULL;
	jfieldID moveStrafe = JNIHelper::env->GetFieldID(CurrentClass, JNIHelper::IsForge() ? "field_70702_br" : "aZ", "F");
	return JNIHelper::env->GetFloatField(CurrentObject, moveStrafe);
}

float LocalPlayer::getMoveForward()
{
	if (GetCurrentClass() == NULL) return NULL;
	jfieldID moveForward = JNIHelper::env->GetFieldID(CurrentClass, JNIHelper::IsForge() ? "field_70701_bs" : "ba", "F");
	return JNIHelper::env->GetFloatField(CurrentObject, moveForward);
}

double LocalPlayer::getSpeed()
{
	return std::sqrt(this->get_motion_x() * this->get_motion_x() + this->get_motion_z() * this->get_motion_z());
}

void LocalPlayer::setFallDist(float dist)
{
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jfieldID falldfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_70143_R" : "O", "F");
	JNIHelper::env->DeleteLocalRef(playerclass);
	return JNIHelper::env->SetFloatField(CurrentObject, falldfid, dist);
}

bool LocalPlayer::isBlocking()
{
	jclass playerclass = JNIHelper::env->GetObjectClass(CurrentObject);
	jmethodID blockmid = JNIHelper::env->GetMethodID(playerclass, JNIHelper::IsForge() ? "func_70632_aY" : "bW", "()Z");
	JNIHelper::env->DeleteLocalRef(playerclass);
	return (bool)JNIHelper::env->CallBooleanMethod(CurrentObject, blockmid);

}

jobject LocalPlayer::raytrace(float dist)
{
	jclass player_class = JNIHelper::IsForge() ? JNIHelper::ForgeFindClass("net/minecraft/client/entity/EntityPlayerSP") : JNIHelper::env->GetObjectClass(CurrentObject);
	jmethodID raytrace_mid = JNIHelper::env->GetMethodID(player_class, JNIHelper::IsForge() ? "func_174822_a" : "a", "(DF)Lauh;");
	JNIHelper::env->DeleteLocalRef(player_class);
	return JNIHelper::env->CallObjectMethod(CurrentObject, raytrace_mid, 1.0, dist);
}


void LocalPlayer::setMoveStrafing(float value)
{
	if (GetCurrentClass() == NULL) return;
	jfieldID moveStrafe = JNIHelper::env->GetFieldID(CurrentClass, JNIHelper::IsForge() ? "field_70702_br" : "aZ", "F");
	return JNIHelper::env->SetFloatField(CurrentObject, moveStrafe, value);
}

void LocalPlayer::setMoveForward(float value)
{
	if (GetCurrentClass() == NULL) return;
	jfieldID moveForward = JNIHelper::env->GetFieldID(CurrentClass, JNIHelper::IsForge() ? "field_70701_bs" : "ba", "F");
	return JNIHelper::env->SetFloatField(CurrentObject, moveForward, value);
}

void LocalPlayer::attackEntity(Entity entity) {
	jobject pc_obj = LaunchWrapper::getMinecraft().get_player_controller();
	Logger::LogDebug("PC class");
	jclass pc_class = JNIHelper::env->GetObjectClass(pc_obj);
	Logger::LogDebug("pc object");
	jmethodID atmid = JNIHelper::env->GetMethodID(pc_class, JNIHelper::IsForge() ? "func_78764_a" : "a", "(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/entity/Entity;)V");
	Logger::LogDebug("method");
	JNIHelper::env->CallVoidMethod(pc_obj, atmid, CurrentObject, entity);
	Logger::LogDebug("method call");
	JNIHelper::env->DeleteLocalRef(pc_obj);
	JNIHelper::env->DeleteLocalRef(pc_class);
}

double toRadians(float degrees) {
	return degrees * (M_PI / 180);
}

double LocalPlayer::getDirection() {
	if (GetCurrentClass() == NULL) return NULL;
	float rotationYaw = getRotationYaw();
	if (this->getMoveForward() < 0.0f) {
		rotationYaw += 180.0f;
	}
	float forward = 1.0f;
	if (this->getMoveForward() < 0.0f) {
		forward = -0.5f;
	}
	else if (this->getMoveForward() > 0.0f) {
		forward = 0.5f;
	}
	if (this->getMoveStrafing() > 0.0f) {
		rotationYaw -= 90.0f * forward;
	}
	if (this->getMoveStrafing() < 0.0f) {
		rotationYaw += 90.0f * forward;
	}
	return toRadians(rotationYaw);
}

bool LocalPlayer::isStrafing() {
	if (GetCurrentClass() == NULL) return NULL;
	return this->getMoveStrafing() != 0.0;
}

bool LocalPlayer::isMovingForwardOrBackwards() {
	if (GetCurrentClass() == NULL) return NULL;
	return this->getMoveForward() != 0.0;
}

void LocalPlayer::strafe(float speed) {
	if (GetCurrentClass() == NULL) return;
	if (!this->isStrafing() && !this->isMovingForwardOrBackwards()) {
		return;
	}
	if (this->isStrafing() || this->isMovingForwardOrBackwards()) {
		double yaw = getDirection();

		this->set_motion_x(-sin(yaw) * speed);
		this->set_motion_z(cos(yaw) * speed);
	}
}

bool LocalPlayer::isMoving() {
	if (GetCurrentClass() == NULL) return NULL;
	return (this->getMoveForward() != 0) || (this->getMoveStrafing() != 0);
}




