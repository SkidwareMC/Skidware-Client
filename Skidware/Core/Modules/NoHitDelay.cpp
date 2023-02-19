#include "NoHitDelay.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

void NoHitDelay::OnTick()
{
	if (Settings::NoHitDelay) LaunchWrapper::getMinecraft().SetLeftClickDelay(0);
}