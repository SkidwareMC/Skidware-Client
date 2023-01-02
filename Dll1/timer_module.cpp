#include "timer_module.h"
#include "machip.h"

void timer::invoke(std::shared_ptr<c_context> ctx) {

	jclass mcclass = machip::instance->get_env()->GetObjectClass(sdk::instance->get_minecraft());
	jfieldID timer_fid = machip::instance->get_env()->GetFieldID(mcclass, "Y", "Lavl;");
	
	jobject timer_obj = machip::instance->get_env()->GetObjectField(sdk::instance->get_minecraft(), timer_fid);

	jclass timer_class = machip::instance->get_env()->GetObjectClass(timer_obj);
	jfieldID timer_speed_fid = machip::instance->get_env()->GetFieldID(timer_class, "d", "F");

	if (m_enabled)
		machip::instance->get_env()->SetFloatField(timer_obj, timer_speed_fid, (jfloat)m_multiplier);
	else
		machip::instance->get_env()->SetFloatField(timer_obj, timer_speed_fid, (jfloat)1.0);

	machip::instance->get_env()->DeleteLocalRef(timer_obj);
	machip::instance->get_env()->DeleteLocalRef(timer_class);
	machip::instance->get_env()->DeleteLocalRef(mcclass);

}

void timer::reset(std::shared_ptr<c_context> ctx) {
	jclass mcclass = machip::instance->get_env()->GetObjectClass(sdk::instance->get_minecraft());
	jfieldID timer_fid = machip::instance->get_env()->GetFieldID(mcclass, "Y", "Lavl;");

	jobject timer_obj = machip::instance->get_env()->GetObjectField(sdk::instance->get_minecraft(), timer_fid);

	jclass timer_class = machip::instance->get_env()->GetObjectClass(timer_obj);
	jfieldID timer_speed_fid = machip::instance->get_env()->GetFieldID(timer_class, "d", "F");

	machip::instance->get_env()->SetFloatField(timer_obj, timer_speed_fid, (jfloat)1.0);

	machip::instance->get_env()->DeleteLocalRef(timer_obj);
	machip::instance->get_env()->DeleteLocalRef(timer_class);
	machip::instance->get_env()->DeleteLocalRef(mcclass);
}
