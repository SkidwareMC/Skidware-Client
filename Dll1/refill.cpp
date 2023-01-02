#include "refill.h"
#include "itemstack.h"

void refill::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return !ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane() || !timer->has_passed(m_clear_delay))
		return;

	jobject openctnr_obj = ctx->local->get_open_container();
	jobject invctnr_obj = ctx->local->get_inventory_container();

	jclass ctnr_class = machip::instance->get_env()->FindClass("xy"); // ContainerPlayer
	jfieldID wid_fid = machip::instance->get_env()->GetFieldID(ctnr_class, "d", "I");

	int open_wid = machip::instance->get_env()->GetIntField(openctnr_obj, wid_fid);

	if (!machip::instance->get_env()->IsInstanceOf(openctnr_obj, ctnr_class)) {
		machip::instance->get_env()->DeleteLocalRef(openctnr_obj);
		machip::instance->get_env()->DeleteLocalRef(ctnr_class);
		wrapper::output("is not instanceof!");
		return;
	}

	jfieldID invslots_fid = machip::instance->get_env()->GetFieldID(ctnr_class, "c", "Ljava/util/List;");
	jclass listclass = machip::instance->get_env()->FindClass("java/util/List");
	jmethodID to_array_mid = machip::instance->get_env()->GetMethodID(listclass, "toArray", "()[Ljava/lang/Object;");

	jobject invslots_obj = machip::instance->get_env()->GetObjectField(openctnr_obj, invslots_fid);

	jobjectArray invslots = reinterpret_cast<jobjectArray>(machip::instance->get_env()->CallObjectMethod(invslots_obj, to_array_mid));
	size_t len = machip::instance->get_env()->GetArrayLength(invslots);

	wrapper::output(std::to_string(len) + " len!");

	jmethodID getslot_mid = machip::instance->get_env()->GetMethodID(ctnr_class, "a", "(I)Lyg;");

	auto pick_item = [ctx, openctnr_obj, getslot_mid, open_wid](int slot) {
		jobject slot_obj = machip::instance->get_env()->CallObjectMethod(openctnr_obj, getslot_mid, (jint)slot);
		jclass slot_class = machip::instance->get_env()->GetObjectClass(slot_obj);
		jmethodID getstack_mid = machip::instance->get_env()->GetMethodID(slot_class, "d", "()Lzx;");
		machip::instance->get_env()->DeleteLocalRef(slot_class);
		jobject slotstack_obj = machip::instance->get_env()->CallObjectMethod(slot_obj, getstack_mid);

		itemstack slotstack(slotstack_obj);
		if (slotstack.get_object() != nullptr && slotstack.get_name() != "air")
		{
			ctx->local->window_click(open_wid, slot, 0, 2);
			timer->reset();
		}
	};

	auto close_container = [ctx, ctnr_class, openctnr_obj]() {
		HWND hMcWindow = FindWindow("LWJGL", nullptr);
		SendMessage(hMcWindow, WM_KEYDOWN, VK_ESCAPE, NULL);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		SendMessage(hMcWindow, WM_KEYUP, VK_ESCAPE, NULL);
	};

	auto delete_local_refs = [openctnr_obj, ctnr_class, listclass, invslots_obj, invslots]() {
		machip::instance->get_env()->DeleteLocalRef(openctnr_obj);
		machip::instance->get_env()->DeleteLocalRef(ctnr_class);
		machip::instance->get_env()->DeleteLocalRef(listclass);
		machip::instance->get_env()->DeleteLocalRef(invslots_obj);
		machip::instance->get_env()->DeleteLocalRef(invslots);
	};

	if (idxsToLoop->size() == 0)
	{
		if (was_running)
		{
			if (!m_keep_open)
				close_container();
			was_running = false;
			wrapper::output("stopped running");
			delete_local_refs();
			return;
		}
		else
		{
			for (int i = 0; i < len; i++)
				idxsToLoop->push_back(i);
		}
	}

	if (m_random)
	{
		int rand_idx = (int)sdk::get_random(0, idxsToLoop->size() - 1);
		int rand_slot = idxsToLoop->at(rand_idx);
		pick_item(rand_slot);
		idxsToLoop->erase(idxsToLoop->begin() + rand_idx);
	}
	else
	{
		pick_item(idxsToLoop->at(0));
		idxsToLoop->erase(idxsToLoop->begin());
	}

	was_running = true;

	delete_local_refs();

}
