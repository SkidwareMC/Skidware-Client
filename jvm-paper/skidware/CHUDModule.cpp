#include "CHUDModule.hpp"
#include "CCheat.hpp"
#include "CFlyModule.hpp"
#include "CSpeedModule.hpp"

CHUDModule::CHUDModule() : CModule("HUD", 'H', RENDER) {
	this->toggle();
}

void CHUDModule::onEnable() {
	CCheat::eventBus->registerListener(this);
}

void CHUDModule::onDisable() {
	CCheat::eventBus->unregisterListener(this);
}

std::string MapSpecialKeyToString(int keycode) {
	switch (keycode) {
	case VK_BACK:
		return "BACKSPACE";
		break;
	case VK_TAB:
		return "TAB";
		break;
	case VK_RETURN:
		return "RETURN";
		break;
	case VK_SHIFT:
		return "SHIFT";
		break;
	case VK_CONTROL:
		return "CONTROL";
		break;
	case VK_MENU:
		return "ALT";
		break;
	case VK_PAUSE:
		return "PAUSE";
		break;
	case VK_CAPITAL:
		return "CAPS_LOCK";
		break;
	case VK_SPACE:
		return "SPACE";
		break;
	case VK_PRIOR:
		return "PGUP";
		break;
	case VK_NEXT:
		return "PGDOWN";
		break;
	case VK_END:
		return "END";
		break;
	case VK_HOME:
		//no it does not return you to home :(
		return "HOME";
		break;
	case VK_LEFT:
		return "LEFT";
		break;
	case VK_RIGHT:
		return "RIGHT";
		break;
	case VK_UP:
		return "UP";
		break;
	case VK_DOWN:
		return "DOWN";
		break;
	case VK_SELECT:
		return "SELECT";
		break;
	case VK_PRINT: //basically it is print screen
	case VK_SNAPSHOT:
		return "SYSRQ";
		break;
	case VK_INSERT:
		return "INSERT";
		break;
	case VK_DELETE:
		return "DELETE";
		break;
	case VK_SLEEP:
		return "SLEEP";
		break;
	case VK_NUMPAD0:
		return "NUMPAD0";
		break;
	case VK_NUMPAD1:
		return "NUMPAD1";
		break;
	case VK_NUMPAD2:
		return "NUMPAD2";
		break;
	case VK_NUMPAD3:
		return "NUMPAD3";
		break;
	case VK_NUMPAD4:
		return "NUMPAD4";
		break;
	case VK_NUMPAD5:
		return "NUMPAD5";
		break;
	case VK_NUMPAD6:
		return "NUMPAD6";
		break;
	case VK_NUMPAD7:
		return "NUMPAD7";
		break;
	case VK_NUMPAD8:
		return "NUMPAD8";
		break;
	case VK_NUMPAD9:
		return "NUMPAD9";
		break;
	case VK_MULTIPLY:
		return "MULTIPLY";
		break;
	case VK_ADD:
		return "ADD";
		break;
	case VK_SUBTRACT:
		return "SUBTRACT";
		break;
	case VK_DIVIDE:
		return "DIVIDE";
		break;
	case VK_SCROLL:
		return "SCROLL";
		break;
	case VK_NUMLOCK:
		return "NUMLOCK";
		break;
	case VK_F1:
		return "F1";
		break;
	case VK_F2:
		return "F2";
		break;
	case VK_F3:
		return "F3";
		break;
	case VK_F4:
		return "F4";
		break;
	case VK_F5:
		return "F5";
		break;
	case VK_F6:
		return "F6";
		break;
	case VK_F7:
		return "F7";
		break;
	case VK_F8:
		return "F8";
		break;
	case VK_F9:
		return "F9";
		break;
	case VK_F10:
		return "F10";
		break;
	case VK_F11:
		return "F11";
		break;
	case VK_F12:
		return "F12";
		break;
	case VK_RSHIFT:
		return "RSHIFT";
		break;
	case VK_RCONTROL:
		return "RCONTROL";
		break;
	case VK_RMENU:
		return "RMENU";
		break;
	default:
		return std::string(1, keycode);
		break;
	}
}

void CHUDModule::onEvent(const CSimpleEvent* event) {
	if (auto e = dynamic_cast<const Render2DEvent*>(event)) {
		//DO NOT USE
		//CCheat::theMinecraft->entityRenderer->setupOverlayRendering();
		if (CCheat::theMinecraft->fontRendererObj != nullptr) {
			if (CCheat::theMinecraft->fontRendererObj->GetKlass()) {
				glPushMatrix();
				glScalef(3, 3, 3);
				std::string minecraftType = CCheat::getInstance()->getMinecraftType() == CMinecraftType::FORGE ? "forge" : "vanilla";
				CCheat::theMinecraft->fontRendererObj->drawStringWithShadow("Skidware (" + CCheat::getInstance()->version + "-" + minecraftType + ")", 4, 4, 0x47fff6);
				glPopMatrix();
				float yPos = 25;
				for (CModule* module : CCheat::moduleManager->modules) {
					/*
					if (module->state == false) {
						continue;
					}
					*/

					glPushMatrix();
					glScalef(2, 2, 2);
					CCheat::theMinecraft->fontRendererObj->drawStringWithShadow(module->name + " [" + MapSpecialKeyToString(module->keyBind) + "]", 4,
						yPos, module->state ? 0x4DF77A : 0xF7524D);
					glPopMatrix();
					yPos += 10;
				}
			}
		}
	}
}

void CHUDModule::renderSettings()
{
	return;
}
