#include "fullbright.h"
#include "machip.h"

void fullbright::invoke(std::shared_ptr<c_context> ctx) {

	if (!m_enabled)
		return;

	jobject mcobj = sdk::instance->get_minecraft();

	jclass mcclass = machip::instance->get_env()->GetObjectClass(mcobj);
	jfieldID gmfid = machip::instance->get_env()->GetFieldID(mcclass, "t", "Lavh;");

	jobject gmobj = machip::instance->get_env()->GetObjectField(mcobj, gmfid);

	jclass gmclass = machip::instance->get_env()->GetObjectClass(gmobj);
	jfieldID gammafid = machip::instance->get_env()->GetFieldID(gmclass, "aJ", "F");

	machip::instance->get_env()->SetFloatField(gmobj, gammafid, (jfloat)1000.0);

	machip::instance->get_env()->DeleteLocalRef(mcclass);
	machip::instance->get_env()->DeleteLocalRef(mcobj);
	machip::instance->get_env()->DeleteLocalRef(gmclass);

}
