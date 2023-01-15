#ifndef CUNIQUEREFERENCE_HPP_GUARD
#define CUNIQUEREFERENCE_HPP_GUARD
#pragma once

#include "jni.h"
#include "CUtils.hpp"

struct CUtils;

	template<typename T> class static_ptr {
	public:
		explicit static_ptr(jclass klass, std::string fieldName, std::string fieldSignature) noexcept {
			this->klass = klass;
			this->fieldName = fieldName;
			this->fieldSignature = fieldSignature;
		}
		void operator=(T value) {
			CUtils::template SetStaticField<T>(klass, fieldName, fieldSignature, value);
		}
		operator T() {
			return CUtils::template GetStaticField<T>(klass, fieldName, fieldSignature);
		}
	private:
		jclass klass;
		std::string fieldName, fieldSignature;
	};

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

	template<typename T> static_ptr<T> make_static_ptr(_In_ jclass _JavaClass, _In_ std::string _FieldName, _In_ std::string _FieldSignature) {
		return static_ptr<T>(_JavaClass, _FieldName, _FieldSignature);
	}

	template<typename T> jni_ptr<T> make_jni_ptr(_In_ jobject _JavaMirror, _In_ std::string _FieldName, _In_ std::string _FieldSignature) {
		return jni_ptr<T>(_JavaMirror, _FieldName, _FieldSignature);
	}
	template<typename T> struct ref_ptr {
		explicit ref_ptr(const T& t) noexcept : ptr{ std::make_unique<T>(t) } {}

		T* operator->() { return ptr.get(); }
		const T* operator->() const { return ptr.get(); }

		T& operator*() { return *ptr; }
		const T& operator*() const { return *ptr; }

		operator T() { return std::move(T{ *ptr }); }
		operator T() const { return std::move(T{ *ptr }); }
	private:
		std::unique_ptr<T> ptr;
	};

#endif //CUNIQUEREFERENCE_HPP_GUARD
