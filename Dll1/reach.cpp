#include "reach.h"

void reach::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane())
		return;

	jobject mc = sdk::instance->get_minecraft();
	jclass mc_class = machip::instance->get_env()->GetObjectClass(mc);
	jfieldID mouseover_fid = machip::instance->get_env()->GetFieldID(mc_class, "s", "Lauh;");

	jobject new_raytrace = ctx->local->raytrace(m_distance);
	//machip::instance->get_env()->SetObjectField(mc, mouseover_fid, new_raytrace);

	wrapper::output(std::to_string(new_raytrace == nullptr));

	machip::instance->get_env()->DeleteLocalRef(mc);
	machip::instance->get_env()->DeleteLocalRef(mc_class);
	machip::instance->get_env()->DeleteLocalRef(new_raytrace);

}
