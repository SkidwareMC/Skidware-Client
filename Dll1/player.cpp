#include "player.h"
#include "machip.h"

using std::string;

c_player::c_player(jobject obj)
{
	player_obj = obj;
}

c_player::~c_player()
{
	machip::instance->get_env()->DeleteLocalRef(player_obj);
}

void c_player::window_click(int windowID, int slotID, int mouseButtonClicked = 0, int mode = 2) {
	jobject mc = sdk::instance->get_minecraft();
	jclass mcclass = machip::instance->get_env()->GetObjectClass(mc);
	jfieldID playerctrl_fid = machip::instance->get_env()->GetFieldID(mcclass, "c", "Lbda;");
	jobject playerctrl_obj = machip::instance->get_env()->GetObjectField(mc, playerctrl_fid);
	jclass playerctrl_class = machip::instance->get_env()->GetObjectClass(playerctrl_obj);
	jmethodID windowclick_mid = machip::instance->get_env()->GetMethodID(playerctrl_class, "a", "(IIIILwn;)Lzx;");
	auto obj = machip::instance->get_env()->CallObjectMethod(playerctrl_obj, windowclick_mid, windowID, slotID, 
		mouseButtonClicked, mode, player_obj);

	machip::instance->get_env()->DeleteLocalRef(mc);
	machip::instance->get_env()->DeleteLocalRef(mcclass);
	machip::instance->get_env()->DeleteLocalRef(playerctrl_obj);
	machip::instance->get_env()->DeleteLocalRef(playerctrl_class);
	machip::instance->get_env()->DeleteLocalRef(obj);
}

double c_player::get_motion_x() 
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = machip::instance->get_env()->GetFieldID(playerclass, "v", "D");
	double x = (double)machip::instance->get_env()->GetDoubleField(player_obj, xfid);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return x;
}

void c_player::set_motion_x(double x)
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = machip::instance->get_env()->GetFieldID(playerclass, "v", "D");
	machip::instance->get_env()->SetDoubleField(player_obj, xfid, (jdouble)x);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
}

double c_player::get_motion_y()
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID yfid = machip::instance->get_env()->GetFieldID(playerclass, "w", "D");
	double y = (double)machip::instance->get_env()->GetDoubleField(player_obj, yfid);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return y;
}

void c_player::set_motion_y(double y)
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID yfid = machip::instance->get_env()->GetFieldID(playerclass, "w", "D");
	machip::instance->get_env()->SetDoubleField(player_obj, yfid, (jdouble)y);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
}

double c_player::get_motion_z() 
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = machip::instance->get_env()->GetFieldID(playerclass, "x", "D");
	double z = (double)machip::instance->get_env()->GetDoubleField(player_obj, xfid);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return z;
}

void c_player::set_motion_z(double z)
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID xfid = machip::instance->get_env()->GetFieldID(playerclass, "x", "D");
	machip::instance->get_env()->SetDoubleField(player_obj, xfid, (jdouble)z);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
}

bool c_player::is_airborne() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID abfid = machip::instance->get_env()->GetFieldID(playerclass, "ai", "D");
	auto res = machip::instance->get_env()->GetBooleanField(player_obj, abfid);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return res;
}

bool c_player::is_jumping() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID jumping_fid = machip::instance->get_env()->GetFieldID(playerclass, "aY", "Z");
	auto res = machip::instance->get_env()->GetBooleanField(player_obj, jumping_fid);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return res;
}

bool c_player::is_on_ground() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID onground_fid = machip::instance->get_env()->GetFieldID(playerclass, "C", "Z");
	auto res = machip::instance->get_env()->GetBooleanField(player_obj, onground_fid);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return res;
}

void c_player::set_on_ground(bool val) {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID onground_fid = machip::instance->get_env()->GetFieldID(playerclass, "C", "Z");
	machip::instance->get_env()->SetBooleanField(player_obj, onground_fid, (jboolean)val);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
}

bool c_player::is_hurt() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID abfid = machip::instance->get_env()->GetFieldID(playerclass, "au", "I");
	auto res = machip::instance->get_env()->GetIntField(player_obj, abfid);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return res > 0;
}

bool c_player::is_moving()
{
	return !((get_motion_x() == 0.0) && (get_motion_z() == 0.0));
}

bool c_player::is_blocking()
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jmethodID blockmid = machip::instance->get_env()->GetMethodID(playerclass, "bW", "()Z");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return (bool)machip::instance->get_env()->CallBooleanMethod(player_obj, blockmid);
}

bool c_player::is_sneaking()
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID fid = machip::instance->get_env()->GetFieldID(playerclass, "b", "Lbeu;");

	jobject mvinput_obj = machip::instance->get_env()->GetObjectField(player_obj, fid);
	jclass mvclass = machip::instance->get_env()->GetObjectClass(mvinput_obj);
	jfieldID sfid = machip::instance->get_env()->GetFieldID(mvclass, "d", "Z");
	auto res = machip::instance->get_env()->GetBooleanField(mvinput_obj, sfid);

	machip::instance->get_env()->DeleteLocalRef(playerclass);
	machip::instance->get_env()->DeleteLocalRef(mvclass);
	machip::instance->get_env()->DeleteLocalRef(mvinput_obj);

	return res;
}

void c_player::set_sneaking(bool val)
{
	jobject mc = sdk::instance->get_minecraft();
	jclass mc_class = machip::instance->get_env()->GetObjectClass(mc);
	jfieldID settings_fid = machip::instance->get_env()->GetFieldID(mc_class, "t", "Lavh;");
	
	jobject settings_obj = machip::instance->get_env()->GetObjectField(mc, settings_fid);
	jclass settings_class = machip::instance->get_env()->GetObjectClass(settings_obj);
	jfieldID binding_fid = machip::instance->get_env()->GetFieldID(settings_class, "ad", "Lavb;");
	
	jobject sneak_binding = machip::instance->get_env()->GetObjectField(settings_obj, binding_fid);
	jclass keybind_class = machip::instance->get_env()->GetObjectClass(sneak_binding);
	jfieldID pressed_fid = machip::instance->get_env()->GetFieldID(keybind_class, "h", "Z");

	machip::instance->get_env()->SetBooleanField(sneak_binding, pressed_fid, val);

	machip::instance->get_env()->DeleteLocalRef(mc);
	machip::instance->get_env()->DeleteLocalRef(mc_class);
	machip::instance->get_env()->DeleteLocalRef(settings_obj);
	machip::instance->get_env()->DeleteLocalRef(settings_class);
	machip::instance->get_env()->DeleteLocalRef(sneak_binding);
	machip::instance->get_env()->DeleteLocalRef(keybind_class);
}

bool c_player::is_breaking_blocks()
{
	jobject mc = sdk::instance->get_minecraft();
	jclass mcc = machip::instance->get_env()->GetObjectClass(mc);
	jfieldID fid = machip::instance->get_env()->GetFieldID(mcc, "s", "Lauh;");
	jobject objectMouseOver = machip::instance->get_env()->GetObjectField(mc, fid);

	if (objectMouseOver != nullptr)
	{
		jclass obj_class = machip::instance->get_env()->GetObjectClass(objectMouseOver);
		jfieldID typehit_fid = machip::instance->get_env()->GetFieldID(obj_class, "a", "Lauh$a;");
		jobject typehit_obj = machip::instance->get_env()->GetObjectField(objectMouseOver, typehit_fid);
		
		jclass enum_class = machip::instance->get_env()->FindClass("auh$a");
		jmethodID ordinal_mid = machip::instance->get_env()->GetMethodID(enum_class, "ordinal", "()I");

		jfieldID block_fid = machip::instance->get_env()->GetStaticFieldID(enum_class, "b", "Lauh$a;");
		jobject typehit_block = machip::instance->get_env()->GetStaticObjectField(enum_class, block_fid);

		int og_ordinal = machip::instance->get_env()->CallIntMethod(typehit_obj, ordinal_mid);
		int block_ordinal = machip::instance->get_env()->CallIntMethod(typehit_block, ordinal_mid);

		machip::instance->get_env()->DeleteLocalRef(mc);
		machip::instance->get_env()->DeleteLocalRef(mcc);
		machip::instance->get_env()->DeleteLocalRef(objectMouseOver);
		machip::instance->get_env()->DeleteLocalRef(obj_class);
		machip::instance->get_env()->DeleteLocalRef(typehit_obj);
		machip::instance->get_env()->DeleteLocalRef(enum_class);
		machip::instance->get_env()->DeleteLocalRef(typehit_block);

		return block_ordinal == og_ordinal;
	}

	machip::instance->get_env()->DeleteLocalRef(mc);
	machip::instance->get_env()->DeleteLocalRef(mcc);

	return true;
}

bool c_player::is_hovering_entity()
{
	jobject mc = sdk::instance->get_minecraft();
	jclass mcc = machip::instance->get_env()->GetObjectClass(mc);
	jfieldID fid = machip::instance->get_env()->GetFieldID(mcc, "s", "Lauh;");
	jobject objectMouseOver = machip::instance->get_env()->GetObjectField(mc, fid);

	if (objectMouseOver != nullptr)
	{
		jclass obj_class = machip::instance->get_env()->GetObjectClass(objectMouseOver);
		jfieldID typehit_fid = machip::instance->get_env()->GetFieldID(obj_class, "a", "Lauh$a;");
		jobject typehit_obj = machip::instance->get_env()->GetObjectField(objectMouseOver, typehit_fid);

		jclass enum_class = machip::instance->get_env()->FindClass("auh$a");
		jmethodID ordinal_mid = machip::instance->get_env()->GetMethodID(enum_class, "ordinal", "()I");

		jfieldID entity_fid = machip::instance->get_env()->GetStaticFieldID(enum_class, "c", "Lauh$a;");
		jobject typehit_entity = machip::instance->get_env()->GetStaticObjectField(enum_class, entity_fid);

		int og_ordinal = machip::instance->get_env()->CallIntMethod(typehit_obj, ordinal_mid);
		int block_ordinal = machip::instance->get_env()->CallIntMethod(typehit_entity, ordinal_mid);

		machip::instance->get_env()->DeleteLocalRef(mc);
		machip::instance->get_env()->DeleteLocalRef(mcc);
		machip::instance->get_env()->DeleteLocalRef(objectMouseOver);
		machip::instance->get_env()->DeleteLocalRef(obj_class);
		machip::instance->get_env()->DeleteLocalRef(typehit_obj);
		machip::instance->get_env()->DeleteLocalRef(enum_class);
		machip::instance->get_env()->DeleteLocalRef(typehit_entity);

		return block_ordinal == og_ordinal;
	}

	machip::instance->get_env()->DeleteLocalRef(mc);
	machip::instance->get_env()->DeleteLocalRef(mcc);

	return true;
}

bool c_player::is_sprinting() 
{
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jmethodID ismid = machip::instance->get_env()->GetMethodID(playerclass, "aw", "()Z");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return (bool)machip::instance->get_env()->CallBooleanMethod(player_obj, ismid);
}

int c_player::get_entity_id() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID idfid = machip::instance->get_env()->GetFieldID(playerclass, "c", "I");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return machip::instance->get_env()->GetIntField(player_obj, idfid);
}

sdk::vec3 c_player::get_location() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj );
	jfieldID xfid = machip::instance->get_env()->GetFieldID( playerclass, "s", "D" );
	jfieldID yfid = machip::instance->get_env()->GetFieldID( playerclass, "t", "D" );
	jfieldID zfid = machip::instance->get_env()->GetFieldID( playerclass, "u", "D" );

	sdk::vec3 loc {
		machip::instance->get_env()->GetDoubleField(player_obj, xfid ),
		machip::instance->get_env()->GetDoubleField(player_obj, yfid ),
		machip::instance->get_env()->GetDoubleField(player_obj, zfid )
	};

	machip::instance->get_env()->DeleteLocalRef(playerclass);

	return loc;
}

float c_player::get_fall_distance() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID falldfid = machip::instance->get_env()->GetFieldID(playerclass, "O", "F");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return machip::instance->get_env()->GetFloatField(player_obj, falldfid);
}

void c_player::set_fall_distance(float val) {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID falldfid = machip::instance->get_env()->GetFieldID(playerclass, "O", "F");
	machip::instance->get_env()->SetFloatField(player_obj, falldfid, (jfloat)val);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
}

jobject c_player::get_open_container() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID opencontainer_fid = machip::instance->get_env()->GetFieldID(playerclass, "bk", "Lxi;");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return machip::instance->get_env()->GetObjectField(player_obj, opencontainer_fid);
}

jobject c_player::get_inventory_container() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID invcontainer_fid = machip::instance->get_env()->GetFieldID(playerclass, "bj", "Lxi;");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return machip::instance->get_env()->GetObjectField(player_obj, invcontainer_fid);
}

jobject c_player::get_inventory() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jfieldID inv_fid = machip::instance->get_env()->GetFieldID(playerclass, "bi", "Lwm;");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return machip::instance->get_env()->GetObjectField(player_obj, inv_fid);
}

int c_player::get_current_item_index() {
	jobject playerctrl_obj = get_player_controller();
	jclass playerctrl_class = machip::instance->get_env()->GetObjectClass(playerctrl_obj);
	jfieldID currentidx_fid = machip::instance->get_env()->GetFieldID(playerctrl_class, "j", "I");
	auto res = machip::instance->get_env()->GetIntField(playerctrl_obj, currentidx_fid);
	machip::instance->get_env()->DeleteLocalRef(playerctrl_class);
	machip::instance->get_env()->DeleteLocalRef(playerctrl_obj);
	return res;
}

void c_player::set_current_item_index(int idx) {
	jobject playerctrl_obj = get_player_controller();
	jclass playerctrl_class = machip::instance->get_env()->GetObjectClass(playerctrl_obj);
	jfieldID currentidx_fid = machip::instance->get_env()->GetFieldID(playerctrl_class, "j", "I");
	machip::instance->get_env()->SetIntField(playerctrl_obj, currentidx_fid, idx);
	update_player_controller();
	machip::instance->get_env()->DeleteLocalRef(playerctrl_class);
	machip::instance->get_env()->DeleteLocalRef(playerctrl_obj);
}

jobject c_player::get_player_controller() {
	jclass mcclass = machip::instance->get_env()->FindClass(xorstr_("ave"));
	jfieldID controllerfid = machip::instance->get_env()->GetFieldID(mcclass, "c", "Lbda;");
	machip::instance->get_env()->DeleteLocalRef(mcclass);
	return machip::instance->get_env()->GetObjectField(sdk::instance->get_minecraft(), controllerfid);
}

void c_player::attackEntity(jobject entity) {
	jobject pc_obj = get_player_controller();
	jclass pc_class = machip::instance->get_env()->GetObjectClass(pc_obj);
	jmethodID atmid = machip::instance->get_env()->GetMethodID(pc_class, "a", "(Lwn;Lpk;)V");
	machip::instance->get_env()->CallVoidMethod(pc_obj, atmid, player_obj, entity);
	machip::instance->get_env()->DeleteLocalRef(pc_obj);
	machip::instance->get_env()->DeleteLocalRef(pc_class);
}

void c_player::update_player_controller() { // TODO: send packet?
	jobject pc_obj = get_player_controller();
	jclass pc_class = machip::instance->get_env()->GetObjectClass(pc_obj);
	jmethodID update_mid = machip::instance->get_env()->GetMethodID(pc_class, "e", "()V");
	machip::instance->get_env()->CallVoidMethod(pc_obj, update_mid);
	machip::instance->get_env()->DeleteLocalRef(pc_obj);
	machip::instance->get_env()->DeleteLocalRef(pc_class);
}

void c_player::drop_current_item(bool drop_all = true) {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jmethodID drop_mid = machip::instance->get_env()->GetMethodID(playerclass, "a", "(Z)Luz;");
	jobject trash = machip::instance->get_env()->CallObjectMethod(player_obj, drop_mid, drop_all);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	machip::instance->get_env()->DeleteLocalRef(trash);
}

void c_player::drop_item(itemstack item, bool dropAround) {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jmethodID drop_mid = machip::instance->get_env()->GetMethodID(playerclass, "a", "(Lzx;ZZ)Luz;");
	jobject trash = machip::instance->get_env()->CallObjectMethod(player_obj, drop_mid, item.get_object(), dropAround, false);
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	machip::instance->get_env()->DeleteLocalRef(trash);
}

itemstack c_player::get_current_item() {
	jobject inv_obj = get_inventory();
	jclass inv_class = machip::instance->get_env()->GetObjectClass(inv_obj);
	jmethodID getcurritem_mid = machip::instance->get_env()->GetMethodID(inv_class, "h", "()Lzx;");
	itemstack res(machip::instance->get_env()->CallObjectMethod(inv_obj, getcurritem_mid));
	machip::instance->get_env()->DeleteLocalRef(inv_obj);
	machip::instance->get_env()->DeleteLocalRef(inv_class);
	return res;
}

int c_player::get_item_index(string name) {
	int res = -1;

	jobject inv_obj = get_inventory();
	jclass inv_class = machip::instance->get_env()->GetObjectClass(inv_obj);
	jfieldID maininv_fid = machip::instance->get_env()->GetFieldID(inv_class, "a", "[Lzx;");
	jobject maininv_obj = machip::instance->get_env()->GetObjectField(inv_obj, maininv_fid);
	jobjectArray inv_array = reinterpret_cast<jobjectArray>(maininv_obj);

	for (int i = 0; i < 36; ++i)
	{
		jobject istackobj = machip::instance->get_env()->GetObjectArrayElement(inv_array, i);
		itemstack istack(istackobj);
		if (istack.get_name().find(name) != string::npos)
		{
			res = i;
			break;
		}
	}

	machip::instance->get_env()->DeleteLocalRef(inv_obj);
	machip::instance->get_env()->DeleteLocalRef(inv_class);
	machip::instance->get_env()->DeleteLocalRef(maininv_obj);
	machip::instance->get_env()->DeleteLocalRef(inv_array);

	return res;
}

float c_player::get_health() {
	jclass playerclass = machip::instance->get_env()->GetObjectClass(player_obj);
	jmethodID gethealth_mid = machip::instance->get_env()->GetMethodID(playerclass, "bn", "()F");
	machip::instance->get_env()->DeleteLocalRef(playerclass);
	return machip::instance->get_env()->CallFloatMethod(player_obj, gethealth_mid);
}

void c_player::send_use_item(jobject world, jobject itemstack) {
	jobject playerctrl = get_player_controller();
	jclass playerctrl_class = machip::instance->get_env()->GetObjectClass(playerctrl);
	jmethodID use_mid = machip::instance->get_env()->GetMethodID(playerctrl_class, "a", "(Lwn;Ladm;Lzx;)Z");
	machip::instance->get_env()->CallVoidMethod(playerctrl, use_mid, player_obj, world, itemstack);
	machip::instance->get_env()->DeleteLocalRef(playerctrl);
	machip::instance->get_env()->DeleteLocalRef(playerctrl_class);
}

jobject c_player::raytrace(float distance) {
	jclass player_class = machip::instance->get_env()->GetObjectClass(player_obj);
	jmethodID raytrace_mid = machip::instance->get_env()->GetMethodID(player_class, "a", "(DF)Lauh;");
	machip::instance->get_env()->DeleteLocalRef(player_class);
	return machip::instance->get_env()->CallObjectMethod(player_obj, raytrace_mid, 1.0, distance);
}
