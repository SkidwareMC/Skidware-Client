#include "NameSpoofer.hpp"
#include "../Settings.hpp"
#include "../../SDK/LaunchWrapper.hpp"
#include "../../SDK/Utils/MCHelper.hpp"
#include "../../Wrapper/Logger.hpp"

std::string NameSpoofer::OriginalName = "";

void NameSpoofer::Toggle()
{
	if (Settings::NameSpoof)
	{
		OriginalName = MCHelper::JstringToString(LaunchWrapper::getMinecraft().getSession().GetUsername());
		LaunchWrapper::getMinecraft().getSession().SetUsername(MCHelper::StringToJstring(&Settings::NameSpoofValue));
	}
	else LaunchWrapper::getMinecraft().getSession().SetUsername(MCHelper::StringToJstring(OriginalName.c_str()));
}