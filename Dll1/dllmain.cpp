#include "includes.h"
#include "machip.h"

HINSTANCE unhook;

void thread()
{
    wrapper::output(xorstr_("Thread Started"));

    std::this_thread::sleep_for(std::chrono::seconds(5));

    machip::instance = std::make_unique<machip::c_machip>();

    if (!machip::instance->attach())
        std::exit(0);

    machip::instance->run();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    machip::instance->destroy();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    FreeLibraryAndExitThread(unhook, 0);
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, unsigned long fdwReason, void* lpvReserved) 
{
    if (fdwReason != DLL_PROCESS_ATTACH)
        return false;

    AllocConsole();
    FILE* pFile;
    freopen_s(&pFile, "conout$", "w", stdout);

    unhook = hinstDLL;
    wrapper::create_thread(reinterpret_cast<LPTHREAD_START_ROUTINE>(thread));

    return true;
}