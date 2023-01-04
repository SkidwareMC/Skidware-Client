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
#include <MinHook.h>

// IMGUI includes

#include "xorstr.h"
#include "wrapper.h"
#include "utils.h"
#include "timer.h"