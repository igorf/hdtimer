// timer.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"

#include <windows.h>
#include "timer.h"

// scale factor for converting a performancce counter reading into milliseconds:
static jdouble s_scaleFactor;

double getScaleFactor() {
	LARGE_INTEGER counterFrequency;
	QueryPerformanceFrequency(&counterFrequency);
	return counterFrequency.QuadPart;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM * vm, void * reserved) {
	s_scaleFactor = getScaleFactor();
	return JNI_VERSION_1_2;
}

double getTimestamp() {
	LARGE_INTEGER counterReading;
	QueryPerformanceCounter(&counterReading);
	return counterReading.QuadPart / s_scaleFactor;
}

JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_start(JNIEnv *env, jobject _this) {
	double start = getTimestamp();
	jfieldID fid = env->GetFieldID(env->GetObjectClass(_this), "timeDiff", "D");

	env->SetDoubleField(_this, fid, start);
}

JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_stop(JNIEnv *env, jobject _this) {
	double stop = getTimestamp();
	double start = 0.0;
	jfieldID fid = env->GetFieldID(env->GetObjectClass(_this), "timeDiff", "D");
	start = env->GetDoubleField(_this, fid);
	env->SetDoubleField(_this, fid, (stop - start));
}

JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_diff(JNIEnv *env, jobject _this) {
	double stop = getTimestamp();
	double start = 0.0;
	jfieldID startFid = env->GetFieldID(env->GetObjectClass(_this), "timeDiff", "D");
	start = env->GetDoubleField(_this, startFid);
		
	jfieldID diffFid = env->GetFieldID(env->GetObjectClass(_this), "runtimeDiff", "D");
	env->SetDoubleField(_this, diffFid, (stop - start));
}