#include "nofall.h"

void nofall::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane())
		return;

	if (!ctx->local->is_on_ground() && ctx->local->get_fall_distance() >= 4) 
	{
		ctx->local->set_on_ground(true);
		ctx->local->set_fall_distance(0.0f);
	}

}
