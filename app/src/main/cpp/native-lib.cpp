#include <jni.h>
#include <string>
#include "Parcel.h"
#include <android/log.h>

#define TAG "zuojie"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);

extern "C"
JNIEXPORT jlong JNICALL
Java_com_zxj_parcel_MyParcel_nativeCreate(JNIEnv *env, jobject thiz) {
    Parcel *parcel = new Parcel();
    return reinterpret_cast<jlong>(parcel);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zxj_parcel_MyParcel_nativeWriteInt(JNIEnv *env, jobject thiz, jlong m_native_ptr,
                                            jint value) {
    Parcel *parcel = reinterpret_cast<Parcel *>(m_native_ptr);
    parcel->writeInt(value);

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_zxj_parcel_MyParcel_nativeReadInt(JNIEnv *env, jobject thiz, jlong m_native_ptr) {
    Parcel *parcel = reinterpret_cast<Parcel *>(m_native_ptr);
    int result = parcel->readInt();
    return result;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zxj_parcel_MyParcel_nativeSetDataPosition(JNIEnv *env, jobject thiz, jlong m_native_ptr,
                                                   jint position) {
    Parcel *parcel = reinterpret_cast<Parcel *>(m_native_ptr);
    LOGE("position = %d\n",position)
    parcel->setDataPosition(position);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zxj_parcel_MyParcel_nativeWriteString(JNIEnv *env, jobject thiz, jlong m_native_ptr,
                                               jstring val) {
    Parcel *parcel = reinterpret_cast<Parcel *>(m_native_ptr);
//    const jchar * str = env->GetStringCritical(val, 0);
    const char *str = env->GetStringUTFChars(val, 0);
    int err = -1;
    if (str) {
        jsize length = env->GetStringLength(val);
        LOGE("length= %d,str=%s",length,str)
        err = parcel->writeString16(reinterpret_cast<const char16_t *>(str), length);
        env->ReleaseStringUTFChars(val,str);
    }

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_zxj_parcel_MyParcel_nativeReadString(JNIEnv *env, jobject thiz, jlong m_native_ptr) {
    Parcel *parcel = reinterpret_cast<Parcel *>(m_native_ptr);
    const char16_t *data = parcel->readString16Inplace();
    jstring pJstring = env->NewStringUTF(reinterpret_cast<const char *>(data));
    return pJstring;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zxj_parcel_MyParcel_nativeWriteChar(JNIEnv *env, jobject thiz, jlong m_native_ptr,
                                             jchar value) {
    Parcel *parcel = reinterpret_cast<Parcel *>(m_native_ptr);
    LOGE("value=%d",value);
    parcel->writeChar(value);
}

extern "C"
JNIEXPORT jchar JNICALL
Java_com_zxj_parcel_MyParcel_nativeReadChar(JNIEnv *env, jobject thiz, jlong m_native_ptr) {

    Parcel *parcel = reinterpret_cast<Parcel *>(m_native_ptr);
    return parcel->readChar();
}