#pragma once
//#define WIN32_LEAN_AND_MEAN

#pragma warning(disable: 26812)
#pragma warning(disable: 4311)
#pragma warning(disable: 4099)
#pragma warning(disable: 4091)
#pragma warning(disable: 26451)
#pragma warning(disable: 4302)
#pragma warning(disable: 4715)

#pragma comment(lib, "OpenGL32.lib")

//socket hook
#include <winsock2.h>

//WinAPI
#include <Windows.h>
#include <Winternl.h>
#include <PsApi.h>

//stdlib
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cassert>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//C++
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <map>
#include <type_traits>
#include <functional>
#include <memory>
#include <set>

//JNI
#include "jni.h"
#include "jni_md.h"
#include "jvmti.h"

//MinHook
#include "minhook/MinHook.h"

//OpenGL
#include <gl/GL.h>

//imgui
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_opengl2.h"
#include "imgui/imgui_internal.h"