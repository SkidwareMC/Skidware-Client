#include "CIntelligentMappings.hpp"
#include "wrapper.h"

std::string CIntelligentMappedClass::name() {
	return CCheat::getInstance()->getMinecraftType() == CMinecraftType::FORGE ? this->_names[this->_unmappedName].first : 
		this->_names[this->_unmappedName].second;
}

std::string CIntelligentMappedField::name() {
	return CCheat::getInstance()->getMinecraftType() == CMinecraftType::FORGE ? this->_names[this->_unmappedName].first :
		this->_names[this->_unmappedName].second;
}

std::string CIntelligentMappedField::signature() {
	return CCheat::getInstance()->getMinecraftType() == CMinecraftType::FORGE ? this->_signatures[this->_unmappedSignature].first :
		this->_signatures[this->_unmappedSignature].second;
}

std::string CIntelligentMappedMethod::name() {
	return CCheat::getInstance()->getMinecraftType() == CMinecraftType::FORGE ? this->_names[this->_unmappedName].first :
		this->_names[this->_unmappedName].second;
}

std::string CIntelligentMappedMethod::signature() {
	return CCheat::getInstance()->getMinecraftType() == CMinecraftType::FORGE ? this->_signatures[this->_unmappedSignature].first :
		this->_signatures[this->_unmappedSignature].second;
}

void CIntelligentMappings::init(Version ver) {
	if (ver == ONE_TWELVE_TWO) {

		/*-------------------------*/

		/*        Minecraft        */

		/*-------------------------*/
		out::display("Minecraft");
		Sleep(500);
		CIntelligentMappedField thePlayerField = make_field("player", "Lnet/minecraft/client/entity/EntityPlayerSP;",
			"field_71439_g", "h", "Lnet/minecraft/client/entity/EntityPlayerSP;", "Lbud;");
		CIntelligentMappedField fontRendererField = make_field("fontRenderer", "Lnet/minecraft/client/gui/FontRenderer;",
			"field_71466_p", "k", "Lnet/minecraft/client/gui/FontRenderer", "Lbip;");
		CIntelligentMappedField entityRendererField = make_field("entityRenderer", "Lnet/minecraft/client/renderer/EntityRenderer;",
			"field_71460_t", "o", "Lnet/minecraft/client/renderer/EntityRenderer;", "Lbuq;");
		CIntelligentMappedField gameSettingsField = make_field("gameSettings", "Lnet/minecraft/client/settings/GameSettings;",
			"field_71474_y", "t", "Lnet/minecraft/client/settings/GameSettings;", "Lbid;");
		CIntelligentMappedMethod getMinecraftMethod = make_method("getMinecraft", "()Lnet/minecraft/client/Minecraft;",
			"func_71410_x", "z", "()Lnet/minecraft/client/Minecraft;", "()Lbib;");
		CIntelligentMappedField Minecraft__theWorldField = make_field("world", "Lnet/minecraft/client/multiplayer/WorldClient;",
			"field_71441_e", "f", "Lbsb;", "Lnet/minecraft/client/multiplayer/WorldClient;");
		CIntelligentMappedField playerControllerField = make_field("playerController", "Lnet/minecraft/client/multiplayer/PlayerControllerMP;",
			"field_71442_b", "c", "Lbsa;", "Lnet/minecraft/client/multiplayer/PlayerControllerMP;");
		CIntelligentMappedField isGameHadFocusField = make_field("isGameHasFocus", "Z", "field_71415_G", "w", "Z", "Z");
		CIntelligentMappedClass minecraftKlass = make_klass("net.minecraft.client.Minecraft",
			"net.minecraft.client.Minecraft", "bib", std::vector({ thePlayerField, fontRendererField, entityRendererField,
				gameSettingsField, Minecraft__theWorldField, playerControllerField, isGameHadFocusField }), std::vector({ getMinecraftMethod }));
		_klasses.push_back(minecraftKlass);

		/*-------------------------*/

		/*      EntityPlayerSP     */

		/*-------------------------*/
		out::display("Player");
		Sleep(500);
		CIntelligentMappedField onGroundField = make_field("onGround", "Z",
			"field_70122_E", "z", "Z", "Z");

		CIntelligentMappedField moveForwardField = make_field("moveForward", "F",
			"field_191988_bg", "bg", "F", "F");
		CIntelligentMappedField moveStrafingField = make_field("moveStrafing", "F",
			"field_70702_br", "be", "F", "F");

		CIntelligentMappedField headRotationYawField = make_field("headRotationYaw", "F",
			"field_70759_as", "aP", "F", "F");

		CIntelligentMappedField rotationYawField = make_field("rotationYaw", "F", "field_70177_z", "v", "F", "F");

		CIntelligentMappedField motionXField = make_field("motionX", "D",
			"field_70159_w", "s", "D", "D");
		CIntelligentMappedField motionYField = make_field("motionY", "D",
			"field_70181_x", "t", "D", "D");
		CIntelligentMappedField motionZField = make_field("motionZ", "D",
			"field_70179_y", "u", "D", "D");

		CIntelligentMappedField theWorldField = make_field("world", "Lnet/minecraft/client/multiplayer/WorldClient;",
			"field_70170_p", "l", "Lbsb;", "Lnet/minecraft/client/multiplayer/WorldClient;");

		CIntelligentMappedField movementInputField = make_field("movementInput", "Lnet/minecraft/util/MovementInput;",
			"field_71158_b", "e", "Lnet/minecraft/util/MovementInput;", "Lbub;");

		CIntelligentMappedField inWaterField = make_field("inWater", "Z", "field_70171_ac", "U", "Z", "Z");

		CIntelligentMappedMethod jumpMethod = make_method("jump", "()V",
			"func_70664_aZ", "cu", "()V", "()V");

		CIntelligentMappedField hurttimeField = make_field("hurttime", "I", "field_70737_aN", "ay", "I", "I");

		CIntelligentMappedField speedInAirField = make_field("speedInAir", "F", "field_71102_ce", "bT", "F", "F");

		CIntelligentMappedMethod setSprintMethod = make_method("setSprint", "(Z)V", "func_70031_b", "f", "(Z)V", "(Z)V");

		CIntelligentMappedClass playerKlass = make_klass("net.minecraft.client.entity.EntityPlayerSP",
			"net.minecraft.client.entity.EntityPlayerSP", "bud", std::vector({ onGroundField, moveForwardField,
				moveStrafingField, headRotationYawField, inWaterField, speedInAirField, motionXField, motionYField, motionZField, hurttimeField, rotationYawField, movementInputField, theWorldField}),
			std::vector({ jumpMethod, setSprintMethod }));
		_klasses.push_back(playerKlass);

		/*-------------------------*/

		/*       FontRenderer      */

		/*-------------------------*/
		out::display("FontRender");
		Sleep(500);
		CIntelligentMappedMethod drawStringWithShadowMethod = make_method("drawStringWithShadow", "(Ljava/lang/String;FFI)I",
			"func_175063_a", "a", "(Ljava/lang/String;FFI)I", "(Ljava/lang/String;FFI)I");
		CIntelligentMappedField fontHeightField = make_field("FONT_HEIGHT", "I",
			"field_78288_b", "a", "I", "I");
		CIntelligentMappedClass fontRendererKlass = make_klass("net.minecraft.client.gui.FontRenderer",
			"net.minecraft.client.gui.FontRenderer", "bip", std::vector({ fontHeightField }), std::vector({ drawStringWithShadowMethod }));
		_klasses.push_back(fontRendererKlass);

		/*-------------------------*/

		/*     EntityRenderer      */

		/*-------------------------*/
		out::display("EntityRender");
		Sleep(500);
		CIntelligentMappedMethod setupOverlayRenderingMethod = make_method("setupOverlayRendering", "()V",
			"func_78478_c", "j", "()V", "()V");
		CIntelligentMappedField bossColorModifierPrevField = make_field("bossColorModifierPrev", "F",
			"field_82832_V", "A", "F", "F");
		CIntelligentMappedClass entityRendererKlass = make_klass("net.minecraft.client.renderer.EntityRenderer",
			"net.minecraft.client.renderer.EntityRenderer", "buq", std::vector({ bossColorModifierPrevField }), std::vector({ setupOverlayRenderingMethod }));
		_klasses.push_back(entityRendererKlass);

		/*-------------------------*/

		/*     MovementInput       */

		/*-------------------------*/
		out::display("MoveIn");
		Sleep(500);
		CIntelligentMappedField moveStrafeField = make_field("moveStrafe", "F",
			"field_78902_a", "a", "F", "F");
		CIntelligentMappedField MovementInput__moveForwardField = make_field("moveForward", "F",
			"field_192832_b", "b", "F", "F");
		CIntelligentMappedMethod nullMethod = make_method("(null)", "(null)",
			"(null)", "(null)", "x.x", "Default string");
		CIntelligentMappedClass movementInputKlass = make_klass("net.minecraft.util.MovementInput",
			"net.minecraft.util.MovementInput", "bub", std::vector({ moveStrafeField, moveForwardField }), std::vector({ nullMethod }));
		_klasses.push_back(movementInputKlass);

		/*-------------------------*/

		/*       KeyBinding        */

		/*-------------------------*/
		out::display("KeyBind");
		Sleep(500);
		CIntelligentMappedField pressedField = make_field("pressed", "Z",
			"field_74513_e", "i", "Z", "Z");
		CIntelligentMappedField keyCodeField = make_field("keyCode", "I",
			"field_74512_d", "h", "I", "I");
		CIntelligentMappedMethod isKeyDownMethod = make_method("isKeyDown", "()Z",
			"func_151470_d", "e", "()Z", "()Z");
		CIntelligentMappedClass keyBindingKlass = make_klass("net.minecraft.client.settings.KeyBinding",
			"net.minecraft.client.settings.KeyBinding", "bhy", std::vector({ pressedField, keyCodeField }), std::vector({ isKeyDownMethod }));
		_klasses.push_back(keyBindingKlass);

		/*-------------------------*/

		/*      GameSettings       */

		/*-------------------------*/
		out::display("GameSets");
		Sleep(500);
		CIntelligentMappedField keyBindForwardField = make_field("keyBindForward", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74351_w", "T", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindBackField = make_field("keyBindBack", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74368_y", "V", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindLeftField = make_field("keyBindLeft", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74370_x", "U", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindRightField = make_field("keyBindRight", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74366_z", "W", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindJumpField = make_field("keyBindJump", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74314_A", "X", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindSneakField = make_field("keyBindSneak", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74311_E", "Y", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");

		CIntelligentMappedClass gameSettingsKlass = make_klass("net.minecraft.client.settings.GameSettings",
			"net.minecraft.client.settings.GameSettings", "bid", std::vector({ keyBindForwardField, keyBindBackField,
				keyBindLeftField, keyBindRightField, keyBindJumpField, keyBindSneakField }), std::vector({ nullMethod }));
		_klasses.push_back(gameSettingsKlass);

		/*-------------------------*/

		/*    PlayerController     */

		/*-------------------------*/
		out::display("PlayerCtrl");
		Sleep(500);
		CIntelligentMappedField nullField = make_field("(null)", "(null)",
			"(null)", "(null)", "x.x", "Default string");
		CIntelligentMappedMethod attackEntityMethod = make_method("attackEntity", "(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/entity/Entity;)V",
			"func_78764_a", "a", "(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/entity/Entity;)V", "(Laed;Lvg;)V");
		CIntelligentMappedClass playerControllerKlass = make_klass("net.minecraft.client.multiplayer.PlayerControllerMP",
			"net.minecraft.client.multiplayer.PlayerControllerMP", "bsa", std::vector({ nullField }), std::vector({ attackEntityMethod }));
		_klasses.push_back(playerControllerKlass);

		/*--------------------------*/

		/*       AxisAlignedBB      */

		/*--------------------------*/
		// CIntelligentMappedField isCollidedWithX = make_field("collideWithXPlane")

	}

	/* -------------- */

	/* 1.8.9 Moment   */

	/* -------------- */

	// Readd comments because yes

	/*
	else {
		/*-------------------------*/

		/*        Minecraft        */

		/*------------------------- 
		//Done

		CIntelligentMappedField thePlayerField = make_field("player", "Lnet/minecraft/client/entity/EntityPlayerSP;",
			"field_70475_c", "h", "Lnet/minecraft/client/entity/EntityPlayerSP;", "Lbud;");
		CIntelligentMappedField fontRendererField = make_field("fontRenderer", "Lnet/minecraft/client/gui/FontRenderer;",
			"field_71466_p", "k", "Lnet/minecraft/client/gui/FontRenderer", "Lbip;");
		CIntelligentMappedField entityRendererField = make_field("entityRenderer", "Lnet/minecraft/client/renderer/EntityRenderer;",
			"field_71460_t", "o", "Lnet/minecraft/client/renderer/EntityRenderer;", "Lbuq;");
		CIntelligentMappedField gameSettingsField = make_field("gameSettings", "Lnet/minecraft/client/settings/GameSettings;",
			"field_71474_y", "y", "Lnet/minecraft/client/settings/GameSettings;", "Lbid;");
		CIntelligentMappedMethod getMinecraftMethod = make_method("getMinecraft", "()Lnet/minecraft/client/Minecraft;",
			"func_71410_x", "A", "()Lnet/minecraft/client/Minecraft;", "()Lbib;");
		CIntelligentMappedField Minecraft__theWorldField = make_field("world", "Lnet/minecraft/client/multiplayer/WorldClient;",
			"field_71441_e", "f", "Lbsb;", "Lnet/minecraft/client/multiplayer/WorldClient;");
		CIntelligentMappedField playerControllerField = make_field("playerController", "Lnet/minecraft/client/multiplayer/PlayerControllerMP;",
			"field_71442_b", "c", "Lbsa;", "Lnet/minecraft/client/multiplayer/PlayerControllerMP;");
		CIntelligentMappedField isGameHadFocusField = make_field("isGameHasFocus", "Z", "field_71415_G", "w", "Z", "Z");
		CIntelligentMappedClass minecraftKlass = make_klass("net.minecraft.client.Minecraft",
			"net.minecraft.client.Minecraft", "bib", std::vector({ thePlayerField, fontRendererField, entityRendererField,
				gameSettingsField, Minecraft__theWorldField, playerControllerField }), std::vector({ getMinecraftMethod }));
		_klasses.push_back(minecraftKlass);

		/*-------------------------*/

		/*      EntityPlayerSP     */

		/*-------------------------

		CIntelligentMappedField onGroundField = make_field("onGround", "Z",
			"field_149474_g", "C", "Z", "Z");

		CIntelligentMappedField moveForwardField = make_field("moveForward", "F",
			"field_78900_b", "b", "F", "F");
		CIntelligentMappedField moveStrafingField = make_field("moveStrafing", "F",
			"field_78902_a", "a", "F", "F");

		CIntelligentMappedField rotationYawField = make_field("rotationYaw", "F",
			"field_70177_z", "y", "F", "F");

		CIntelligentMappedField motionXField = make_field("motionX", "D",
			"field_70159_w", "s", "D", "D");
		CIntelligentMappedField motionYField = make_field("motionY", "D",
			"field_70181_x", "t", "D", "D");
		CIntelligentMappedField motionZField = make_field("motionZ", "D",
			"field_70179_y", "u", "D", "D");

		CIntelligentMappedField theWorldField = make_field("world", "Lnet/minecraft/client/multiplayer/WorldClient;",
			"field_70170_p", "l", "Lbsb;", "Lnet/minecraft/client/multiplayer/WorldClient;");

		CIntelligentMappedField movementInputField = make_field("movementInput", "Lnet/minecraft/util/MovementInput;",
			"field_71158_b", "e", "Lnet/minecraft/util/MovementInput;", "Lbub;");

		CIntelligentMappedField hurtTimeField = make_field("hurtTime", "I", "field_70737_aN", "au", "I", "I");

		CIntelligentMappedMethod jumpMethod = make_method("jump", "()V",
			"func_70664_aZ", "cu", "()V", "()V");

		CIntelligentMappedClass playerKlass = make_klass("net.minecraft.client.entity.EntityPlayerSP",
			"net.minecraft.client.entity.EntityPlayerSP", "bud", std::vector({ onGroundField, moveForwardField,
				moveStrafingField, rotationYawField, motionXField, motionYField, motionZField, movementInputField, theWorldField }),
			std::vector({ jumpMethod }));
		_klasses.push_back(playerKlass);

		/*-------------------------*/

		/*       FontRenderer      */

		/*-------------------------

		CIntelligentMappedMethod drawStringWithShadowMethod = make_method("drawStringWithShadow", "(Ljava/lang/String;FFI)I",
			"func_175063_a", "a", "(Ljava/lang/String;FFI)I", "(Ljava/lang/String;FFI)I");
		CIntelligentMappedField fontHeightField = make_field("FONT_HEIGHT", "I",
			"field_78288_b", "a", "I", "I");
		CIntelligentMappedClass fontRendererKlass = make_klass("net.minecraft.client.gui.FontRenderer",
			"net.minecraft.client.gui.FontRenderer", "bip", std::vector({ fontHeightField }), std::vector({ drawStringWithShadowMethod }));
		_klasses.push_back(fontRendererKlass);

		/*-------------------------*/

		/*     EntityRenderer      */

		/*-------------------------

		CIntelligentMappedMethod setupOverlayRenderingMethod = make_method("setupOverlayRendering", "()V",
			"func_78478_c", "j", "()V", "()V");
		CIntelligentMappedField bossColorModifierPrevField = make_field("bossColorModifierPrev", "F",
			"field_82832_V", "A", "F", "F");
		CIntelligentMappedClass entityRendererKlass = make_klass("net.minecraft.client.renderer.EntityRenderer",
			"net.minecraft.client.renderer.EntityRenderer", "buq", std::vector({ bossColorModifierPrevField }), std::vector({ setupOverlayRenderingMethod }));
		_klasses.push_back(entityRendererKlass);

		/*-------------------------*/

		/*     MovementInput       */

		/*-------------------------

		CIntelligentMappedField moveStrafeField = make_field("moveStrafe", "F",
			"field_78902_a", "a", "F", "F");
		CIntelligentMappedField MovementInput__moveForwardField = make_field("moveForward", "F",
			"field_192832_b", "b", "F", "F");
		CIntelligentMappedMethod nullMethod = make_method("(null)", "(null)",
			"(null)", "(null)", "x.x", "Default string");
		CIntelligentMappedClass movementInputKlass = make_klass("net.minecraft.util.MovementInput",
			"net.minecraft.util.MovementInput", "bub", std::vector({ moveStrafeField, moveForwardField }), std::vector({ nullMethod }));
		_klasses.push_back(movementInputKlass);

		/*-------------------------*/

		/*       KeyBinding        */

		/*-------------------------

		CIntelligentMappedField pressedField = make_field("pressed", "Z",
			"field_74513_e", "i", "Z", "Z");
		CIntelligentMappedField keyCodeField = make_field("keyCode", "I",
			"field_74512_d", "h", "I", "I");
		CIntelligentMappedMethod isKeyDownMethod = make_method("isKeyDown", "()Z",
			"func_151470_d", "e", "()Z", "()Z");
		CIntelligentMappedClass keyBindingKlass = make_klass("net.minecraft.client.settings.KeyBinding",
			"net.minecraft.client.settings.KeyBinding", "bhy", std::vector({ pressedField, keyCodeField }), std::vector({ isKeyDownMethod }));
		_klasses.push_back(keyBindingKlass);

		/*-------------------------*/

		/*      GameSettings       */

		/*-------------------------

		CIntelligentMappedField keyBindForwardField = make_field("keyBindForward", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74351_w", "T", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindBackField = make_field("keyBindBack", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74368_y", "V", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindLeftField = make_field("keyBindLeft", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74370_x", "U", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindRightField = make_field("keyBindRight", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74366_z", "W", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindJumpField = make_field("keyBindJump", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74314_A", "X", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");
		CIntelligentMappedField keyBindSneakField = make_field("keyBindSneak", "Lnet/minecraft/client/settings/KeyBinding;",
			"field_74311_E", "Y", "Lnet/minecraft/client/settings/KeyBinding;", "Lbhy;");

		CIntelligentMappedClass gameSettingsKlass = make_klass("net.minecraft.client.settings.GameSettings",
			"net.minecraft.client.settings.GameSettings", "bid", std::vector({ keyBindForwardField, keyBindBackField,
				keyBindLeftField, keyBindRightField, keyBindJumpField, keyBindSneakField }), std::vector({ nullMethod }));
		_klasses.push_back(gameSettingsKlass);

		/*-------------------------*/

		/*    PlayerController     */

		/*-------------------------

		CIntelligentMappedField nullField = make_field("(null)", "(null)",
			"(null)", "(null)", "x.x", "Default string");
		CIntelligentMappedMethod attackEntityMethod = make_method("attackEntity", "(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/entity/Entity;)V",
			"func_78764_a", "a", "(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/entity/Entity;)V", "(Laed;Lvg;)V");
		CIntelligentMappedClass playerControllerKlass = make_klass("net.minecraft.client.multiplayer.PlayerControllerMP",
			"net.minecraft.client.multiplayer.PlayerControllerMP", "bsa", std::vector({ nullField }), std::vector({ attackEntityMethod }));
		_klasses.push_back(playerControllerKlass);
	}
	*/
	
};
