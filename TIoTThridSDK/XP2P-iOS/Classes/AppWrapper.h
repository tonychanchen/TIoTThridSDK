#ifndef __APPWRAPPER_H_
#define __APPWRAPPER_H_
//#ifdef __cplusplus
//extern "C" {
//#endif

#include <stddef.h>
#include <stdint.h>
#include <string>

//type=1:日志； type=2:json;
typedef void (*CallBackFunc)(int type, char *format);
typedef void (*CallBackFuncData)(uint8_t *data, size_t len);

#ifdef BUILD_WITH_ANDROID_JNI
#include <jni.h>

__attribute__ ((visibility ("default")))
int setJavaCallback(JNIEnv *env, jobject obj, const char* name);
#endif

__attribute__ ((visibility ("default")))
int getCommandRequestWithSync(const char *params, char **buf, size_t *len, uint64_t timeout_us);

__attribute__ ((visibility ("default")))
int startServiceWithXp2pInfo(const char* xp2p_info);

__attribute__ ((visibility ("default")))
std::string delegateHttpFlv();

__attribute__ ((visibility ("default")))
void *runSendService();

__attribute__ ((visibility ("default")))
int stopSendService(void *req);

__attribute__ ((visibility ("default")))
int setQcloudApiCred(const char *sec_id, const char *sec_key);

__attribute__ ((visibility ("default")))
int setDeviceInfo(const char *pro_id, const char *dev_name);

__attribute__ ((visibility ("default")))
int setXp2pInfoAttributes(const char *attr);

__attribute__ ((visibility ("default")))
int dataSend(uint8_t *data, size_t len);

__attribute__ ((visibility ("default")))
void stopService();

__attribute__ ((visibility ("default")))
void setNativeCallback(CallBackFunc pcallbackFunc);

__attribute__ ((visibility ("default")))
void setNativeCallback(CallBackFuncData pcallbackFuncData);
//#ifdef __cplusplus
//}
//#endif
#endif
