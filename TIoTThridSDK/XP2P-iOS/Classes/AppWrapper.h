#ifndef __APPWRAPPER_H_
#define __APPWRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define MAX_SIZE_OF_PARAMS 3000

static const char * VIDEOSDKVERSION = "544a26e4";

/*
 * type=0:close通知； type=1:日志； type=2:json;
 * native返回给SDK结果：char*
 */
typedef char* (*msg_handle_t)(int type, const char* msg);

typedef void (*av_recv_handle_t)(uint8_t* recv_buf, size_t recv_len);

void setUserCallbackToXp2p(av_recv_handle_t recv_handle, msg_handle_t msg_handle);


__attribute__ ((visibility ("default")))
int getCommandRequestWithSync(const char *params, char **buf, size_t *len, uint64_t timeout_us);

__attribute__ ((visibility ("default")))
int getCommandRequestWithAsync(const char *params);

__attribute__ ((visibility ("default")))
void *startAvRecvService(const char *params);

__attribute__ ((visibility ("default")))
int stopAvRecvService(void *req);

__attribute__ ((visibility ("default")))
int startServiceWithXp2pInfo(const char* xp2p_info);

__attribute__ ((visibility ("default")))
const char *delegateHttpFlv();

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

#ifdef __cplusplus
}
#endif

#endif
