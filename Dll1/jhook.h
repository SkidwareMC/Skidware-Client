#pragma once
#include "includes.h"

typedef void(__cdecl* runTick) (void**, void**);

namespace jtickhook {

	bool apply();

}