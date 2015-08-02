#include "timer_library.h"
#include <stdio.h>
#include <time.h>

/*ACTUAL IMPLEMENTATION OF USEABLE TIMER LIBRARY FUNCTIONS BEGIN*/

/*****************************************************************************
   FUNCTION NAME    :
   FUNCTION PURPOSE :
   FUNCTION ARGS    :
   FUNCION RET VAL  :
******************************************************************************/
JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_start(JNIEnv *env, jobject this) {
	double start = 0.0;
	jfieldID fid;

	if (getTimeStamp(&start) != TIMER_LIB_OK) {
		(*env)->ThrowNew(env, (*env)->FindClass(env, \
					"java/lang/Exception"), \
				"Unable to start timer, high res system function " \
				"returned FALSE");
		return;
	}

	/*the value returned by getTimeStamp is in nano sec well convert it*/
	start /= TIMER_LIB_SEC_TO_NANOSEC_MULTIPLIER; /*we are dividing!!*/ 
	fid = (*env)->GetFieldID(env, (*env)->GetObjectClass(env, this), "timeDiff", "D");
	(*env)->SetDoubleField(env, this, fid, start);
}

/*****************************************************************************
   FUNCTION NAME    :
   FUNCTION PURPOSE :
   FUNCTION ARGS    :
   FUNCION RET VAL  :
******************************************************************************/
JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_stop(JNIEnv *env, jobject this) {
	double stop = 0.0;
	double start = 0.0;
	jfieldID fid;

	if (getTimeStamp(&stop) != TIMER_LIB_OK) {
		(*env)->ThrowNew(env, (*env)->FindClass(env, \
					"java/lang/Exception"), \
				"Unable to stop timer, high res system function " \
				"returned FALSE");
		return;
	}

	/*the value returned by getTimeStamp is in nano sec well convert it*/
	stop /= TIMER_LIB_SEC_TO_NANOSEC_MULTIPLIER; /*we are dividing!!*/ 
	fid = (*env)->GetFieldID(env, (*env)->GetObjectClass(env, this), "timeDiff", "D");
	start = (*env)->GetDoubleField(env, this, fid);
	(*env)->SetDoubleField(env, this, fid, (stop - start));
}

/*****************************************************************************
   FUNCTION NAME    :
   FUNCTION PURPOSE :
   FUNCTION ARGS    :
   FUNCION RET VAL  :
******************************************************************************/
JNIEXPORT void JNICALL Java_highrestimer_HighResTimer_diff(JNIEnv *env, jobject this) {
	double stop = 0.0;
	double start = 0.0;
	jfieldID fid;
	jfieldID dif;

	if (getTimeStamp(&stop) != TIMER_LIB_OK) {
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"),
				"Unable to stop timer, high res system function "
				"returned FALSE");
		return;
	}

	/*the value returned by getTimeStamp is in nano sec well convert it*/
	stop /= TIMER_LIB_SEC_TO_NANOSEC_MULTIPLIER; /*we are dividing!!*/ 
	fid = (*env)->GetFieldID(env, (*env)->GetObjectClass(env, this), "timeDiff", "D");
	dif = (*env)->GetFieldID(env, (*env)->GetObjectClass(env, this), "runtimeDiff", "D");
	start = (*env)->GetDoubleField(env, this, fid);

	double res = stop - start;
	(*env)->SetDoubleField(env, this, dif, (stop - start));
}

/*****************************************************************************
   FUNCTION NAME    :
   FUNCTION PURPOSE :
   FUNCTION ARGS    :
   FUNCION RET VAL  :
******************************************************************************/
int getTimeStamp(double *timeStamp) {
	struct timespec ts;
    double nsec = 0.0;
    timespec_get(&ts, 1);
    nsec = ts.tv_nsec;
    *timeStamp = ts.tv_sec * 1000000 + nsec / 1000;

	return TIMER_LIB_OK;
}
