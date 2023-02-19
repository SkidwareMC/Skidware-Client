#pragma once
#include "../JNIHelper.hpp"

class JavaUtil
{
private:
	inline static jclass ArrayListClass = NULL;
	inline static jclass ListClass = NULL;
	inline static jclass ThreadClass = NULL;
	inline static jclass ThreadGroupClass = NULL;

	inline static jfieldID ArrayListElementDataFieldID = NULL;
	inline static jfieldID ArrayListSizeFieldID = NULL;

	inline static jmethodID CurrentThreadMethodID = NULL;
	inline static jobject CurrentThread = NULL;

	inline static jmethodID CurrentThreadGroupMethodID = NULL;
	inline static jobject CurrentThreadGroup = NULL;

	static jclass GetArrayListClass();
	static jclass GetListClass();
	static jclass GetThreadClass();
	static jclass GetThreadGroupClass();

public:
	static jint GetArraySize(jobject);
	static jobjectArray GetArray(jobject);
	static jobject GetCurrentThread();
	static jobject GetThreadGroup();
};