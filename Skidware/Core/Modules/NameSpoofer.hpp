#pragma once
#include <string>

class NameSpoofer
{
private:
	static std::string OriginalName;

public:
	static void Toggle();
};