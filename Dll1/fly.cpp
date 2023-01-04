#include "fly.h"

void fly::invoke(std::shared_ptr<c_context> ctx)
{

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane())
		return;

	jclass playerclass = machip::instance->get_env()->GetObjectClass(ctx->local->get_object());
	jfieldID playercap_fid = machip::instance->get_env()->GetFieldID(playerclass, "bA", "Lwl;");
	
	jobject playercap_obj = machip::instance->get_env()->GetObjectField(ctx->local->get_object(), playercap_fid);
	jclass playercap_class = machip::instance->get_env()->GetObjectClass(playercap_obj);
	jfieldID allowfly_fid = machip::instance->get_env()->GetFieldID(playercap_class, "c", "Z");

	// TODO: bypass em AC

	machip::instance->get_env()->SetBooleanField(playercap_obj, allowfly_fid, m_enabled);
	if (m_enabled)
		ctx->local->set_on_ground(true);

	machip::instance->get_env()->DeleteLocalRef(playerclass);
	machip::instance->get_env()->DeleteLocalRef(playercap_class);
	machip::instance->get_env()->DeleteLocalRef(playercap_obj);

}
