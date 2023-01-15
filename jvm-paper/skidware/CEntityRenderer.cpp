#include "CEntityRenderer.hpp"
#include "CCheat.hpp"

CEntityRenderer::CEntityRenderer(jobject klass) : _klass(klass) {
	this->_klass = klass;
}

CEntityRenderer::~CEntityRenderer() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}

void CEntityRenderer::setupOverlayRendering() {
	CIntelligentMappedClass entityRendererKlass = CIntelligentMappings::getClass("net.minecraft.client.renderer.EntityRenderer");
	CUtils::CallMethod<void>(this->_klass, entityRendererKlass.getMethod("setupOverlayRendering").name(), 
		entityRendererKlass.getMethod("setupOverlayRendering").signature());
}