#include "noslowdown.h"

void noslowdown::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane())
		return;

	// TODO: checar poções na Map da classe EntityLivingBase, filtrar por slowness e se tiver slowness, motion * 1.15

	wrapper::output(std::to_string(ctx->local->get_motion_x()) + " : " + std::to_string(ctx->local->get_motion_z()));

}
