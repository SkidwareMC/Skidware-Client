#include "antiafk.h"
#include "machip.h"
#include "utils.h"

void antiafk::invoke(std::shared_ptr<c_context> ctx) {

	if (!m_enabled || ctx->local == nullptr || ctx->local->get_object() == nullptr || !timer.has_passed(sdk::get_random(10000, 20000)))
		return;

	timer.reset();

	jclass playerclass = machip::instance->get_env()->GetObjectClass(ctx->local->get_object());
	jmethodID jumpmid = machip::instance->get_env()->GetMethodID(playerclass, "bF", "()V");
	machip::instance->get_env()->CallVoidMethod(ctx->local->get_object(), jumpmid);
	
	machip::instance->get_env()->DeleteLocalRef(playerclass);

}
