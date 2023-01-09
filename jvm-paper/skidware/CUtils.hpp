#ifndef CUTILS_HPP_GUARD
#define CUTILS_HPP_GUARD
#pragma once

#include "common.h"
#include "CCheat.hpp"

struct CCheat;

typedef struct CUtils {
	template<class T, class... Args> constexpr static T CallMethod(_In_ jobject _JavaMirror,
		_In_ std::string _MethodName, _In_ std::string _MethodSignature, _In_ const Args... _Args) {
		JNIEnv* env = CCheat::getInstance()->env;
		if constexpr (std::is_same_v<T, void>) {
			jmethodID mid = env->GetMethodID(env->GetObjectClass(_JavaMirror), _MethodName.c_str(), _MethodSignature.c_str());
			//be sure we HAVE passed any argument
			if constexpr (sizeof...(_Args) >= 1) {
				env->CallVoidMethod(_JavaMirror, mid, _Args...);
			}
			else {
				env->CallVoidMethod(_JavaMirror, mid);
			}
			return T();
		}
		else {
			jmethodID mid = env->GetMethodID(env->GetObjectClass(_JavaMirror), _MethodName.c_str(), _MethodSignature.c_str());
			if constexpr (std::is_same_v<T, double>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallDoubleMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallDoubleMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, float>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallFloatMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallFloatMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, long long>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallLongMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallLongMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, int> || std::is_same_v<T, jint>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallIntMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallIntMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallByteMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallByteMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, short>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallShortMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallShortMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallBooleanMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallBooleanMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, char> || std::is_same_v<T, jchar>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallCharMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallCharMethod(_JavaMirror, mid);
				}
			}
			if constexpr (std::is_same_v<T, jobject>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallObjectMethod(_JavaMirror, mid, _Args...);
				}
				else {
					return env->CallObjectMethod(_JavaMirror, mid);
				}
			}
		}

		return T();
	}

	template<class T, class... Args> constexpr static T CallStaticMethod(_In_ jclass _JavaClass,
		_In_ std::string _MethodName, _In_ std::string _MethodSignature, _In_ const Args... _Args) {
		JNIEnv* env = CCheat::getInstance()->env;
		if constexpr (std::is_same_v<T, void>) {
			jmethodID mid = env->GetStaticMethodID(_JavaClass, _MethodName.c_str(), _MethodSignature.c_str());
			//be sure we HAVE passed any argument
			if constexpr (sizeof...(_Args) >= 1) {
				env->CallStaticVoidMethod(_JavaClass, mid, _Args...);
			}
			else {
				env->CallStaticVoidMethod(_JavaClass, mid);
			}
			return T();
		}
		else {
			jmethodID mid = env->GetStaticMethodID(_JavaClass, _MethodName.c_str(), _MethodSignature.c_str());
			if constexpr (std::is_same_v<T, double>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticDoubleMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticDoubleMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, float>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticFloatMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticFloatMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, long long>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticLongMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticLongMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, int>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticIntMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticIntMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticByteMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticByteMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, short>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticShortMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticShortMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticBooleanMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticBooleanMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, char>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticCharMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticCharMethod(_JavaClass, mid);
				}
			}
			if constexpr (std::is_same_v<T, jobject>) {
				if constexpr (sizeof...(_Args) >= 1) {
					return env->CallStaticObjectMethod(_JavaClass, mid, _Args...);
				}
				else {
					return env->CallStaticObjectMethod(_JavaClass, mid);
				}
			}
		}

		return T();
	}

	template<class T> constexpr static T GetField(_In_ jobject _JavaMirror,
		_In_ std::string _FieldName, _In_ std::string _FieldSignature) {
		JNIEnv* env = CCheat::getInstance()->env;
		jfieldID fid = env->GetFieldID(env->GetObjectClass(_JavaMirror), _FieldName.c_str(), _FieldSignature.c_str());

		if constexpr (std::is_same_v<T, double>) {
			return env->GetDoubleField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, float>) {
			return env->GetFloatField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, long long>) {
			return env->GetLongField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, int>) {
			return env->GetIntField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
			return env->GetByteField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
			return env->GetBooleanField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, char>) {
			return env->GetCharField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, short>) {
			return env->GetShortField(_JavaMirror, fid);
		}
		if constexpr (std::is_same_v<T, jobject>) {
			return env->GetObjectField(_JavaMirror, fid);
		}

		return T();
	}

	template<class T> constexpr static T GetStaticField(_In_ jclass _JavaClass,
		_In_ std::string _FieldName, _In_ std::string _FieldSignature) {
		JNIEnv* env = CCheat::getInstance()->env;
		jfieldID fid = env->GetStaticFieldID(_JavaClass, _FieldName.c_str(), _FieldSignature.c_str());

		if constexpr (std::is_same_v<T, double>) {
			return env->GetStaticDoubleField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, float>) {
			return env->GetStaticFloatField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, long long>) {
			return env->GetStaticLongField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, int>) {
			return env->GetStaticIntField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
			return env->GetStaticByteField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
			return env->GetStaticBooleanField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, char>) {
			return env->GetStaticCharField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, short>) {
			return env->GetStaticShortField(_JavaClass, fid);
		}
		if constexpr (std::is_same_v<T, jobject>) {
			return env->GetStaticObjectField(_JavaClass, fid);
		}

		return T();
	}

	template<class T> constexpr static void SetField(_In_ jobject _JavaMirror,
		_In_ std::string _FieldName, _In_ std::string _FieldSignature, const T val) {
		JNIEnv* env = CCheat::getInstance()->env;
		jfieldID fid = env->GetFieldID(env->GetObjectClass(_JavaMirror), _FieldName.c_str(), _FieldSignature.c_str());

		if constexpr (std::is_same_v<T, double>) {
			return env->SetDoubleField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, float>) {
			return env->SetFloatField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, long long>) {
			return env->SetLongField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, int>) {
			return env->SetIntField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
			return env->SetByteField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
			return env->SetBooleanField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, char>) {
			return env->SetCharField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, short>) {
			return env->SetShortField(_JavaMirror, fid, val);
		}
		if constexpr (std::is_same_v<T, jobject>) {
			return env->SetObjectField(_JavaMirror, fid, val);
		}
	}

	template<class T> constexpr static void SetStaticField(_In_ jclass _JavaClass,
		_In_ std::string _FieldName, _In_ std::string _FieldSignature, const T val) {
		JNIEnv* env = CCheat::getInstance()->env;
		jfieldID fid = env->GetStaticFieldID(_JavaClass, _FieldName.c_str(), _FieldSignature.c_str());

		if constexpr (std::is_same_v<T, double>) {
			return env->SetStaticDoubleField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, float>) {
			return env->SetStaticFloatField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, long long>) {
			return env->SetStaticLongField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, int>) {
			return env->SetStaticIntField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
			return env->SetStaticByteField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
			return env->SetStaticBooleanField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, char>) {
			return env->SetStaticCharField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, short>) {
			return env->SetStaticShortField(_JavaClass, fid, val);
		}
		if constexpr (std::is_same_v<T, jobject>) {
			return env->SetStaticObjectField(_JavaClass, fid, val);
		}
	}
} CUtils;

#endif //CUTILS_HPP_GUARD
