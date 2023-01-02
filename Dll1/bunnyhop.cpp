#include "bunnyhop.h"
#include "machip.h"

void bunnyhop::invoke(std::shared_ptr<c_context> ctx) {

	if (ctx->local->get_object() == nullptr)
		return;

	jclass playerclass = machip::instance->get_env()->GetObjectClass(ctx->local->get_object());
	jfieldID speedairfid = machip::instance->get_env()->GetFieldID(playerclass, "bF", "F");

	if (m_enabled)
		machip::instance->get_env()->SetFloatField(ctx->local->get_object(), speedairfid, (jfloat)(0.02 * (6.0 + multiplier)));
	else
		machip::instance->get_env()->SetFloatField(ctx->local->get_object(), speedairfid, (jfloat)0.02);

}

void bunnyhop::reset(std::shared_ptr<c_context> ctx) {

	if (ctx->local->get_object() == nullptr)
		return;

	jclass playerclass = machip::instance->get_env()->GetObjectClass(ctx->local->get_object());
	jfieldID speedairfid = machip::instance->get_env()->GetFieldID(playerclass, "bF", "F");

	machip::instance->get_env()->SetFloatField(ctx->local->get_object(), speedairfid, (jfloat)0.02);

}
