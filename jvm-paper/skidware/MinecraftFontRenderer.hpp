#ifndef MINECRAFTFONTRENDERER_HPP_GUARD
#define MINECRAFTFONTRENDERER_HPP_GUARD
#pragma once

#include "common.h"

typedef struct MinecraftFontRenderer {
	MinecraftFontRenderer(jobject, JNIEnv*);
	~MinecraftFontRenderer();
	long drawStringWithShadow(std::string text, float x, float y, long color);
	jobject GetKlass() {
		return this->_klass;
	}
private:
	jobject _klass;
	JNIEnv* env;
} MinecraftFontRenderer;

#endif //MINECRAFTFONTRENDERER_HPP_GUARD
