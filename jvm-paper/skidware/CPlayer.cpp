#include "CPlayer.hpp"
#include "CCheat.hpp"

CPlayer::CPlayer(jobject klass) : _klass(klass), onGround(klass, 
	CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP").getField("onGround").name(), "Z"), moveForward(klass,
		CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP").getField("moveForward").name(), "F"), moveStrafing(klass,
			CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP").getField("moveStrafing").name(), "F"), motionX(klass,
			CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP").getField("motionX").name(), "D"), motionY(klass, 
				CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP").getField("motionY").name(), "D"), motionZ(klass,
					CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP").getField("motionZ").name(), "D"), rotationYaw(klass,
						CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP").getField("rotationYaw").name(), "F"){
	this->_klass = klass;
	CIntelligentMappedClass intelligent = CIntelligentMappings::getClass("net.minecraft.client.entity.EntityPlayerSP");
	this->movementInput = new CMovementInput(CUtils::GetField<jobject>(this->_klass,
		intelligent.getField("movementInput").name(), intelligent.getField("movementInput").signature()));
	//would be reinited after each world change
	this->theWorld = new CWorld(CUtils::GetField<jobject>(this->_klass,
		intelligent.getField("world").name(), intelligent.getField("world").signature()));
	//useless for now
	//printf("[DEBUG] [CPlayer] this->_klass: 0x%p\n", this->_klass);
}

double toRadians(float degrees) {
	return degrees * (M_PI / 180);
}

CPlayer::~CPlayer() {
	CCheat::getInstance()->env->DeleteLocalRef(this->_klass);
}

bool CPlayer::isStrafing() {
	return this->movementInput->moveStrafe != 0.0;
}

bool CPlayer::isMovingForwardOrBackwards() {
	return this->movementInput->moveForward != 0.0;
}

float CPlayer::getSpeed() {
	return sqrt(this->motionX * this->motionX + this->motionZ * this->motionZ);
}

double CPlayer::getDirection() {
	float rotationYaw = this->rotationYaw;

	if (this->moveForward < 0.0f) {
		rotationYaw += 180.0f;
	}
	float forward = 1.0f;
	if (this->moveForward < 0.0f) {
		forward = -0.5f;
	} else if (this->moveForward > 0.0f) {
		forward = 0.5f;
	}
	if (this->moveStrafing > 0.0f) {
		rotationYaw -= 90.0f * forward;
	}
	if (this->moveStrafing < 0.0f) {
		rotationYaw += 90.0f * forward;
	}
	return toRadians(rotationYaw);
}

void CPlayer::strafe(float speed) {
	if (!this->isStrafing() && !this->isMovingForwardOrBackwards()) {
		return;
	}
	if (this->isStrafing() || this->isMovingForwardOrBackwards()) {
		double yaw = getDirection();
		this->motionX = -sin(yaw) * speed;
		this->motionZ = cos(yaw) * speed;
	}
}