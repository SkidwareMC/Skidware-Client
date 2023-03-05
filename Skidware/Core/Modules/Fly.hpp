#pragma once
#include <map>
#include <string>
#include "../../SDK/LocalPlayer.hpp"
#include "../../SDK/Launchwrapper.hpp"
#include "../Settings.hpp"
#include "../../Wrapper/timer.h"
#include "Module.hpp"
class Flight : Module
{
private:

public:
	Flight();
	static void OnTick();
};