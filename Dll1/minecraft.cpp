#include "minecraft.h"
#include "machip.h"
#include <iostream>

std::unique_ptr<sdk::c_minecraft> sdk::instance;

#pragma warning(disable:4996)

jobject sdk::c_minecraft::get_minecraft()
{
	jobject res;
	auto cls = machip::instance->get_env()->FindClass(xorstr_("ave"));
	auto ave = machip::instance->get_env()->GetStaticMethodID(cls, xorstr_("A"), xorstr_("()Lave;"));

	res = machip::instance->get_env()->CallStaticObjectMethod(cls, ave);

	machip::instance->get_env()->DeleteLocalRef(cls);

	return res;
}

jobject sdk::c_minecraft::get_player(jobject mc) {
	jobject res;
	auto cls = machip::instance->get_env()->FindClass(xorstr_("ave"));
	auto player_fid = machip::instance->get_env()->GetFieldID(cls, xorstr_("h"), xorstr_("Lbew;"));

	res = machip::instance->get_env()->GetObjectField(mc, player_fid);

	machip::instance->get_env()->DeleteLocalRef(cls);

	return res;
}

jobject sdk::c_minecraft::get_world(jobject mc) {
	jobject res;
	auto cls = machip::instance->get_env()->FindClass(xorstr_("ave"));
	auto world_fid = machip::instance->get_env()->GetFieldID(cls, xorstr_("f"), xorstr_("Lbdb;"));

	res = machip::instance->get_env()->GetObjectField(mc, world_fid);

	machip::instance->get_env()->DeleteLocalRef(cls);

	return res;
}

jobject sdk::c_minecraft::get_current_screen(jobject mc) {
	jobject res;
	auto cls = machip::instance->get_env()->FindClass(xorstr_("ave"));
	auto current_screen_fid = machip::instance->get_env()->GetFieldID(cls, xorstr_("m"), xorstr_("Laxu;"));

	res = machip::instance->get_env()->GetObjectField(mc, current_screen_fid);

	machip::instance->get_env()->DeleteLocalRef(cls);

	return res;
}
