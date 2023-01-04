#include "killaura.h"
#include "machip.h"

void killaura::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane() || !timer.has_passed(m_delay))
		return;

	timer.reset();

	jobjectArray world_players = m_mobs ? ctx->world->get_world_entities() : ctx->world->get_world_players();

	size_t len = machip::instance->get_env()->GetArrayLength(world_players);

	if (len <= 1)
		return;

	double closest_distance = m_range;
	int players_targeted = 0;
	jobject closest_player = nullptr;

	for (int i = 0; i < len; ++i) {
		if (m_max_targets != 0 && players_targeted == m_max_targets)
			break;

		jobject pj = machip::instance->get_env()->GetObjectArrayElement(world_players, i);
		if (pj == nullptr)
			continue;

		c_player p(pj);
		if (p.get_object() == nullptr)
			continue;

		if (p.get_entity_id() == ctx->local->get_entity_id() || p.get_health() <= 0)
			continue;

		double dist = sdk::calc_distance(ctx->local->get_location(), p.get_location());
		if (dist > 6.0 || dist > m_range)
			continue;

		if (m_hit_closest && dist < closest_distance) {
			closest_distance = dist;
			closest_player = p.get_object();
		}

		if (!m_hit_closest) {
			ctx->local->attackEntity(p.get_object());
			players_targeted++;
		}
	}


	if (m_hit_closest && closest_player != nullptr)
		ctx->local->attackEntity(closest_player);

	machip::instance->get_env()->DeleteLocalRef(world_players);
	machip::instance->get_env()->DeleteLocalRef(closest_player);

}
