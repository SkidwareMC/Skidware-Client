#include "ClientConsole.hpp"
#include <windows.h>
#include "Utils.hpp"

std::vector<std::string> ClientConsole::LogLines;

void ClientConsole::Log(std::string log)
{
	if (LogLines.size() == 50) LogLines.erase(LogLines.begin());

	time_t rawtime;
	time(&rawtime);

	auto ptm = localtime(&rawtime);
	std::string Timetamp = Utils::time_to_string("%H:%M", ptm);

	log = "[" + Timetamp + "] " + log;

	LogLines.push_back(log);
}

void ClientConsole::ClearLogs()
{
	LogLines.clear();
}

std::vector<std::string> ClientConsole::GetLogs()
{
	return LogLines;
}