#include "minecraft.h"
#include "../../main/gasper.h"
#include <iostream>

std::unique_ptr<sdk::c_minecraft> sdk::instance;

#pragma warning(disable:4996)

jobject sdk::c_minecraft::get_minecraft()
{
	jobject res;
	auto cls = gasper::instance->get_env()->FindClass(xorstr_("ave"));
	auto ave = gasper::instance->get_env()->GetStaticMethodID(cls, xorstr_("A"), xorstr_("()Lave;"));

	res = gasper::instance->get_env()->CallStaticObjectMethod(cls, ave);

	gasper::instance->get_env()->DeleteLocalRef(cls);

	return res;
}

jobject sdk::c_minecraft::get_player(jobject mc) {
	jobject res;
	auto cls = gasper::instance->get_env()->FindClass(xorstr_("ave"));
	auto player_fid = gasper::instance->get_env()->GetFieldID(cls, xorstr_("h"), xorstr_("Lbew;"));

	res = gasper::instance->get_env()->GetObjectField(mc, player_fid);

	gasper::instance->get_env()->DeleteLocalRef(cls);

	return res;
}

jobject sdk::c_minecraft::get_world(jobject mc) {
	jobject res;
	auto cls = gasper::instance->get_env()->FindClass(xorstr_("ave"));
	auto world_fid = gasper::instance->get_env()->GetFieldID(cls, xorstr_("f"), xorstr_("Lbdb;"));

	res = gasper::instance->get_env()->GetObjectField(mc, world_fid);

	gasper::instance->get_env()->DeleteLocalRef(cls);

	return res;
}

jobject sdk::c_minecraft::get_current_screen(jobject mc) {
	jobject res;
	auto cls = gasper::instance->get_env()->FindClass(xorstr_("ave"));
	auto current_screen_fid = gasper::instance->get_env()->GetFieldID(cls, xorstr_("m"), xorstr_("Laxu;"));

	res = gasper::instance->get_env()->GetObjectField(mc, current_screen_fid);

	gasper::instance->get_env()->DeleteLocalRef(cls);

	return res;
}