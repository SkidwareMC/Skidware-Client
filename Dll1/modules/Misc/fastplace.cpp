#include "fastplace.h"
#include "machip.h"

void fastplace::invoke(std::shared_ptr<c_context> ctx) {

	auto is_sane = [ctx]() {
		return ctx->ingame && ctx->local != nullptr && ctx->local->get_object() != nullptr && ctx->world != nullptr &&
			ctx->world->get_object() != nullptr && m_enabled;
	};

	if (!is_sane())
		return;
	
	jobject mcobj = sdk::instance->get_minecraft();
	jclass mcclass = machip::instance->get_env()->GetObjectClass(mcobj);
	jfieldID fid = machip::instance->get_env()->GetFieldID(mcclass, "ap", "I");
	int delayTimer = (int)machip::instance->get_env()->GetIntField(mcobj, fid);
	if (delayTimer > m_delay)
		machip::instance->get_env()->SetIntField(sdk::instance->get_minecraft(), fid, (jint)m_delay);
	machip::instance->get_env()->DeleteLocalRef(mcclass);
	machip::instance->get_env()->DeleteLocalRef(mcobj);

}
