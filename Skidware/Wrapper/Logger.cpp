#include "Logger.hpp"
#include <windows.h>
#include "Utils.hpp"

void Logger::Log(std::string msg)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 3);

	time_t rawtime;
	time(&rawtime);

	auto ptm = localtime(&rawtime);
	std::string Timetamp = Utils::time_to_string("%H:%M:%S", ptm);

	msg = "[" + Timetamp + "]" + " [Skidware] " + msg + "\n";
	std::cout << msg;
}

void Logger::LogWarning(std::string msg)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);

	time_t rawtime;
	time(&rawtime);

	auto ptm = localtime(&rawtime);
	std::string Timetamp = Utils::time_to_string("%H:%M:%S", ptm);

	msg = "[" + Timetamp + "]" + " [Skidware] " + msg + "\n";
	std::cout << msg;
}

void Logger::LogError(std::string msg)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 4);

	time_t rawtime;
	time(&rawtime);

	auto ptm = localtime(&rawtime);
	std::string Timetamp = Utils::time_to_string("%H:%M:%S", ptm);

	msg = "[" + Timetamp + "]" + " [Skidware] " + msg + "\n";
	std::cout << msg;
}

void Logger::LogDebug(std::string msg)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 8);

	time_t rawtime;
	time(&rawtime);

	auto ptm = localtime(&rawtime);
	std::string Timetamp = Utils::time_to_string("%H:%M:%S", ptm);

	msg = "[" + Timetamp + "]" + " [Skidware] " + msg + "\n";
	std::cout << msg;
}