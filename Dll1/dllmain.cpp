#include "includes.h"
#include "machip.h"

void create_machip_thread();

/// Note: this DLL is manually mapped, there's literally NO reason to handle any other call than DLL_PROCESS_ATTACH
/// thread calls are also non-existant, so no reason to use DisableThreadLibraryCalls
/// int __stdcall DllMain(
int __stdcall DllMain(
    HINSTANCE hinstDLL,
    unsigned long     fdwReason,
    void* lpvReserved
) {

    if (fdwReason != DLL_PROCESS_ATTACH)
        return false;

    /// Not necessary to handle the handle to the thread because, no second call I guess.
    wrapper::create_thread(reinterpret_cast<LPTHREAD_START_ROUTINE>(create_machip_thread));

    return true;
}

void create_machip_thread() {
    wrapper::output("Thread started.");
    std::this_thread::sleep_for(std::chrono::seconds(5));

    /// "Bro you know when the object is destroyed" true.
    machip::instance = std::make_unique<machip::c_machip>();

    /// Try to attach, if we fail the attach function will be sure to drop an error message
    if (!machip::instance->attach())
        std::exit(0);

    /// Let's get this started 
    machip::instance->run();

    /// Wait a second actually
    std::this_thread::sleep_for(std::chrono::seconds(1));

    /// Ok now dispose of our shit
    machip::instance->dispose();
}