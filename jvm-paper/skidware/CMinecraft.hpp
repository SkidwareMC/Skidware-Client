#ifndef CMINECRAFT_HPP_GUARD
#define CMINECRAFT_HPP_GUARD
#pragma once

#include "common.h"
#include "CPlayer.hpp"
#include "CFontRenderer.hpp"
#include "CEntityRenderer.hpp"
#include "MinecraftFontRenderer.hpp"
#include "CGameSettings.hpp"
#include "CWorld.hpp"
#include "CPlayerController.hpp"

typedef struct CWorld CWorld;
typedef struct CPlayer CPlayer;
typedef struct CFontRenderer CFontRenderer;
typedef struct CEntityRenderer CEntityRenderer;
typedef struct MinecraftFontRenderer MinecraftFontRenderer;
typedef struct CGameSettings CGameSettings;
typedef struct CPlayerController CPlayerController;

typedef struct CMinecraft {
	CMinecraft();
	static CMinecraft* getMinecraft();
	jobject getNativeMinecraft();
	jobject getNativePlayer();
	jobject getNativeWorld();
	jobject getNativePlayerController();
	void runTick();
private:
	static CMinecraft* theMinecraft;
public:
	CEntityRenderer* entityRenderer = nullptr;
	CFontRenderer* fontRenderer = nullptr;
	CPlayer* thePlayer = nullptr;
	CGameSettings* gameSettings = nullptr;
	MinecraftFontRenderer* fontRendererObj = nullptr;
	//CWorld* theWorld = nullptr;
	CPlayerController* playerController = nullptr;
} CMinecraft;

#endif //CMINECRAFT_HPP_GUARD
