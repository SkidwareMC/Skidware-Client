#include "FrameSpoof.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

void FrameSpoof::OnTick()
{
	if (Settings::FrameSpoof) LaunchWrapper::getMinecraft().SetFPS(Settings::FrameSpoofValue); 
}