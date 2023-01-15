#include "MinecraftFontRenderer.hpp"
#include "CIntelligentMappings.hpp"
#include "CCheat.hpp"

MinecraftFontRenderer::MinecraftFontRenderer(jobject klass, JNIEnv* env) : _klass(klass), env(env) {
	this->_klass = klass;
	this->env = env;
}

MinecraftFontRenderer::~MinecraftFontRenderer() {
	this->env->DeleteLocalRef(this->_klass);
}

long MinecraftFontRenderer::drawStringWithShadow(std::string text, float x, float y, long color) {
	if (this->_klass) {
		CIntelligentMappedClass fontRendererKlass = CIntelligentMappings::getClass("net.minecraft.client.gui.FontRenderer");
		CIntelligentMappedMethod drawStringWithShadowMethod = fontRendererKlass.getMethod("drawStringWithShadow");

		jmethodID mid = this->env->GetMethodID(this->env->GetObjectClass(this->_klass), drawStringWithShadowMethod.name().data(),
			drawStringWithShadowMethod.signature().data());

		jstring java_text = this->env->NewStringUTF(text.c_str());

		while (!mid) {
			mid = this->env->GetMethodID(this->env->GetObjectClass(this->_klass), drawStringWithShadowMethod.name().data(),
				drawStringWithShadowMethod.signature().data());
		}

		return this->env->CallIntMethod(this->_klass, mid, java_text, x, y, color);
	}
}