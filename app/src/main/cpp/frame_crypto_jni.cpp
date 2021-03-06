#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#include <vector>
#include <algorithm>

#include "custom_audio_frame_decryptor.h"
#include "custom_audio_frame_encryptor.h"
#include "custom_video_frame_decryptor.h"
#include "custom_video_frame_encryptor.h"

#include "frame_crypto_jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv *env = NULL;

    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    assert(env != NULL);

    /* success -- return valid version number */
    result = JNI_VERSION_1_6;

    return result;
}

/**
   自定义视频加密方法设置，通过RTCLib java层 enableVideoEncryption开关控制
   由RTCLib java层完成 C++层加密方法的绑定
   C++层 CustomVideoFrameEncryptor 类名可以修改
   **/
JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomVideoFrameEncryptor_nativeCustomVideoFrameEncryptor(JNIEnv *env,
                                                                                    jobject thiz) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);

    CustomVideoFrameEncryptor * customVideoFrameEncryptor = new CustomVideoFrameEncryptor;
    //开发者不能修改如下两行代码，RTCLib java层方法和 native层映射
    jclass clazz = env->FindClass("cn/rongcloud/rtc/crypto/CustomVideoFrameEncryptor");
    jfieldID fieldID  = env->GetFieldID(clazz, "nativeVideoFrameEncryptor","J");
    env->SetLongField(thiz, fieldID, reinterpret_cast<long>(customVideoFrameEncryptor));
    LOGI("custom_crypto %s, %d %lld ", __func__, __LINE__, customVideoFrameEncryptor);
}

/**
   自定义音频加密方法设置，通过RTCLib java层 enableAudioEncryption开关控制
   由RTCLib java层完成 C++层加密方法的绑定
   C++层 CustomAudioFrameEncryptor 类名可以修改
   **/
JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomAudioFrameEncryptor_nativeCustomAudioFrameEncryptor(JNIEnv *env,
                                                                                 jobject thiz) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);
    CustomAudioFrameEncryptor * customAudioFrameEncryptor = new CustomAudioFrameEncryptor;
    //开发者不能修改如下两行代码，RTCLib java层方法和 native层映射
    jclass clazz = env->FindClass("cn/rongcloud/rtc/crypto/CustomAudioFrameEncryptor");
    jfieldID fieldID  = env->GetFieldID(clazz, "nativeAudioFrameEncryptor","J");
    env->SetLongField(thiz, fieldID, reinterpret_cast<long>(customAudioFrameEncryptor));
    LOGI("custom_crypto %s, %d %lld", __func__, __LINE__, customAudioFrameEncryptor);
}

/**
   自定义视频解密方法设置，通过RTCLib java层 enableVideoEncryption开关控制
   由RTCLib java层完成 C++层加密方法的绑定
   C++层 CustomVideoFrameDecryptor 类名可以修改
   **/
JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomVideoFrameDecryptor_nativeCustomVideoFrameDecryptor(JNIEnv *env,
                                                                                       jobject thiz) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);

    CustomVideoFrameDecryptor * customVideoFrameDecryptor = new CustomVideoFrameDecryptor;
    //开发者不能修改如下两行代码，RTCLib java层方法和 native层映射
    jclass clazz = env->FindClass("cn/rongcloud/rtc/crypto/CustomVideoFrameDecryptor");
    jfieldID fieldID  = env->GetFieldID(clazz, "nativeVideoFrameDecryptor","J");
    env->SetLongField(thiz, fieldID, reinterpret_cast<long>(customVideoFrameDecryptor));
    LOGI("custom_crypto %s, %d %lld ", __func__, __LINE__, customVideoFrameDecryptor);
}

/**
   自定义音频解密方法设置，通过RTCLib java层 enableAudioEncryption开关控制
   由RTCLib java层完成 C++层加密方法的绑定
   C++层 CustomAudioFrameDecryptor 类名可以修改
   **/
JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomAudioFrameDecryptor_nativeCustomAudioFrameDecryptor(JNIEnv *env,
                                                                                       jobject thiz) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);
    CustomAudioFrameDecryptor * customAudioFrameDecryptor = new CustomAudioFrameDecryptor;
    //开发者不能修改如下两行代码，RTCLib java层方法和 native层映射
    jclass clazz = env->FindClass("cn/rongcloud/rtc/crypto/CustomAudioFrameDecryptor");
    jfieldID fieldID  = env->GetFieldID(clazz, "nativeAudioFrameDecryptor","J");
    env->SetLongField(thiz, fieldID, reinterpret_cast<long>(customAudioFrameDecryptor));
    LOGI("custom_crypto %s, %d %lld", __func__, __LINE__, customAudioFrameDecryptor);
}

//////////////////////////////////////////////////
JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomVideoFrameEncryptor_release(JNIEnv *env, jobject thiz,
                                                               jlong native_pointer) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);
    CustomVideoFrameEncryptor* customVideoFrameEncryptor = reinterpret_cast<CustomVideoFrameEncryptor*>(
            native_pointer);
    delete customVideoFrameEncryptor;
}

JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomAudioFrameEncryptor_release(JNIEnv *env, jobject thiz,
                                                            jlong native_pointer) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);
    CustomAudioFrameEncryptor* customAudioFrameEncryptor = reinterpret_cast<CustomAudioFrameEncryptor*>(
            native_pointer);
    delete customAudioFrameEncryptor;
}

JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomVideoFrameDecryptor_release(JNIEnv *env, jobject thiz,
                                                               jlong native_pointer) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);
    CustomVideoFrameDecryptor* customVideoFrameDecryptor = reinterpret_cast<CustomVideoFrameDecryptor*>(
            native_pointer);
    delete customVideoFrameDecryptor;
}

JNIEXPORT void JNICALL
Java_cn_rongcloud_rtc_crypto_CustomAudioFrameDecryptor_release(JNIEnv *env, jobject thiz,
                                                               jlong native_pointer) {
    LOGI("custom_crypto %s, %d ", __func__, __LINE__);
    CustomAudioFrameDecryptor* customAudioFrameDecryptor = reinterpret_cast<CustomAudioFrameDecryptor*>(
            native_pointer);
    delete customAudioFrameDecryptor;
}

#ifdef __cplusplus
}
#endif
