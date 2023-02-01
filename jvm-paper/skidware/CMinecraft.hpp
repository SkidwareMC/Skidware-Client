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
#include "CUniqueReference.hpp"
#include "CTimer.h"

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

	jobject getNativeTimer();

	void runTick();
	std::vector<std::shared_ptr<CPlayer*>> get_players();
	jni_ptr<bool> isGameHasFocus = make_jni_ptr<bool>(this->getNativeMinecraft(), "", "Z");
private:
	static CMinecraft* theMinecraft;
	jobject __klass;
public:
	
	CEntityRenderer* entityRenderer = nullptr;
	CFontRenderer* fontRenderer = nullptr;
	CPlayer* thePlayer = nullptr;
	CGameSettings* gameSettings = nullptr;
	MinecraftFontRenderer* fontRendererObj = nullptr;
	CWorld* theWorld = nullptr;
	CPlayerController* playerController = nullptr;
	CTimer* timer = nullptr;
} CMinecraft;

#endif //CMINECRAFT_HPP_GUARD
