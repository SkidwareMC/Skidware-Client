#include "autosoup.h"

void autosoup::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane() || ctx->local->get_health() >= m_life_required || !timer->has_passed(50))
		return;

	timer->reset();

	int mushIdx = ctx->local->get_item_index("mushroomStew");

	if (!(mushIdx >= 0 && mushIdx <= 9))
		return;

	ctx->local->set_current_item_index(mushIdx);
	ctx->local->send_use_item(ctx->world->get_object(), ctx->local->get_current_item().get_object());
	ctx->local->drop_current_item(true);

}
