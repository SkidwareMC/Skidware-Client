#include "keep_sprint.h"

void keep_sprint::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane())
		return;

	auto should_work = [ctx]() {
		return ctx->local->is_moving() && !ctx->local->is_blocking() && !ctx->local->is_sneaking();
	};

	if (should_work()) {
		jclass playerclass = machip::instance->get_env()->GetObjectClass(ctx->local->get_object());
		jmethodID ssmid = machip::instance->get_env()->GetMethodID(playerclass, "d", "(Z)V");
		machip::instance->get_env()->CallVoidMethod(ctx->local->get_object(), ssmid, (jboolean)true);
		machip::instance->get_env()->DeleteLocalRef(playerclass);
	}

}
