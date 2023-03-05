#include "VanillaSpeed.hpp"
#include "../../Wrapper/Logger.hpp"
#include "../../SDK/JNIHelper.hpp"
void VanillaSpeed::OnTick()
{
	if (LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject() == nullptr) return;
	jclass playerclass = JNIHelper::env->GetObjectClass(LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject());
	jfieldID speedairfid = JNIHelper::env->GetFieldID(playerclass, JNIHelper::IsForge() ? "field_71102_ce" : "bF", "F");
	if (Settings::VanillaSpeed == true) {
		JNIHelper::env->SetFloatField(LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject(), speedairfid, (jfloat)(0.02 * (1.0 + Settings::multiplier)));
		LaunchWrapper::getMinecraft().getLocalPlayer().strafe(LaunchWrapper::getMinecraft().getLocalPlayer().getSpeed());
	}
	else
		JNIHelper::env->SetFloatField(LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject(), speedairfid, (jfloat)0.02);

}
