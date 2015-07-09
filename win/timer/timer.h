#include <jni.h>

double getScaleFactor();

#ifdef __cplusplus
extern "C" {
#endif
	/*
	* Class:     internal
	* Method:    getTimestamp
	* Signature: double
	*/
	double getTimestamp();

	/*
	* Class:     highrestimer.HighResTimer
	* Method:    start
	* Signature: ()V
	*/
	JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_start(JNIEnv *, jobject);

	/*
	* Class:     highrestimer.HighResTimer
	* Method:    stop
	* Signature: ()V
	*/
	JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_stop(JNIEnv *, jobject);

	/*
	* Class:     highrestimer.HighResTimer
	* Method:    diff
	* Signature: ()V
	*/
	JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_diff(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif