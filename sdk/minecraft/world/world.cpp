#include "world.h"

#include "../../../main/gasper.h"

c_world::c_world(jobject obj)
{
	world_obj = obj;
}

c_world::~c_world()
{
	gasper::instance->get_env()->DeleteLocalRef(world_obj);
}

jobjectArray c_world::get_world_players()
{

	jclass wclass = gasper::instance->get_env()->GetObjectClass(world_obj);
	jfieldID c_playersfid = gasper::instance->get_env()->GetFieldID(wclass, "j", "Ljava/util/List;");
	jclass listclass = gasper::instance->get_env()->FindClass("java/util/List");
	jmethodID to_array_md = gasper::instance->get_env()->GetMethodID(listclass, "toArray", "()[Ljava/lang/Object;");

	jobject objc_players = gasper::instance->get_env()->GetObjectField(world_obj, c_playersfid);

	//size_t len = gasper::instance->get_env()->GetArrayLength(arrayc_players);

	auto res = reinterpret_cast<jobjectArray>(gasper::instance->get_env()->CallObjectMethod(objc_players, to_array_md));

	gasper::instance->get_env()->DeleteLocalRef(wclass);
	gasper::instance->get_env()->DeleteLocalRef(listclass);
	gasper::instance->get_env()->DeleteLocalRef(objc_players);

	return res;

}

jobjectArray c_world::get_world_entities()
{

	jclass wclass = gasper::instance->get_env()->GetObjectClass(world_obj);
	jfieldID c_playersfid = gasper::instance->get_env()->GetFieldID(wclass, "f", "Ljava/util/List;");
	jclass listclass = gasper::instance->get_env()->FindClass("java/util/List");
	jmethodID to_array_md = gasper::instance->get_env()->GetMethodID(listclass, "toArray", "()[Ljava/lang/Object;");

	jobject objc_players = gasper::instance->get_env()->GetObjectField(world_obj, c_playersfid);

	//size_t len = gasper::instance->get_env()->GetArrayLength(arrayc_players);

	auto res = reinterpret_cast<jobjectArray>(gasper::instance->get_env()->CallObjectMethod(objc_players, to_array_md));

	gasper::instance->get_env()->DeleteLocalRef(wclass);
	gasper::instance->get_env()->DeleteLocalRef(listclass);
	gasper::instance->get_env()->DeleteLocalRef(objc_players);

	return res;

}

bool c_world::is_air_block(double x, double y, double z)
{

	jclass bpclass = gasper::instance->get_env()->FindClass("cj");
	jmethodID bpmid = gasper::instance->get_env()->GetMethodID(bpclass, "<init>", "(DDD)V");
	jobject blockpos = gasper::instance->get_env()->NewObject(bpclass, bpmid, (jdouble)x, (jdouble)y, (jdouble)z);

	jclass wclass = gasper::instance->get_env()->GetObjectClass(world_obj);
	jmethodID mid = gasper::instance->get_env()->GetMethodID(wclass, "d", "(Lcj;)Z");

	bool res = gasper::instance->get_env()->CallBooleanMethod(world_obj, mid, blockpos);

	gasper::instance->get_env()->DeleteLocalRef(bpclass);
	gasper::instance->get_env()->DeleteLocalRef(wclass);
	gasper::instance->get_env()->DeleteLocalRef(blockpos);

	return res;

}


