#pragma once
#include "../JNIHelper.hpp"
#include "../EntityPlayer.hpp"
#include <string>

class MCHelper
{
private:
	
public:
	static EntityPlayer getEntityPlayerByName(std::string);
	static Entity getEntityByName(std::string);
	static std::string JstringToString(jstring);
	static jstring StringToJstring(const char*);
};