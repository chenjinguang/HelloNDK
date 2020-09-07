#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_hkrt_ndk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_hkrt_ndk_MainActivity_init(JNIEnv *env, jobject thiz,jstring config_) {
    const char *config = env->GetStringUTFChars(config_,0);
    NativeInit(std::string(config));
    env->ReleaseStringUTFChars(config_,config);
}