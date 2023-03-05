#include "Reach.hpp"
#include "../../SDK/LaunchWrapper.hpp"
#include "../Settings.hpp"
void Reach::OnTick()
{
	jobject mc = LaunchWrapper::getMinecraft().GetCurrentObject();
	jclass mc_class = JNIHelper::env->GetObjectClass(mc);
	jfieldID mouseover_fid = JNIHelper::env->GetFieldID(mc_class, JNIHelper::IsForge() ? "field_71476_x" : "s", "Lauh;");
	jobject ray = LaunchWrapper::getMinecraft().getLocalPlayer().raytrace(Settings::dist);
	JNIHelper::env->SetObjectField(mc, mouseover_fid, ray);
	printf("Reach \n");
}
