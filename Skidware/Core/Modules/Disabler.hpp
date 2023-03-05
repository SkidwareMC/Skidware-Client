#pragma once
#include <map>
#include <string>
#include "../../SDK/LocalPlayer.hpp"
#include "../../SDK/Launchwrapper.hpp"
#include "../Settings.hpp"
#include "../../Wrapper/Utils.hpp"
#include "../../Wrapper/Logger.hpp"
#include "../../Wrapper/timer.h"
#include "Module.hpp"
class Disabler : Module
{
private:

public:
	Disabler();
	static void OnTick();

};