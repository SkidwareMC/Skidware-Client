#include "world.h"
#include "machip.h"

c_world::c_world(jobject obj)
{
	world_obj = obj;
}

c_world::~c_world()
{
	machip::instance->get_env()->DeleteLocalRef(world_obj);
}

jobjectArray c_world::get_world_players()
{

	jclass wclass = machip::instance->get_env()->GetObjectClass(world_obj);
	jfieldID c_playersfid = machip::instance->get_env()->GetFieldID(wclass, "j", "Ljava/util/List;");
	jclass listclass = machip::instance->get_env()->FindClass("java/util/List");
	jmethodID to_array_md = machip::instance->get_env()->GetMethodID(listclass, "toArray", "()[Ljava/lang/Object;");

	jobject objc_players = machip::instance->get_env()->GetObjectField(world_obj, c_playersfid);

	//size_t len = machip::instance->get_env()->GetArrayLength(arrayc_players);

	auto res = reinterpret_cast<jobjectArray>(machip::instance->get_env()->CallObjectMethod(objc_players, to_array_md));

	machip::instance->get_env()->DeleteLocalRef(wclass);
	machip::instance->get_env()->DeleteLocalRef(listclass);
	machip::instance->get_env()->DeleteLocalRef(objc_players);

	return res;

}

jobjectArray c_world::get_world_entities()
{

	jclass wclass = machip::instance->get_env()->GetObjectClass(world_obj);
	jfieldID c_playersfid = machip::instance->get_env()->GetFieldID(wclass, "f", "Ljava/util/List;");
	jclass listclass = machip::instance->get_env()->FindClass("java/util/List");
	jmethodID to_array_md = machip::instance->get_env()->GetMethodID(listclass, "toArray", "()[Ljava/lang/Object;");

	jobject objc_players = machip::instance->get_env()->GetObjectField(world_obj, c_playersfid);

	//size_t len = machip::instance->get_env()->GetArrayLength(arrayc_players);

	auto res = reinterpret_cast<jobjectArray>(machip::instance->get_env()->CallObjectMethod(objc_players, to_array_md));

	machip::instance->get_env()->DeleteLocalRef(wclass);
	machip::instance->get_env()->DeleteLocalRef(listclass);
	machip::instance->get_env()->DeleteLocalRef(objc_players);

	return res;

}

bool c_world::is_air_block(double x, double y, double z) 
{

	jclass bpclass = machip::instance->get_env()->FindClass("cj");
	jmethodID bpmid = machip::instance->get_env()->GetMethodID(bpclass, "<init>", "(DDD)V");
	jobject blockpos = machip::instance->get_env()->NewObject(bpclass, bpmid, (jdouble)x, (jdouble)y, (jdouble)z);

	jclass wclass = machip::instance->get_env()->GetObjectClass(world_obj);
	jmethodID mid = machip::instance->get_env()->GetMethodID(wclass, "d", "(Lcj;)Z");

	bool res = machip::instance->get_env()->CallBooleanMethod(world_obj, mid, blockpos);

	machip::instance->get_env()->DeleteLocalRef(bpclass);
	machip::instance->get_env()->DeleteLocalRef(wclass);
	machip::instance->get_env()->DeleteLocalRef(blockpos);

	return res;

}
