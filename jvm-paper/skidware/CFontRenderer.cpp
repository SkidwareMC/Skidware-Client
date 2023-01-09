#include "CFontRenderer.hpp"
#include "CCheat.hpp"

/*CFontRenderer::CFontRenderer(jobject klass) : _klass(klass) {
	this->_klass = klass;
	//printf("[DEBUG] [CFontRenderer] this->_klass: 0x%p\n", this->_klass);
}

CFontRenderer::~CFontRenderer() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}*/

void CFontRenderer::setup() {
	this->fontHDC = wglGetCurrentDC();
	this->_thizFont = glGenLists(96);

	HFONT font = CreateFontA(-15, 0, 0, 0, FW_MEDIUM, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, FF_DONTCARE | DEFAULT_PITCH, "Verdana");
	HFONT oldFont = (HFONT)SelectObject(this->fontHDC, font);

	wglUseFontBitmapsA(this->fontHDC, 32, 96, this->_thizFont);
	SelectObject(this->fontHDC, oldFont);
	DeleteObject(font);

	this->builtFonts = true;
}

void CFontRenderer::drawString(std::string text, float x, float y, long color) {
	if (this->builtFonts) {
		float red = (float)(color >> 16 & 255) / 255.0F;
		float blue = (float)(color >> 8 & 255) / 255.0F;
		float green = (float)(color & 255) / 255.0F;
		float alpha = (float)(color >> 24 & 255) / 255.0F;
		glColor4f(red, blue, green, alpha);
		glRasterPos2f(x, y);

		glPushAttrib(GL_LIST_BIT);
		glListBase(this->_thizFont - 32);
		glCallLists(strlen(text.c_str()), GL_UNSIGNED_BYTE, text.c_str());
		glPopAttrib();
	}
}

void CFontRenderer::drawStringWithShadow(std::string text, float x, float y, long color) {
	this->drawString(text, x, y, color + 15295960);
	this->drawString(text, x - 2, y - 2, color);
}