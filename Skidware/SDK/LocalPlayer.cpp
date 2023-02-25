#include "LocalPlayer.hpp"
#include "../Wrapper/Utils.hpp"
#include "LaunchWrapper.hpp"
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

void LocalPlayer::SetVelocity(double motionx, double motiony, double motionz) {
	if (GetCurrentClass() == NULL) return;
	if (motionXfd == NULL)
		motionXfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70159_w" : "v", "()V");
	if (motionYfd == NULL)
		motionYfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70181_x" : "w", "()V");
	if (motionZfd == NULL)
		motionZfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70179_y" : "x", "()V");
	if (motionx == NULL)
		JNIHelper::env->SetDoubleField(CurrentObject, motionXfd, JNIHelper::env->GetDoubleField(CurrentObject, motionXfd));
	if (motiony == NULL)
		JNIHelper::env->SetDoubleField(CurrentObject, motionYfd, JNIHelper::env->GetDoubleField(CurrentObject, motionYfd));
	if (motionz == NULL)
		JNIHelper::env->SetDoubleField(CurrentObject, motionZfd, JNIHelper::env->GetDoubleField(CurrentObject, motionZfd));

	JNIHelper::env->SetDoubleField(CurrentObject, motionXfd, motionx);
	JNIHelper::env->SetDoubleField(CurrentObject, motionYfd, motiony);
	JNIHelper::env->SetDoubleField(CurrentObject, motionZfd, motionz);
	return;
}

vector3 LocalPlayer::GetVelocity()
{
	vector3 temp;
	if (GetCurrentClass() == NULL) return temp;
	if (motionXfd == NULL)
		motionXfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70159_w" : "v", "()V");
	if (motionYfd == NULL)
		motionYfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70181_x" : "w", "()V");
	if (motionZfd == NULL)
		motionZfd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70179_y" : "x", "()V");
	temp.x = JNIHelper::env->GetDoubleField(CurrentObject, motionXfd);
	temp.y = JNIHelper::env->GetDoubleField(CurrentObject, motionYfd);
	temp.z = JNIHelper::env->GetDoubleField(CurrentObject, motionZfd);
	return temp;
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

	jclass capabilitiesClass = JNIHelper::env->GetObjectClass(capabilities);

	jfieldID fid = JNIHelper::env->GetFieldID(capabilitiesClass, JNIHelper::IsForge() ? "field_75100_b" : "b", "Z");
	JNIHelper::env->SetBooleanField(capabilities, fid, state);

	JNIHelper::env->DeleteLocalRef(capabilitiesClass);
	JNIHelper::env->DeleteLocalRef(capabilities);
}

bool LocalPlayer::isHurt(int ticks)
{
	if (GetCurrentClass() == NULL) return NULL;
	if (hurttimefd == NULL)
		hurttimefd = JNIHelper::env->GetFieldID(GetCurrentClass(), JNIHelper::IsForge() ? "field_70737_aN" : "au", "I");
	int hurtTime = (int)JNIHelper::env->GetIntField(GetCurrentObject(), hurttimefd);
	return (hurtTime > ticks);
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
	jobject mc = LaunchWrapper::getMinecraft().GetCurrentObject();
	jclass mc_class = JNIHelper::env->GetObjectClass(mc);
	jfieldID settings_fid = JNIHelper::env->GetFieldID(mc_class, JNIHelper::IsForge() ? "field_71474_y" : "t", "Lavh;");

	jobject settings_obj = JNIHelper::env->GetObjectField(mc, settings_fid);
	jclass settings_class = JNIHelper::env->GetObjectClass(settings_obj);
	jfieldID binding_fid = JNIHelper::env->GetFieldID(settings_class, "ad", "Lavb;");

	jobject sneak_binding = JNIHelper::env->GetObjectField(settings_obj, binding_fid);
	jclass keybind_class = JNIHelper::env->GetObjectClass(sneak_binding);
	jfieldID pressed_fid = JNIHelper::env->GetFieldID(keybind_class, "h", "Z");

	JNIHelper::env->SetBooleanField(sneak_binding, pressed_fid, state);

	JNIHelper::env->DeleteLocalRef(mc);
	JNIHelper::env->DeleteLocalRef(mc_class);
	JNIHelper::env->DeleteLocalRef(settings_obj);
	JNIHelper::env->DeleteLocalRef(settings_class);
	JNIHelper::env->DeleteLocalRef(sneak_binding);
	JNIHelper::env->DeleteLocalRef(keybind_class);
}




