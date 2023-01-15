#include "CGameSettings.hpp"
#include "CCheat.hpp"

CGameSettings::CGameSettings(jobject klass) : _klass(klass) {
	this->_klass = klass;
	CIntelligentMappedClass gameSettingsKlass = CIntelligentMappings::getClass("net.minecraft.client.settings.GameSettings");
	this->keyBindForward = new CKeyBinding(CUtils::GetField<jobject>(klass,
		gameSettingsKlass.getField("keyBindForward").name(), gameSettingsKlass.getField("keyBindForward").signature()));
	this->keyBindBack = new CKeyBinding(CUtils::GetField<jobject>(klass,
		gameSettingsKlass.getField("keyBindBack").name(), gameSettingsKlass.getField("keyBindBack").signature()));
	this->keyBindLeft = new CKeyBinding(CUtils::GetField<jobject>(klass,
		gameSettingsKlass.getField("keyBindLeft").name(), gameSettingsKlass.getField("keyBindLeft").signature()));
	this->keyBindRight = new CKeyBinding(CUtils::GetField<jobject>(klass,
		gameSettingsKlass.getField("keyBindRight").name(), gameSettingsKlass.getField("keyBindRight").signature()));
	this->keyBindJump = new CKeyBinding(CUtils::GetField<jobject>(klass,
		gameSettingsKlass.getField("keyBindJump").name(), gameSettingsKlass.getField("keyBindJump").signature()));
	this->keyBindSneak = new CKeyBinding(CUtils::GetField<jobject>(klass,
		gameSettingsKlass.getField("keyBindSneak").name(), gameSettingsKlass.getField("keyBindSneak").signature()));
}

CGameSettings::~CGameSettings() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}

bool CGameSettings::isAnyKeyDown() {
	return this->keyBindForward->pressed || this->keyBindBack->pressed || this->keyBindLeft->pressed || this->keyBindRight->pressed;
}