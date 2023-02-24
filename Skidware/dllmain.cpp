#include "Wrapper/Utils.hpp"
#include "Core/Patching.hpp"
#include "Core/Settings.hpp"
#include "Core/GUI.hpp"
#include "SDK/JNIHelper.hpp"
#include "Wrapper/Logger.hpp"
#include "SDK/LaunchWrapper.hpp"
#include "Core/Handler.hpp"
#include <stdio.h>
#include <algorithm>
#include <TlHelp32.h>
#include <iostream>
#include <strsafe.h>
#include <codecvt>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <random>
#include <thread>
#include <string>
#include <Windows.h>
#include <sddl.h>
#include <tchar.h>
#include <unordered_map>
#include <mmsystem.h>
#include <shellapi.h>
#include <process.h>
#include <processthreadsapi.h>
bool dps_string_found = false;
HMODULE HModule;

int cucklord_random_int(int min, int max)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
	return dist6(rng);
}

WCHAR cucklord_random_wchar(int min, int max)
{
	int choose = cucklord_random_int(min, max);
	WCHAR returnme;
	if (choose == 0) { returnme = '0'; }
	if (choose == 1) { returnme = '1'; }
	if (choose == 2) { returnme = '2'; }
	if (choose == 3) { returnme = '3'; }
	if (choose == 4) { returnme = '4'; }
	if (choose == 5) { returnme = '5'; }
	if (choose == 6) { returnme = '6'; }
	if (choose == 7) { returnme = '7'; }
	if (choose == 8) { returnme = '8'; }
	if (choose == 9) { returnme = '9'; }
	if (choose == 10) { returnme = 'a'; }
	if (choose == 11) { returnme = 'b'; }
	if (choose == 12) { returnme = 'c'; }
	if (choose == 13) { returnme = 'd'; }
	if (choose == 14) { returnme = 'e'; }
	if (choose == 15) { returnme = 'f'; }
	if (choose == 16) { returnme = 'g'; }
	if (choose == 17) { returnme = 'h'; }
	if (choose == 18) { returnme = 'i'; }
	if (choose == 19) { returnme = 'j'; }
	if (choose == 20) { returnme = 'k'; }
	if (choose == 21) { returnme = 'l'; }
	if (choose == 22) { returnme = 'm'; }
	if (choose == 23) { returnme = 'n'; }
	if (choose == 24) { returnme = 'o'; }
	if (choose == 25) { returnme = 'p'; }
	if (choose == 26) { returnme = 'q'; }
	if (choose == 27) { returnme = 'r'; }
	if (choose == 28) { returnme = 's'; }
	if (choose == 29) { returnme = 't'; }
	if (choose == 30) { returnme = 'u'; }
	if (choose == 31) { returnme = 'v'; }
	if (choose == 32) { returnme = 'w'; }
	if (choose == 33) { returnme = 'x'; }
	if (choose == 34) { returnme = 'y'; }
	if (choose == 35) { returnme = 'z'; }

	return returnme;
}

DWORD cucklord_get_service_processid(const char* serviceName)
{
	const auto hScm = OpenSCManager(nullptr, nullptr, NULL);
	const auto hSc = OpenService(hScm, serviceName, SERVICE_QUERY_STATUS);
	SERVICE_STATUS_PROCESS ssp = {};
	DWORD bytesNeeded = 0;
	QueryServiceStatusEx(hSc, SC_STATUS_PROCESS_INFO, reinterpret_cast<LPBYTE>(&ssp), sizeof(ssp), &bytesNeeded);
	CloseServiceHandle(hSc);
	CloseServiceHandle(hScm);
	return ssp.dwProcessId;
}

std::string cucklord_get_exe_name()
{
	std::string strAppName;
	std::string strinpathloool;
	char szAppPath[MAX_PATH];
	::GetModuleFileName(0, szAppPath, MAX_PATH);
	strinpathloool = szAppPath;
	strAppName = szAppPath;
	strAppName = strAppName.substr(strAppName.rfind("\\") + 1);
	return strAppName;
}

std::string cucklord_get_exe_path()
{
	std::string strAppName;
	std::string strinpathloool;
	char szAppPath[MAX_PATH];
	::GetModuleFileName(0, szAppPath, MAX_PATH);
	std::string returnme = szAppPath;
	return returnme;
}

void cucklord_destruct_clean_strings_function(DWORD pid, std::vector<const char*> findvector, bool isdps)
{
	bool cucklord_destruct_failed = false;
	int cucklord_destruct_total_cleaned = 0;
	int cucklord_destruct_total_failed = 0;
	bool isjava = false;
	if (pid == GetProcessId((HANDLE)"javaw.exe")) { isjava = true; }
	double processid = pid;
	HANDLE processhandle;
	if (processhandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid))
	{
		MEMORY_BASIC_INFORMATION cucklord_memory;
		INT64 ActAddress = 0;
		INT64 pos = 0;
		while (VirtualQueryEx(processhandle, (LPVOID)ActAddress, &cucklord_memory, sizeof(MEMORY_BASIC_INFORMATION)))
		{
			if (isjava && ActAddress > 0x2000000) { break; }
			if (cucklord_memory.State == MEM_COMMIT && ((cucklord_memory.Protect == PAGE_EXECUTE_READWRITE) | (
				cucklord_memory.Protect == PAGE_READWRITE) | (cucklord_memory.Protect == PAGE_EXECUTE_WRITECOPY) | (
					cucklord_memory.Protect == PAGE_WRITECOPY)))
			{
				std::vector<byte> buffer(cucklord_memory.RegionSize);
				if (ReadProcessMemory(processhandle, (LPVOID)ActAddress, &buffer[0], cucklord_memory.RegionSize, 0))
				{
					for (const char* removeme : findvector)
					{
						INT64 StringLenght = strlen(removeme);
						INT64 BufferSize = static_cast<int>(cucklord_memory.RegionSize);
						for (INT64 i = 0; i <= BufferSize; i++)
						{
							INT64 j;
							for (j = 0; j < StringLenght; j++)
								if (buffer[i + j] != removeme[j])
									break;
							if (j == StringLenght)
							{
								std::string RewriteMem = "";
								if (!WriteProcessMemory(processhandle, (LPVOID)(ActAddress + i), &RewriteMem,
									StringLenght, 0))
								{
									//std::cout << pid << std::endl;
								}
							}
						}
					}
				}
				std::vector<WCHAR> buffer2(cucklord_memory.RegionSize);
				if (ReadProcessMemory(processhandle, (LPVOID)ActAddress, &buffer2[0], cucklord_memory.RegionSize, 0))
				{
					for (const char* removeme : findvector)
					{
						INT64 StringLenght2 = strlen(removeme);
						INT64 BufferSize = static_cast<int>(cucklord_memory.RegionSize);
						for (INT64 i = 0; i <= BufferSize; i++)
						{
							INT64 j;
							for (j = 0; j < StringLenght2; j++)
								if (buffer2[i + j] != removeme[j])
									break;
							if (j == StringLenght2)
							{
								if (isdps)
								{
									dps_string_found = true;
									char container;
									int counter = 0;
									int x = i;
									int loopingint = 0;
									ActAddress = ActAddress - 4;
									for (;;)
									{
										WCHAR writeme = cucklord_random_wchar(0, 35);
										ReadProcessMemory((processhandle), (LPVOID)(ActAddress + x * 2), &container,
											sizeof(char), 0);
										if (container == '!') { counter++; }
										if (!WriteProcessMemory(processhandle, (LPVOID)(ActAddress + x * 2), &writeme,
											(sizeof(WCHAR)), 0)) {
											//std::cout << pid << std::endl;
										}
										x++;
										if (counter == 5) { break; }
									}
								}
								else
								{
									WCHAR RewriteMem = NULL;
									WriteProcessMemory(processhandle, (LPVOID)(ActAddress + i * 2), &RewriteMem,
										(StringLenght2 * 2), 0);
								}
							}
						}
					}
				}
			}
			ActAddress += cucklord_memory.RegionSize;
		}
	}
	if (isdps) { if (!dps_string_found) { system("sc stop DPS"); } }
}

int cleanedprocesses = 0;
std::vector<const char*> exenamevectordps;
std::vector<const char*> exenamevector;
std::vector<const char*> exenamevector2;

void Initialize()
{
    AllocConsole();
    SetConsoleOutputCP(65001);
    freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
    std::string msg = "HEXED | CONSOLE | " + Utils::RandomString(16);
    SetConsoleTitleA(msg.c_str());

    jsize count;
    JavaVM* vm;

    if (JNI_GetCreatedJavaVMs(&vm, 1, &count) == JNI_OK && count > 0)
    {
        jint res = vm->GetEnv((void**)&JNIHelper::env, JNI_VERSION_1_6);
        if (res == JNI_EDETACHED)
        {
            res = vm->AttachCurrentThread((void**)&JNIHelper::env, nullptr);
            Logger::LogDebug("Attached JVM to current Thread");
        }

        if (res == JNI_OK)
        {
            std::string Mappings = JNIHelper::IsForge() ? "FORGE" : "VANILLA";
            Logger::Log("Minecraft running on: " + Mappings);

            Logger::Log("Waiting for World to Initialize...");
            while (LaunchWrapper::getMinecraft().GetCurrentClass() == NULL || LaunchWrapper::getMinecraft().getWorld().GetCurrentClass() == NULL)
            {
                Sleep(1);
            }

            Patching::ApplyPatches();
            while (!Settings::ShouldUninject)
            {
                Handler::OnTick(); // for now 
                Sleep(50);
            }
        }
    }

    ShowWindow(GetConsoleWindow(), SW_HIDE);
    FreeConsole();
    Patching::UnapplyPatches();
    GUI::Delete();
    vm->DetachCurrentThread();
	system("ipconfig /flushdns");
	std::string exename = cucklord_get_exe_name();
	std::string exepath = cucklord_get_exe_path();
	std::string exenamedps = exename + "!";
	exenamevector.push_back(exename.c_str());
	exenamevector.push_back(exepath.c_str());
	exenamevectordps.push_back(exenamedps.c_str());
	system("ipconfig /flushdns");
	std::string prefetchstring = "del \\Windows\\prefetch\\" + exename + "* /F /Q";
	system(prefetchstring.c_str());
	exenamevector2 = exenamevector;
	exenamevector2.push_back(cucklord_get_exe_path().c_str());
	cucklord_destruct_clean_strings_function(cucklord_get_service_processid("PcaSvc"), exenamevector, false);
	cucklord_destruct_clean_strings_function(cucklord_get_service_processid("DPS"), exenamevector, false);
	cucklord_destruct_clean_strings_function(cucklord_get_service_processid("DPS"), exenamevectordps, true);
    FreeLibraryAndExitThread(HModule, 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            HModule = hModule;
            DisableThreadLibraryCalls(HModule);
            const auto thread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Initialize, NULL, NULL, NULL);
            if (thread) CloseHandle(thread);
            break;
    }
    return TRUE;
}

