#include "Patching.hpp"
#include "../Wrapper/Logger.hpp"
#include "../minhook/MinHook.h"
#include "GUI.hpp"
#include "../SDK/LaunchWrapper.hpp"
#include "Handler.hpp"

typedef void(__cdecl* OnUpdate) (void**, void**);
OnUpdate originalOnUpdate;
OnUpdate patchedOnUpdate;
void OnUpdatePatch(void** p1, void** p2)
{
	originalOnUpdate(p1, p2);
}

typedef void(__cdecl* OnTick) (void**, void**);
OnTick originalOnTick;
OnTick patchedOnTick;
void OnTickPatch(void** p1, void** p2)
{
	originalOnTick(p1, p2);
}

typedef void(__cdecl* SetSprinting) (void**, void**, jboolean);
SetSprinting originalSetSprinting;
SetSprinting patchedSetSprinting;
void SetSprintingPatch(void** t1, void** t2, jboolean state)
{
	originalSetSprinting(t1, t2, state);
}

typedef void(*twglSwapBuffers) (HDC);
twglSwapBuffers originalSwapBuffers;
twglSwapBuffers patchedSwapBuffers;
void SwapBuffersPatch(HDC hDc)
{
	GUI::OnSwapBuffers(hDc);
	originalSwapBuffers(hDc);
}

void Patching::PatchOnUpdate()
{
	MH_STATUS status = MH_UNKNOWN;
	while (status != MH_OK)
	{
		Minecraft minecraftInstance = LaunchWrapper::getMinecraft();
		if (minecraftInstance.GetCurrentClass() == NULL) return;

		jmethodID OnUpdateMethod = JNIHelper::env->GetMethodID(minecraftInstance.GetCurrentClass(), "func_99999_d", "()V"); // maybe i should use func_71411_J instead?
		if (OnUpdateMethod == NULL) return;

		patchedOnUpdate = OnUpdate(*(unsigned __int64*)(*(unsigned __int64*)OnUpdateMethod + 0x40));

		status = MH_CreateHook(patchedOnUpdate, &OnUpdatePatch, (void**)(&originalOnUpdate));
		if (status != MH_OK) Sleep(50);
	}

	Logger::LogDebug("OnUpdate Patched");
}

void Patching::PatchOnTick()
{
	MH_STATUS status = MH_UNKNOWN;
	while (status != MH_OK)
	{
		Minecraft minecraftInstance = LaunchWrapper::getMinecraft();
		if (minecraftInstance.GetCurrentClass() == NULL) return;

		jmethodID OnTickMethod = JNIHelper::env->GetMethodID(minecraftInstance.GetCurrentClass(), "func_71407_l", "()V");
		if (OnTickMethod == NULL) return;

		patchedOnTick = OnTick(*(unsigned __int64*)(*(unsigned __int64*)OnTickMethod + 0x40));

		status = MH_CreateHook(patchedOnTick, &OnTickPatch, (void**)(&originalOnTick));
		if (status != MH_OK) Sleep(50);
	}

	Logger::LogDebug("OnTick Patched");
}

void Patching::PatchSetSprinting()
{
	MH_STATUS status = MH_UNKNOWN;
	while (status != MH_OK)
	{
		Minecraft minecraftInstance = LaunchWrapper::getMinecraft();
		if (minecraftInstance.GetCurrentClass() == NULL) return;

		LocalPlayer localPlayerInstance = LaunchWrapper::getMinecraft().getLocalPlayer();
		if (localPlayerInstance.GetCurrentClass() == NULL) return;

		jmethodID SetSprintingMethod = JNIHelper::env->GetMethodID(localPlayerInstance.GetCurrentClass(), "func_70031_b", "(Z)V");
		if (SetSprintingMethod == NULL) return;

		patchedSetSprinting = SetSprinting(*(unsigned __int64*)(*(unsigned __int64*)SetSprintingMethod + 0x40));

		status = MH_CreateHook(patchedSetSprinting, &SetSprintingPatch, (void**)(&originalSetSprinting));
		if (status != MH_OK) Sleep(50);
	}

	Logger::LogDebug("SetSprinting Patched");
}

void Patching::PatchSwapBuffers()
{
	Logger::LogDebug("Patching swapbuffers...");
	Sleep(100);
	MH_STATUS status = MH_UNKNOWN;
	while (status != MH_OK)
	{
		patchedSwapBuffers = (twglSwapBuffers)GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers");

		status = MH_CreateHook(patchedSwapBuffers, &SwapBuffersPatch, (LPVOID*)&originalSwapBuffers);
		if (status != MH_OK) Sleep(50);
	}

	Logger::LogDebug("SwapBuffers Patched");
}

void Patching::ApplyPatches()
{
	Logger::Log("Initializing Hooks...");
	MH_Initialize();

	PatchSwapBuffers();
	//PatchOnUpdate();
	//PatchOnTick();
	//PatchSetSprinting();

	MH_EnableHook(MH_ALL_HOOKS);
	Logger::LogDebug("Hooks Enabled");
}

void Patching::UnapplyPatches()
{
	MH_DisableHook(MH_ALL_HOOKS);

	MH_Uninitialize();
}