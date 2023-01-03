#include "velocity.h"
#include "machip.h"

void velocity::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane() || !m_enabled)
		return;

	if (ctx->local->is_hurt()) {
		double motionx = ctx->local->get_motion_x(), motiony = ctx->local->get_motion_y(), motionz = ctx->local->get_motion_z();
		ctx->local->set_motion_x(motionx * m_horizontal_multiplier);
		ctx->local->set_motion_y(motiony * m_vertical_multiplier);
		ctx->local->set_motion_z(motionz * m_horizontal_multiplier);
	}

}
