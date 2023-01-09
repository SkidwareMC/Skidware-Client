#ifndef CKEYBINDING_HPP_GUARD
#define CKEYBINDING_HPP_GUARD
#pragma once

#include "common.h"


#include "CUtils.hpp"

struct CUtils;

class __FIX_ME__2 {
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

typedef struct CKeyBinding {
	CKeyBinding(jobject);
	~CKeyBinding();

	__FIX_ME__2::jni_ptr<bool> pressed = __FIX_ME__2::make_jni_ptr<bool>(this->_klass, "", "Z");
	__FIX_ME__2::jni_ptr<int> keyCode = __FIX_ME__2::make_jni_ptr<int>(this->_klass, "", "I");

	bool isKeyDown();
private:
	jobject _klass;
} CKeyBinding;

#endif //CKEYBINDING_HPP_GUARD
