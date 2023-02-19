#include "NoBuildDelay.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

void NoBuildDelay::OnTick()
{
	if (Settings::NoBuildDelay) LaunchWrapper::getMinecraft().SetRightClickDelay(0);
}