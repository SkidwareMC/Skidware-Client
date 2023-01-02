#include "../headers/clicker.h"
#include "../../../../sdk/minecraft/player/player.h"
#include <windows.h>
#include "../../../gasper.h"
#include "../../../../sdk/minecraft/player/player.h"

HWND hwnd = FindWindowA("LWJGL", nullptr);

void c_player::swingItem()
{
    jmethodID swingItem = gasper::instance->get_env()->GetMethodID(gasper::instance->get_env()->GetObjectClass(sdk::instance->get_player(sdk::instance->get_minecraft())), "bw", "()v");
    gasper::instance->get_env()->CallVoidMethod(sdk::instance->get_player(sdk::instance->get_minecraft()), swingItem);
}

void clicker::invoke(std::shared_ptr<c_context> ctx) {

    /*auto is_sane = [ctx]() {
        return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
            ctx->world->get_object() != nullptr && m_enabled;
    };
        
    if (!is_sane())
        return;
        */

    if (GetAsyncKeyState(VK_LBUTTON) && GetForegroundWindow() == hwnd)
    {

        // What is the point of this???????
        int cps = m_cps;

        if (m_randomize)
            cps += (int)floorf(sdk::util::get_random(-3, 4));

        long long delay = (long long)(1000 / (cps - 1));

    
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));\
        std::this_thread::sleep_for(std::chrono::milliseconds(delay / 2));
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
        std::this_thread::sleep_for(std::chrono::milliseconds(delay / 2));
        /*if (++clicks % 3 == 0 && sdk::util::get_random(0, 1) <= m_blockhit_chance && ctx->local->is_hovering_entity()) {
            SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
            std::this_thread::sleep_for(std::chrono::milliseconds(delay / 4));
            SendMessage(hwnd, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
            std::this_thread::sleep_for(std::chrono::milliseconds(delay / 4));
        }*/
    }
}