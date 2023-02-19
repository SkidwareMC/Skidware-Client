#pragma once
#pragma warning(disable : 4996)

#include <string>
#include <vector>

class ClientConsole
{
private:
	static std::vector<std::string> LogLines;

public:
	static void Log(std::string text);
	static void ClearLogs();
	static std::vector<std::string> GetLogs();
};