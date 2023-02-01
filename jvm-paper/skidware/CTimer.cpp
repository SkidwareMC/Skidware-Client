#include "CTimer.h"

CTimer::CTimer(jobject klass) : _klass(klass), tickLength(klass, 
	CIntelligentMappings::getClass("net.minecraft.util.Timer").getField("tickLength").name(), "F") {

	this->_klass = klass;

}

CTimer::~CTimer()
{
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}
