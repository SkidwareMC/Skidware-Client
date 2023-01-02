#include "autoclick.h"

auto hMcWindow = FindWindow("LWJGL", nullptr);

void autoclick::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};


	if (!is_sane())
		return;


    if ((wrapper::get_keystate(VK_LBUTTON) || (m_triggerbot && ctx->local->is_hovering_entity())) && GetForegroundWindow() == hMcWindow) {
        if (m_break_blocks && ctx->local->is_breaking_blocks())
        {
            SendMessage(hMcWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
            return;
        }

        int cps = m_cps;

        if (m_randomize)
            cps += (int)floorf(sdk::get_random(-3, 4));

        if (!m_inventory_check) {
            jobject openctnr_obj = ctx->local->get_open_container();
            jclass ctnr_class = machip::instance->get_env()->GetObjectClass(openctnr_obj);
            jfieldID wid_fid = machip::instance->get_env()->GetFieldID(ctnr_class, "d", "I");
            int open_wid = machip::instance->get_env()->GetIntField(openctnr_obj, wid_fid);

            machip::instance->get_env()->DeleteLocalRef(openctnr_obj);
            machip::instance->get_env()->DeleteLocalRef(ctnr_class);

            if (open_wid > 0)
                return;
        }

        long long delay = (long long)(1000 / (cps - 1));

        SendMessage(hMcWindow, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
        std::this_thread::sleep_for(std::chrono::milliseconds(delay / 2));
        SendMessage(hMcWindow, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
        std::this_thread::sleep_for(std::chrono::milliseconds(delay / 2));
        if (++clicks % 3 == 0 && sdk::get_random(0, 1) <= m_blockhit_chance && ctx->local->is_hovering_entity()) {
            SendMessage(hMcWindow, WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
            std::this_thread::sleep_for(std::chrono::milliseconds(delay / 4));
            SendMessage(hMcWindow, WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
            std::this_thread::sleep_for(std::chrono::milliseconds(delay / 4));
        }

    }

}
