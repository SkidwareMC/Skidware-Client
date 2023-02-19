#include "PingSpoof.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"

void PingSpoof::OnTick()
{
	if (Settings::PingSpoof) LaunchWrapper::getMinecraft().getLocalPlayer().getNetworkPlayerInfo().SetPing(Settings::PingSpoofValue);
}