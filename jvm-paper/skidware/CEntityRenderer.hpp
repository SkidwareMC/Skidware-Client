#ifndef CENTITYRENDERER_HPP_GUARD
#define CENTITYRENDERER_HPP_GUARD
#pragma once

#include "common.h"
#include "CIntelligentMappings.hpp"

typedef struct CEntityRenderer {
	CEntityRenderer(jobject);
	~CEntityRenderer();
	void setupOverlayRendering();
private:
	jobject _klass;
} CEntityRenderer;

#endif //CENTITYRENDERER_HPP_GUARD
