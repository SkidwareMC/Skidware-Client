#include "ActiveRenderInfo.hpp"
#include "../Wrapper/Logger.hpp"

ActiveRenderInfo::ActiveRenderInfo(jclass obj)
{
	CurrentClass = obj;
}

jclass ActiveRenderInfo::GetCurrentClass()
{
	if (CurrentClass == NULL) return NULL;
	return CurrentClass;
}