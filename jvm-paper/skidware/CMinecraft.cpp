#include "CMinecraft.hpp"

#include "CPlayer.hpp"
#include "CUtils.hpp"
#include "CIntelligentMappings.hpp"
#include "CCheat.hpp"
#include "CModule.hpp"

typedef struct CPlayer CPlayer;

CMinecraft* CMinecraft::theMinecraft;
std::vector<CIntelligentMappedClass> CIntelligentMappings::_klasses;

CMinecraft::CMinecraft() {
	theMinecraft = this;
	CIntelligentMappedClass minecraftClass = CIntelligentMappings::getClass("net.minecraft.client.Minecraft");
	jobject thePlayerField = CUtils::GetField<jobject>(getNativeMinecraft(),
		minecraftClass.getField("player").name(), minecraftClass.getField("player").signature());
	if (thePlayerField) {
		this->thePlayer = new CPlayer(thePlayerField);
		if (this->thePlayer->theWorld == nullptr) {
			printf("It seems like you have injected Lightning outside of the world.\n");
		}
	} else {
		printf("It seems like you have injected Lightning outside of the world.\n");
	}
	this->entityRenderer = new CEntityRenderer(CUtils::GetField<jobject>(getNativeMinecraft(),
		minecraftClass.getField("entityRenderer").name(), minecraftClass.getField("entityRenderer").signature()));
	this->gameSettings = new CGameSettings(CUtils::GetField<jobject>(getNativeMinecraft(),
		minecraftClass.getField("gameSettings").name(), minecraftClass.getField("gameSettings").signature()));
	/*jobject theWorldField = this->getNativeWorld();
	if (theWorldField) {
		this->theWorld = new CWorld(theWorldField);
	}*/
	if (this->thePlayer && this->thePlayer->theWorld) {
		this->playerController = new CPlayerController(this->getNativePlayerController());
	}
}

CMinecraft* CMinecraft::getMinecraft() {
	return theMinecraft;
}

jobject CMinecraft::getNativeMinecraft() {
	CIntelligentMappedClass minecraftClass = CIntelligentMappings::getClass("net.minecraft.client.Minecraft");
	jclass minecraftKlass = CCheat::getInstance()->env->FindClass(minecraftClass.name().data());
	if (!minecraftKlass) {
		minecraftKlass = CCheat::getInstance()->env->FindClass(minecraftClass.name().data());
	}
	if (minecraftKlass) {
		return CUtils::template CallStaticMethod<jobject>(minecraftKlass, minecraftClass.getMethod("getMinecraft").name(),
			minecraftClass.getMethod("getMinecraft").signature());
	}
}

jobject CMinecraft::getNativePlayer() {
	CIntelligentMappedClass minecraftClass = CIntelligentMappings::getClass("net.minecraft.client.Minecraft");
	return CUtils::GetField<jobject>(getNativeMinecraft(),
		minecraftClass.getField("player").name(), minecraftClass.getField("player").signature());
}

jobject CMinecraft::getNativeWorld() {
	CIntelligentMappedClass minecraftClass = CIntelligentMappings::getClass("net.minecraft.client.Minecraft");
	return CUtils::GetField<jobject>(getNativeMinecraft(),
		minecraftClass.getField("world").name(), minecraftClass.getField("world").signature());
}

jobject CMinecraft::getNativePlayerController() {
	CIntelligentMappedClass minecraftClass = CIntelligentMappings::getClass("net.minecraft.client.Minecraft");
	return CUtils::GetField<jobject>(getNativeMinecraft(),
		minecraftClass.getField("playerController").name(), minecraftClass.getField("playerController").signature());
}

void CMinecraft::runTick() {
	//making a new instance of the player in case of nullptr
	if (this->thePlayer == nullptr && this->getNativePlayer()) {
		this->thePlayer = new CPlayer(this->getNativePlayer());
	}
	//making a new instance of the world in case of nullptr
	//if (this->theWorld == nullptr && this->getNativeWorld()) {
	//	this->theWorld = new CWorld(this->getNativeWorld());
	//}
	if (this->playerController == nullptr && this->getNativePlayerController()) {
		this->playerController = new CPlayerController(this->getNativePlayerController());
	}
	//to be sure if we have right player instance
	if (this->thePlayer != nullptr && this->getNativePlayer()) {
		if (!CCheat::getInstance()->env->IsSameObject(this->thePlayer->GetKlass(), this->getNativePlayer())) {
			this->thePlayer = new CPlayer(this->getNativePlayer());
		}
	}
	//same but for the world
	//if (this->theWorld != nullptr && this->getNativeWorld()) {
	//	if (!CCheat::getInstance()->env->IsSameObject(this->theWorld->GetKlass(), this->getNativeWorld())) {
	//		this->theWorld = new CWorld(this->getNativeWorld());
	//	}
	//}
	//same but for player controller
	if (this->playerController != nullptr && this->getNativePlayerController()) {
		if (!CCheat::getInstance()->env->IsSameObject(this->playerController->GetKlass(), this->getNativePlayerController())) {
			this->playerController = new CPlayerController(this->getNativePlayerController());
		}
	}
	//if (this->theWorld != nullptr && !this->theWorld->GetKlass()) {
	//	this->theWorld = nullptr;
	//}
	if (this->thePlayer != nullptr && !this->thePlayer->GetKlass()) {
		this->thePlayer = nullptr;
	}
	if (this->playerController != nullptr && !this->playerController->GetKlass()) {
		this->playerController = nullptr;
	}
	//to be sure if the player isn't null
	if (this->thePlayer != nullptr && this->thePlayer->GetKlass()) {
		//if (this->theWorld != nullptr && this->theWorld->GetKlass()) {
			if (CCheat::getInstance()->env->IsSameObject(this->thePlayer->GetKlass(), this->getNativePlayer())) {
				//if (CCheat::getInstance()->env->IsSameObject(this->theWorld->GetKlass(), this->getNativeWorld())) {
					CCheat::eventBus->callEvent(new UpdateEvent());
				//}
			}
		//}
	}
}