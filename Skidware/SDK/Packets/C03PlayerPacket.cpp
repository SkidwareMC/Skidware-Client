#include "C03PlayerPacket.hpp"
#include "../../Wrapper/Logger.hpp"

C03PlayerPacket::C03PlayerPacket(bool onGround)
{
	jclass blockposclass = JNIHelper::IsForge() ? JNIHelper::ForgeFindClass("net/minecraft/util/BlockPos") : JNIHelper::env->FindClass("ip"); //packet class
	jmethodID bpmid = JNIHelper::env->GetMethodID(blockposclass, "<init>", "(DDD)V"); // construcor
}
