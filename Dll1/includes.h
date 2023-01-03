#pragma once

#define DEBUG TRUE

#include <Windows.h>
#include <thread>
#include <memory>
#include <chrono>
#include <thread>
#include <string>
#include <unordered_map>
#include <mutex>
#include <functional>
#include <jni.h>
#include <jvmti.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <gl/GL.h>
#include <gl/GLU.h>
#include <MinHook.h>

// IMGUI includes

#include "SDK/xorstr.h"
#include "SDK/wrapper.h"
#include "SDK/utils.h"
#include "SDK/timer.h"
#include "SDK/minecraft.h"
#include "SDK/player.h"
#include "SDK/itemstack.h"
#include "main/machip.h"