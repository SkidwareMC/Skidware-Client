#include "JavaUtil.hpp"

jclass JavaUtil::GetArrayListClass()
{
	if (ArrayListClass == NULL) ArrayListClass = JNIHelper::env->FindClass("java/util/ArrayList");
	return ArrayListClass;
}

jclass JavaUtil::GetListClass()
{
	if (ListClass == NULL) ListClass = JNIHelper::env->FindClass("java/util/List");
	return ListClass;
}

jclass JavaUtil::GetThreadClass()
{
	if (ThreadClass == NULL) ThreadClass = JNIHelper::env->FindClass("java/util/List");
	return ThreadClass;
}

jclass JavaUtil::GetThreadGroupClass()
{
	if (ThreadGroupClass == NULL) ThreadGroupClass = JNIHelper::env->FindClass("java/lang/ThreadGroup");
	return ThreadGroupClass;
}

jint JavaUtil::GetArraySize(jobject obj)
{
	if (GetArrayListClass() == NULL) return NULL;

	if (ArrayListSizeFieldID == NULL)
	{
		ArrayListSizeFieldID = JNIHelper::env->GetFieldID(GetArrayListClass(), "size", "I");
		if (ArrayListSizeFieldID == NULL) return NULL;
	}

	return JNIHelper::env->GetIntField(obj, ArrayListSizeFieldID);
}

jobjectArray JavaUtil::GetArray(jobject obj)
{
	if (GetArrayListClass() == NULL) return NULL;

	if (ArrayListElementDataFieldID == NULL)
	{
		ArrayListElementDataFieldID = JNIHelper::env->GetFieldID(GetArrayListClass(), "elementData", "[Ljava/lang/Object;");
		if (ArrayListElementDataFieldID == NULL) return NULL;
	}

	return (jobjectArray)JNIHelper::env->GetObjectField(obj, ArrayListElementDataFieldID);
}

jobject JavaUtil::GetCurrentThread()
{
	if (GetThreadClass() == NULL) return NULL;

	if (CurrentThread == NULL)
	{
		if (CurrentThreadMethodID == NULL)
		{
			CurrentThreadMethodID = JNIHelper::env->GetMethodID(GetThreadClass(), "currentThread", "()Ljava/lang/Thread;");
			if (CurrentThreadMethodID == NULL) return NULL;
		}

		CurrentThread = JNIHelper::env->CallObjectMethod(GetThreadClass(), CurrentThreadMethodID);
	}

	return CurrentThread;
}

jobject JavaUtil::GetThreadGroup()
{
	if (GetThreadGroupClass() == NULL) return NULL;

	if (CurrentThreadGroup == NULL)
	{
		if (CurrentThreadGroupMethodID == NULL)
		{
			CurrentThreadGroupMethodID = JNIHelper::env->GetMethodID(GetThreadGroupClass(), "getThreadGroup", "()Ljava/lang/ThreadGroup;");
			if (CurrentThreadGroupMethodID == NULL) return NULL;
		}

		CurrentThreadGroup = JNIHelper::env->CallObjectMethod(GetThreadGroupClass(), CurrentThreadGroupMethodID);
	}

	return CurrentThreadGroup;
}