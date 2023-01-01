#include "player.h"

#include "../../../main/gasper.h"
#include "../axisaligned/axisalignedbb.h"
using std::string;

c_player::c_player(jobject obj)
{
	player_obj = obj;
}

c_player::~c_player()
{
	gasper::instance->get_env()->DeleteLocalRef(player_obj);
}

void c_player::window_click(int windowID, int slotID, int mouseButtonClicked = 0, int mode = 2) {
	jobject mc = sdk::instance->get_minecraft();
	jclass mcclass = gasper::instance->get_env()->GetObjectClass(mc);
	jfieldID playerctrl_fid = gasper::instance->get_env()->GetFieldID(mcclass, "c", "Lbda;");
	jobject playerctrl_obj = gasper::instance->get_env()->GetObjectField(mc, playerctrl_fid);
	jclass playerctrl_class = gasper::instance->get_env()->GetObjectClass(playerctrl_obj);
	jmethodID windowclick_mid = gasper::instance->get_env()->GetMethodID(playerctrl_class, "a", "(IIIILwn;)Lzx;");
	auto obj = gasper::instance->get_env()->CallObjectMethod(playerctrl_obj, windowclick_mid, windowID, slotID, 
		mouseButtonClicked, mode, player_obj);

	gasper::instance->get_env()->DeleteLocalRef(mc);
	gasper::instance->get_env()->DeleteLocalRef(mcclass);
	gasper::instance->get_env()->DeleteLocalRef(playerctrl_obj);
	gasper::instance->get_env()->DeleteLocalRef(playerctrl_class);
	gasper::instance->get_env()->DeleteLocalRef(obj);
}

double c_player::get_motion_x() 
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = gasper::instance->get_env()->GetFieldID(playerclass, "v", "D");
	double x = (double)gasper::instance->get_env()->GetDoubleField(player_obj, xfid);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return x;
}

void c_player::set_motion_x(double x)
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = gasper::instance->get_env()->GetFieldID(playerclass, "v", "D");
	gasper::instance->get_env()->SetDoubleField(player_obj, xfid, (jdouble)x);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
}

double c_player::get_motion_y()
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID yfid = gasper::instance->get_env()->GetFieldID(playerclass, "w", "D");
	double y = (double)gasper::instance->get_env()->GetDoubleField(player_obj, yfid);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return y;
}

void c_player::set_motion_y(double y)
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID yfid = gasper::instance->get_env()->GetFieldID(playerclass, "w", "D");
	gasper::instance->get_env()->SetDoubleField(player_obj, yfid, (jdouble)y);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
}

double c_player::get_motion_z() 
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = gasper::instance->get_env()->GetFieldID(playerclass, "x", "D");
	double z = (double)gasper::instance->get_env()->GetDoubleField(player_obj, xfid);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return z;
}

void c_player::set_motion_z(double z)
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = gasper::instance->get_env()->GetFieldID(playerclass, "x", "D");
	gasper::instance->get_env()->SetDoubleField(player_obj, xfid, (jdouble)z);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
}

bool c_player::is_airborne() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID abfid = gasper::instance->get_env()->GetFieldID(playerclass, "ai", "D");
	auto res = gasper::instance->get_env()->GetBooleanField(player_obj, abfid);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return res;
}

bool c_player::is_jumping() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID jumping_fid = gasper::instance->get_env()->GetFieldID(playerclass, "aY", "Z");
	auto res = gasper::instance->get_env()->GetBooleanField(player_obj, jumping_fid);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return res;
}

bool c_player::is_on_ground() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID onground_fid = gasper::instance->get_env()->GetFieldID(playerclass, "C", "Z");
	auto res = gasper::instance->get_env()->GetBooleanField(player_obj, onground_fid);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return res;
}

void c_player::set_on_ground(bool val) {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID onground_fid = gasper::instance->get_env()->GetFieldID(playerclass, "C", "Z");
	gasper::instance->get_env()->SetBooleanField(player_obj, onground_fid, (jboolean)val);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
}

bool c_player::is_hurt() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID abfid = gasper::instance->get_env()->GetFieldID(playerclass, "au", "I");
	auto res = gasper::instance->get_env()->GetIntField(player_obj, abfid);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return res > 0;
}

bool c_player::is_moving()
{
	return !((get_motion_x() == 0.0) && (get_motion_z() == 0.0));
}

bool c_player::is_blocking()
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jmethodID blockmid = gasper::instance->get_env()->GetMethodID(playerclass, "bW", "()Z");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return (bool)gasper::instance->get_env()->CallBooleanMethod(player_obj, blockmid);
}

bool c_player::is_sneaking()
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID fid = gasper::instance->get_env()->GetFieldID(playerclass, "b", "Lbeu;");

	jobject mvinput_obj = gasper::instance->get_env()->GetObjectField(player_obj, fid);
	jclass mvclass = gasper::instance->get_env()->GetObjectClass(mvinput_obj);
	jfieldID sfid = gasper::instance->get_env()->GetFieldID(mvclass, "d", "Z");
	auto res = gasper::instance->get_env()->GetBooleanField(mvinput_obj, sfid);

	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	gasper::instance->get_env()->DeleteLocalRef(mvclass);
	gasper::instance->get_env()->DeleteLocalRef(mvinput_obj);

	return res;
}

void c_player::set_sneaking(bool val)
{
	jobject mc = sdk::instance->get_minecraft();
	jclass mc_class = gasper::instance->get_env()->GetObjectClass(mc);
	jfieldID settings_fid = gasper::instance->get_env()->GetFieldID(mc_class, "t", "Lavh;");
	
	jobject settings_obj = gasper::instance->get_env()->GetObjectField(mc, settings_fid);
	jclass settings_class = gasper::instance->get_env()->GetObjectClass(settings_obj);
	jfieldID binding_fid = gasper::instance->get_env()->GetFieldID(settings_class, "ad", "Lavb;");
	
	jobject sneak_binding = gasper::instance->get_env()->GetObjectField(settings_obj, binding_fid);
	jclass keybind_class = gasper::instance->get_env()->GetObjectClass(sneak_binding);
	jfieldID pressed_fid = gasper::instance->get_env()->GetFieldID(keybind_class, "h", "Z");

	gasper::instance->get_env()->SetBooleanField(sneak_binding, pressed_fid, val);

	gasper::instance->get_env()->DeleteLocalRef(mc);
	gasper::instance->get_env()->DeleteLocalRef(mc_class);
	gasper::instance->get_env()->DeleteLocalRef(settings_obj);
	gasper::instance->get_env()->DeleteLocalRef(settings_class);
	gasper::instance->get_env()->DeleteLocalRef(sneak_binding);
	gasper::instance->get_env()->DeleteLocalRef(keybind_class);
}

bool c_player::is_breaking_blocks()
{
	jobject mc = sdk::instance->get_minecraft();
	jclass mcc = gasper::instance->get_env()->GetObjectClass(mc);
	jfieldID fid = gasper::instance->get_env()->GetFieldID(mcc, "s", "Lauh;");
	jobject objectMouseOver = gasper::instance->get_env()->GetObjectField(mc, fid);

	if (objectMouseOver != nullptr)
	{
		jclass obj_class = gasper::instance->get_env()->GetObjectClass(objectMouseOver);
		jfieldID typehit_fid = gasper::instance->get_env()->GetFieldID(obj_class, "a", "Lauh$a;");
		jobject typehit_obj = gasper::instance->get_env()->GetObjectField(objectMouseOver, typehit_fid);
		
		jclass enum_class = gasper::instance->get_env()->FindClass("auh$a");
		jmethodID ordinal_mid = gasper::instance->get_env()->GetMethodID(enum_class, "ordinal", "()I");

		jfieldID block_fid = gasper::instance->get_env()->GetStaticFieldID(enum_class, "b", "Lauh$a;");
		jobject typehit_block = gasper::instance->get_env()->GetStaticObjectField(enum_class, block_fid);

		int og_ordinal = gasper::instance->get_env()->CallIntMethod(typehit_obj, ordinal_mid);
		int block_ordinal = gasper::instance->get_env()->CallIntMethod(typehit_block, ordinal_mid);

		gasper::instance->get_env()->DeleteLocalRef(mc);
		gasper::instance->get_env()->DeleteLocalRef(mcc);
		gasper::instance->get_env()->DeleteLocalRef(objectMouseOver);
		gasper::instance->get_env()->DeleteLocalRef(obj_class);
		gasper::instance->get_env()->DeleteLocalRef(typehit_obj);
		gasper::instance->get_env()->DeleteLocalRef(enum_class);
		gasper::instance->get_env()->DeleteLocalRef(typehit_block);

		return block_ordinal == og_ordinal;
	}

	gasper::instance->get_env()->DeleteLocalRef(mc);
	gasper::instance->get_env()->DeleteLocalRef(mcc);

	return true;
}

bool c_player::is_hovering_entity()
{
	jobject mc = sdk::instance->get_minecraft();
	jclass mcc = gasper::instance->get_env()->GetObjectClass(mc);
	jfieldID fid = gasper::instance->get_env()->GetFieldID(mcc, "s", "Lauh;");
	jobject objectMouseOver = gasper::instance->get_env()->GetObjectField(mc, fid);

	if (objectMouseOver != nullptr)
	{
		jclass obj_class = gasper::instance->get_env()->GetObjectClass(objectMouseOver);
		jfieldID typehit_fid = gasper::instance->get_env()->GetFieldID(obj_class, "a", "Lauh$a;");
		jobject typehit_obj = gasper::instance->get_env()->GetObjectField(objectMouseOver, typehit_fid);

		jclass enum_class = gasper::instance->get_env()->FindClass("auh$a");
		jmethodID ordinal_mid = gasper::instance->get_env()->GetMethodID(enum_class, "ordinal", "()I");

		jfieldID entity_fid = gasper::instance->get_env()->GetStaticFieldID(enum_class, "c", "Lauh$a;");
		jobject typehit_entity = gasper::instance->get_env()->GetStaticObjectField(enum_class, entity_fid);

		int og_ordinal = gasper::instance->get_env()->CallIntMethod(typehit_obj, ordinal_mid);
		int block_ordinal = gasper::instance->get_env()->CallIntMethod(typehit_entity, ordinal_mid);

		gasper::instance->get_env()->DeleteLocalRef(mc);
		gasper::instance->get_env()->DeleteLocalRef(mcc);
		gasper::instance->get_env()->DeleteLocalRef(objectMouseOver);
		gasper::instance->get_env()->DeleteLocalRef(obj_class);
		gasper::instance->get_env()->DeleteLocalRef(typehit_obj);
		gasper::instance->get_env()->DeleteLocalRef(enum_class);
		gasper::instance->get_env()->DeleteLocalRef(typehit_entity);

		return block_ordinal == og_ordinal;
	}

	gasper::instance->get_env()->DeleteLocalRef(mc);
	gasper::instance->get_env()->DeleteLocalRef(mcc);

	return true;
}

bool c_player::is_sprinting() 
{
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jmethodID ismid = gasper::instance->get_env()->GetMethodID(playerclass, "aw", "()Z");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return (bool)gasper::instance->get_env()->CallBooleanMethod(player_obj, ismid);
}

int c_player::get_entity_id() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID idfid = gasper::instance->get_env()->GetFieldID(playerclass, "c", "I");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return gasper::instance->get_env()->GetIntField(player_obj, idfid);
}

sdk::vec3d c_player::get_location() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj );
	jfieldID xfid = gasper::instance->get_env()->GetFieldID( playerclass, "s", "D" );
	jfieldID yfid = gasper::instance->get_env()->GetFieldID( playerclass, "t", "D" );
	jfieldID zfid = gasper::instance->get_env()->GetFieldID( playerclass, "u", "D" );

	sdk::vec3d loc {
		gasper::instance->get_env()->GetDoubleField(player_obj, xfid ),
		gasper::instance->get_env()->GetDoubleField(player_obj, yfid ),
		gasper::instance->get_env()->GetDoubleField(player_obj, zfid )
	};

	gasper::instance->get_env()->DeleteLocalRef(playerclass);

	return loc;
}

float c_player::get_fall_distance() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID falldfid = gasper::instance->get_env()->GetFieldID(playerclass, "O", "F");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return gasper::instance->get_env()->GetFloatField(player_obj, falldfid);
}

void c_player::set_fall_distance(float val) {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID falldfid = gasper::instance->get_env()->GetFieldID(playerclass, "O", "F");
	gasper::instance->get_env()->SetFloatField(player_obj, falldfid, (jfloat)val);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
}

jobject c_player::get_open_container() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID opencontainer_fid = gasper::instance->get_env()->GetFieldID(playerclass, "bk", "Lxi;");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return gasper::instance->get_env()->GetObjectField(player_obj, opencontainer_fid);
}

jobject c_player::get_inventory_container() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID invcontainer_fid = gasper::instance->get_env()->GetFieldID(playerclass, "bj", "Lxi;");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return gasper::instance->get_env()->GetObjectField(player_obj, invcontainer_fid);
}

jobject c_player::get_inventory() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID inv_fid = gasper::instance->get_env()->GetFieldID(playerclass, "bi", "Lwm;");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return gasper::instance->get_env()->GetObjectField(player_obj, inv_fid);
}

int c_player::get_current_item_index() {
	jobject playerctrl_obj = get_player_controller();
	jclass playerctrl_class = gasper::instance->get_env()->GetObjectClass(playerctrl_obj);
	jfieldID currentidx_fid = gasper::instance->get_env()->GetFieldID(playerctrl_class, "j", "I");
	auto res = gasper::instance->get_env()->GetIntField(playerctrl_obj, currentidx_fid);
	gasper::instance->get_env()->DeleteLocalRef(playerctrl_class);
	gasper::instance->get_env()->DeleteLocalRef(playerctrl_obj);
	return res;
}

void c_player::set_current_item_index(int idx) {
	jobject playerctrl_obj = get_player_controller();
	jclass playerctrl_class = gasper::instance->get_env()->GetObjectClass(playerctrl_obj);
	jfieldID currentidx_fid = gasper::instance->get_env()->GetFieldID(playerctrl_class, "j", "I");
	gasper::instance->get_env()->SetIntField(playerctrl_obj, currentidx_fid, idx);
	update_player_controller();
	gasper::instance->get_env()->DeleteLocalRef(playerctrl_class);
	gasper::instance->get_env()->DeleteLocalRef(playerctrl_obj);
}

jobject c_player::get_player_controller() {
	jclass mcclass = gasper::instance->get_env()->FindClass(xorstr_("ave"));
	jfieldID controllerfid = gasper::instance->get_env()->GetFieldID(mcclass, "c", "Lbda;");
	gasper::instance->get_env()->DeleteLocalRef(mcclass);
	return gasper::instance->get_env()->GetObjectField(sdk::instance->get_minecraft(), controllerfid);
}

void c_player::attackEntity(jobject entity) {
	jobject pc_obj = get_player_controller();
	jclass pc_class = gasper::instance->get_env()->GetObjectClass(pc_obj);
	jmethodID atmid = gasper::instance->get_env()->GetMethodID(pc_class, "a", "(Lwn;Lpk;)V");
	gasper::instance->get_env()->CallVoidMethod(pc_obj, atmid, player_obj, entity);
	gasper::instance->get_env()->DeleteLocalRef(pc_obj);
	gasper::instance->get_env()->DeleteLocalRef(pc_class);
}

void c_player::update_player_controller() { // TODO: send packet?
	jobject pc_obj = get_player_controller();
	jclass pc_class = gasper::instance->get_env()->GetObjectClass(pc_obj);
	jmethodID update_mid = gasper::instance->get_env()->GetMethodID(pc_class, "e", "()V");
	gasper::instance->get_env()->CallVoidMethod(pc_obj, update_mid);
	gasper::instance->get_env()->DeleteLocalRef(pc_obj);
	gasper::instance->get_env()->DeleteLocalRef(pc_class);
}

void c_player::drop_current_item(bool drop_all = true) {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jmethodID drop_mid = gasper::instance->get_env()->GetMethodID(playerclass, "a", "(Z)Luz;");
	jobject trash = gasper::instance->get_env()->CallObjectMethod(player_obj, drop_mid, drop_all);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	gasper::instance->get_env()->DeleteLocalRef(trash);
}

void c_player::drop_item(itemstack item, bool dropAround) {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jmethodID drop_mid = gasper::instance->get_env()->GetMethodID(playerclass, "a", "(Lzx;ZZ)Luz;");
	jobject trash = gasper::instance->get_env()->CallObjectMethod(player_obj, drop_mid, item.get_object(), dropAround, false);
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	gasper::instance->get_env()->DeleteLocalRef(trash);
}

itemstack c_player::get_current_item() {
	jobject inv_obj = get_inventory();
	jclass inv_class = gasper::instance->get_env()->GetObjectClass(inv_obj);
	jmethodID getcurritem_mid = gasper::instance->get_env()->GetMethodID(inv_class, "h", "()Lzx;");
	itemstack res(gasper::instance->get_env()->CallObjectMethod(inv_obj, getcurritem_mid));
	gasper::instance->get_env()->DeleteLocalRef(inv_obj);
	gasper::instance->get_env()->DeleteLocalRef(inv_class);
	return res;
}

int c_player::get_item_index(string name) {
	int res = -1;

	jobject inv_obj = get_inventory();
	jclass inv_class = gasper::instance->get_env()->GetObjectClass(inv_obj);
	jfieldID maininv_fid = gasper::instance->get_env()->GetFieldID(inv_class, "a", "[Lzx;");
	jobject maininv_obj = gasper::instance->get_env()->GetObjectField(inv_obj, maininv_fid);
	jobjectArray inv_array = reinterpret_cast<jobjectArray>(maininv_obj);

	for (int i = 0; i < 36; ++i)
	{
		jobject istackobj = gasper::instance->get_env()->GetObjectArrayElement(inv_array, i);
		itemstack istack(istackobj);
		if (istack.get_name().find(name) != string::npos)
		{
			res = i;
			break;
		}
	}

	gasper::instance->get_env()->DeleteLocalRef(inv_obj);
	gasper::instance->get_env()->DeleteLocalRef(inv_class);
	gasper::instance->get_env()->DeleteLocalRef(maininv_obj);
	gasper::instance->get_env()->DeleteLocalRef(inv_array);

	return res;
}

float c_player::get_health() {
	jclass playerclass = gasper::instance->get_env()->GetObjectClass(player_obj);
	jmethodID gethealth_mid = gasper::instance->get_env()->GetMethodID(playerclass, "bn", "()F");
	gasper::instance->get_env()->DeleteLocalRef(playerclass);
	return gasper::instance->get_env()->CallFloatMethod(player_obj, gethealth_mid);
}

void c_player::send_use_item(jobject world, jobject itemstack) {
	jobject playerctrl = get_player_controller();
	jclass playerctrl_class = gasper::instance->get_env()->GetObjectClass(playerctrl);
	jmethodID use_mid = gasper::instance->get_env()->GetMethodID(playerctrl_class, "a", "(Lwn;Ladm;Lzx;)Z");
	gasper::instance->get_env()->CallVoidMethod(playerctrl, use_mid, player_obj, world, itemstack);
	gasper::instance->get_env()->DeleteLocalRef(playerctrl);
	gasper::instance->get_env()->DeleteLocalRef(playerctrl_class);
}

jobject c_player::raytrace(float distance) {
	jclass player_class = gasper::instance->get_env()->GetObjectClass(player_obj);
	jmethodID raytrace_mid = gasper::instance->get_env()->GetMethodID(player_class, "a", "(DF)Lauh;");
	gasper::instance->get_env()->DeleteLocalRef(player_class);
	return gasper::instance->get_env()->CallObjectMethod(player_obj, raytrace_mid, 1.0, distance);
}

sdk::vec3d c_player::get_position()
{
	auto player_class = gasper::instance->get_env()->GetObjectClass(player_obj);

	jfieldID pos_x_fid, pos_y_fid, pos_z_fid;

	if (!BADLION_CLIENT) {
		pos_x_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70165_t"), xorstr_("D"));
		pos_y_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70163_u"), xorstr_("D"));
		pos_z_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70161_v"), xorstr_("D"));
	}

	gasper::instance->get_env()->DeleteLocalRef(player_class);

	return sdk::vec3d{
		gasper::instance->get_env()->GetDoubleField(player_obj, pos_x_fid),
		gasper::instance->get_env()->GetDoubleField(player_obj, pos_y_fid),
		gasper::instance->get_env()->GetDoubleField(player_obj, pos_z_fid)
	};
}

void c_player::set_yaw(float yaw)
{
	auto player_class = gasper::instance->get_env()->GetObjectClass(player_obj);

	jfieldID yaw_fid;
	if (!BADLION_CLIENT) {
		yaw_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70177_z"), xorstr_("F"));
	}

	gasper::instance->get_env()->DeleteLocalRef(player_class);

	gasper::instance->get_env()->SetFloatField(player_obj, yaw_fid, yaw);
}

float c_player::get_yaw()
{
	auto player_class = gasper::instance->get_env()->GetObjectClass(player_obj);

	jfieldID yaw_fid;
	if (!BADLION_CLIENT) {
		yaw_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70177_z"), xorstr_("F"));
	}

	gasper::instance->get_env()->DeleteLocalRef(player_class);

	return gasper::instance->get_env()->GetFloatField(player_obj, yaw_fid);
}

void c_player::set_pitch(float pitch)
{
	auto player_class = gasper::instance->get_env()->GetObjectClass(player_obj);

	jfieldID pitch_fid;
	if (!BADLION_CLIENT) {
		pitch_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70125_A"), xorstr_("F"));
	}
	else {
		pitch_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_148936_d"), xorstr_("F"));
	}

	gasper::instance->get_env()->DeleteLocalRef(player_class);

	gasper::instance->get_env()->SetFloatField(player_obj, pitch_fid, pitch);
}

float c_player::get_pitch()
{
	auto player_class = gasper::instance->get_env()->GetObjectClass(player_obj);
	
	jfieldID pitch_fid;
	if (!BADLION_CLIENT) {
		pitch_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70125_A"), xorstr_("F"));
	}
	else {
		pitch_fid = gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_148936_d"), xorstr_("F"));
	}

	gasper::instance->get_env()->DeleteLocalRef(player_class);

	return gasper::instance->get_env()->GetFloatField(player_obj, pitch_fid);
}

std::shared_ptr<c_axisalignedbb> c_player::get_bounding_box()
{
	auto player_class = gasper::instance->get_env()->GetObjectClass(player_obj);
	jfieldID boundingbox_fid;

	boundingbox_fid = BADLION_CLIENT ? gasper::instance->get_env()->GetFieldID(player_class, xorstr_("f"), xorstr_("Laug;")) : gasper::instance->get_env()->GetFieldID(player_class, xorstr_("field_70121_D"), xorstr_("Lnet/minecraft/util/AxisAlignedBB;"));

	gasper::instance->get_env()->DeleteLocalRef(player_class);

	return std::make_shared<c_axisalignedbb>(gasper::instance->get_env()->GetObjectField(player_obj, boundingbox_fid));
}

double c_player::get_distance_to(std::shared_ptr<c_player> other)
{
	auto pos = get_position();
	auto entity_pos = other->get_position();
	return sdk::util::distance(pos.x, pos.y, pos.z, entity_pos.x, entity_pos.y, entity_pos.z);
}


void c_player::setSprint(jboolean sprinting)
{
	jmethodID setSprinting = gasper::instance->get_env()->GetMethodID(gasper::instance->get_env()->GetObjectClass(sdk::instance->get_player(sdk::instance->get_minecraft())), "d", "(Z)V");
	gasper::instance->get_env()->CallBooleanMethod(sdk::instance->get_player(sdk::instance->get_minecraft()), setSprinting, sprinting);
}

void c_player::swingItem()
{
	jmethodID swingItem = gasper::instance->get_env()->GetMethodID(gasper::instance->get_env()->GetObjectClass(sdk::instance->get_player(sdk::instance->get_minecraft())), "bw", "()v");
	gasper::instance->get_env()->CallVoidMethod(sdk::instance->get_player(sdk::instance->get_minecraft()), swingItem);
}

jobject c_player::getCapabilities()
{
	if (!player_obj) return 0;

	jclass playerClass = gasper::instance->get_env()->GetObjectClass(player_obj);

	jfieldID fid = gasper::instance->get_env()->GetFieldID(playerClass, "bA", "Lwl;");
	jobject ret = gasper::instance->get_env()->GetObjectField(player_obj, fid);

	gasper::instance->get_env()->DeleteLocalRef(playerClass);

	return ret;
}

void c_player::setFlying(bool state)
{
	jobject capabilities = getCapabilities();
	if (!capabilities)
	{
		gasper::instance->get_env()->DeleteLocalRef(capabilities);
		return;
	}

	jclass capabilitiesClass = gasper::instance->get_env()->GetObjectClass(capabilities);

	jfieldID fid = gasper::instance->get_env()->GetFieldID(capabilitiesClass, "b", "Z");
	gasper::instance->get_env()->SetBooleanField(capabilities, fid, state);

	gasper::instance->get_env()->DeleteLocalRef(capabilitiesClass);
	gasper::instance->get_env()->DeleteLocalRef(capabilities);
}
