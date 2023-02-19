#include "HitBoxExtender.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

bool HitBoxExtender::NeedReset = false;
float HitBoxExtender::DefaultWidth = 0.6f;
float HitBoxExtender::DefaultHeight = 1.8f;

void HitBoxExtender::OnTick()
{
	if (Settings::HitBoxExtender)
	{
		NeedReset = true;
		for (auto& val : LaunchWrapper::getMinecraft().getWorld().getPlayerList())
		{
			if (JNIHelper::env->IsSameObject(val.GetCurrentObject(), LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject())) continue;
			
			val.SetBoundingBoxWidth(DefaultWidth + Settings::HitBoxWidth);
			val.SetBoundingBoxHeight(DefaultHeight + Settings::HitBoxHeight);
		}
	}

	else if (NeedReset)
	{
		NeedReset = false;
		for (auto& val : LaunchWrapper::getMinecraft().getWorld().getPlayerList())
		{
			if (JNIHelper::env->IsSameObject(val.GetCurrentObject(), LaunchWrapper::getMinecraft().getLocalPlayer().GetCurrentObject())) continue;

			val.SetBoundingBoxWidth(DefaultWidth);
			val.SetBoundingBoxHeight(DefaultHeight);
		}
	}
}