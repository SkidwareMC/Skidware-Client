#ifndef CFONTRENDERER_HPP_GUARD
#define CFONTRENDERER_HPP_GUARD
#pragma once

#include "common.h"
#include "CIntelligentMappings.hpp"

typedef struct CIntelligentMappings CIntelligentMappings;

typedef struct CFontRenderer {
	void setup();
	void drawString(std::string text, float x, float y, long color);
	void drawStringWithShadow(std::string text, float x, float y, long color);

	bool builtFonts = false;
	HDC fontHDC = nullptr;
private:
	unsigned int _thizFont;
	jobject _klass;
} CFontRenderer;

#endif //CFONTRENDERER_HPP_GUARD
