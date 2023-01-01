
#include "itemstack.h"
#include "../../gasper.h"

itemstack::itemstack(jobject obj) {
	item_obj = obj;
}

itemstack::~itemstack() {
	gasper::instance->get_env()->DeleteLocalRef(item_obj);
}

jobject itemstack::get_object() {
	return item_obj;
}

string itemstack::get_name()
{
	if (item_obj == nullptr)
		return "air";
	jobject item_obj = get_item();
	jclass item_class = gasper::instance->get_env()->GetObjectClass(item_obj);
	jfieldID name_fid = gasper::instance->get_env()->GetFieldID(item_class, "l", "Ljava/lang/String;");
	gasper::instance->get_env()->DeleteLocalRef(item_class);
	jobject name_object = gasper::instance->get_env()->GetObjectField(item_obj, name_fid);
	if (name_object == nullptr)
		return "block";
	return (string)gasper::instance->get_env()->GetStringUTFChars((jstring)name_object, 0);
}

jobject itemstack::get_item()
{
	if (item_obj == nullptr)
		return nullptr;
	jclass iclass = gasper::instance->get_env()->GetObjectClass(item_obj);
	jfieldID ifid = gasper::instance->get_env()->GetFieldID(iclass, "d", "Lzw;");
	gasper::instance->get_env()->DeleteLocalRef(iclass);
	return gasper::instance->get_env()->GetObjectField(item_obj, ifid);
}

int itemstack::get_item_damage()
{
	if (item_obj == nullptr)
		return -7;
	jclass klass = gasper::instance->get_env()->GetObjectClass(item_obj);
	jfieldID ifid = gasper::instance->get_env()->GetFieldID(klass, "f", "I");
	gasper::instance->get_env()->DeleteLocalRef(klass);
	return gasper::instance->get_env()->GetIntField(item_obj, ifid);
}