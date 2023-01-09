#include "CWorld.hpp"
#include "CCheat.hpp"

CWorld::CWorld(jobject klass) : _klass(klass) {
	this->_klass = klass;
}

CWorld::~CWorld() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}

std::vector<CPlayer*> CWorld::getPlayers() {
	std::vector<CPlayer*> result;

	JNIEnv* env = CCheat::getInstance()->env;

	//@todo: Recode. Code is a mess. - xwhitey
	jfieldID playerEntities;
	if (CCheat::getInstance()->getMinecraftType() == CMinecraftType::FORGE) {
		playerEntities = env->GetFieldID(env->GetObjectClass(this->_klass), "field_73010_i", "Ljava/lang/List;");
	} else {
		playerEntities = env->GetFieldID(env->GetObjectClass(this->_klass), "i", "Ljava/lang/List;");
	}

	if (playerEntities) {
		jclass java__lang__List = env->FindClass("java/lang/List");
		jmethodID toArray = env->GetMethodID(java__lang__List, "toArray", "()[Ljava/lang/Object;"); //returns Object[]

		jobject playerEntities_ = env->GetObjectField(this->_klass, playerEntities);

		if (playerEntities_) {
			jobjectArray array = reinterpret_cast<jobjectArray>(env->CallObjectMethod(playerEntities_, toArray));

			if (array) {
				auto length = env->GetArrayLength(array);

				for (int idx = 0; idx < length; idx++) {
					jobject entity = env->GetObjectArrayElement(array, idx);

					if (entity) {
						result.push_back(new CPlayer(entity));
					}
				}
			}
		}
	}

	return result;
}