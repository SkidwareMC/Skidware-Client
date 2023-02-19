#pragma once
#pragma warning(disable : 4996)

#include <string>

class Logger
{
public:
	static void Log(std::string);
	static void LogWarning(std::string);
	static void LogError(std::string);
	static void LogDebug(std::string);
};