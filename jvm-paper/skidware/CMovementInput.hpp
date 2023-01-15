#ifndef CMOVEMENTINPUT_HPP_GUARD
#define CMOVEMENTINPUT_HPP_GUARD
#pragma once

#include "common.h"

#include "CUtils.hpp"

struct CUtils;

class __FIX_ME__ {
public:
	template<typename T> class jni_ptr {
	public:
		explicit jni_ptr(jobject obj, std::string fieldName, std::string fieldSignature) noexcept {
			this->obj = obj;
			this->fieldName = fieldName;
			this->fieldSignature = fieldSignature;
		}
		void operator=(T value) {
			CUtils::template SetField<T>(obj, fieldName, fieldSignature, value);
		}
		operator T() {
			return CUtils::template GetField<T>(obj, fieldName, fieldSignature);
		}
	private:
		jobject obj;
		std::string fieldName, fieldSignature;
	};

	template<typename T> static jni_ptr<T> make_jni_ptr(_In_ jobject _JavaMirror, _In_ std::string _FieldName, _In_ std::string _FieldSignature) {
		return jni_ptr<T>(_JavaMirror, _FieldName, _FieldSignature);
	}
};

typedef struct CMovementInput {
	CMovementInput(jobject);
	~CMovementInput();

	__FIX_ME__::jni_ptr<float> moveForward = __FIX_ME__::make_jni_ptr<float>(this->_klass, "", "F");
	__FIX_ME__::jni_ptr<float> moveStrafe = __FIX_ME__::make_jni_ptr<float>(this->_klass, "", "F");
private:
	jobject _klass;
} CMovementInput;

#endif //CMOVEMENTINPUT_HPP_GUARD
