#include "scaffold.h"
#include "machip.h"


void scaffold::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr;
	};

	if (!is_sane())
		return;

	double motionx = ctx->local->get_motion_x();
	double motionz = ctx->local->get_motion_z();

	if (!m_enabled) {
		//wrapper::output(std::to_string(motionx) + " : " + std::to_string(motionz));
		sdk::instance->mx = motionx;
		sdk::instance->mz = motionz;
		sdk::instance->blockMovement = false;
		return;
	}

	sdk::vec3 location = ctx->local->get_location();

	if (ctx->local->is_jumping() || ctx->local->get_fall_distance() > 2)
		return;

	
	if (ctx->local->is_moving() && ctx->world->is_air_block(location.x, location.y - 1.0, location.z)) {
		if (m_rage) {

		}
		else {
			if (m_sneak) {
				if (!ctx->local->is_sneaking())
					ctx->local->set_sneaking(true);
			}
			else {
				sdk::instance->blockMovement = true;
				if (motionx != 0)
					sdk::instance->mx = 0;
				if (motionz != 0)
					sdk::instance->mz = 0;
			}
		}

	} else {
		if (ctx->local->is_sneaking()) {
			if (timer->has_passed(m_sneak_delay)) {
				ctx->local->set_sneaking(false);
				timer->reset();
			}
		}
		sdk::instance->mx = motionx;
		sdk::instance->mz = motionz;
		sdk::instance->blockMovement = false;
	}

}
