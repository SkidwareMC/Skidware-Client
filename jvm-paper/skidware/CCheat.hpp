#ifndef CCHEAT_HPP_GUARD
#define CCHEAT_HPP_GUARD
#pragma once

#include "common.h"
#include "CMinecraft.hpp"
#include "CMinecraftType.hpp"
#include "CIntelligentMappings.hpp"
#include "CModuleManager.hpp"

struct CMinecraft;

struct CIntelligentMappings;

typedef struct CCheat {
	CCheat(JNIEnv*, JavaVM*);
	static CCheat* getInstance() {
		return theCheat;
	}
	CMinecraftType setMinecraftType() {
		jclass forgeTestKlass = env->FindClass("net/minecraftforge/common/ForgeVersion");
		if (!forgeTestKlass) {
			#ifdef _DEBUG
			printf("[DEBUG] forge test #1 failed\n");
			#endif //_DEBUG
			forgeTestKlass = env->FindClass("net.minecraftforge.common.ForgeVersion");
			if (!forgeTestKlass) {
				#ifdef _DEBUG
				printf("[DEBUG] forge test #2 failed\n");
				#endif //_DEBUG
			} else {
				return CMinecraftType::FORGE;
			}
		} else {
			return CMinecraftType::FORGE;
		}

		return CMinecraftType::VANILLA;
	}
	CMinecraftType getMinecraftType() {
		return this->minecraftType;
	}
private:
	CMinecraftType minecraftType;
	static inline CCheat* theCheat = nullptr;
public:
	JNIEnv* env;
	JavaVM* javavm;
	static inline CMinecraft* theMinecraft = nullptr;
	static inline CModuleManager* moduleManager = nullptr;
	static inline CSimpleEventManager* eventBus = nullptr;
	std::string version = "b0.4"; //alpha
	static inline int timerDelay = 50;
	// static inline Version mcVer = ONE_TWELVE_TWO;
} CCheat;

#endif //CCHEAT_HPP_GUARD
