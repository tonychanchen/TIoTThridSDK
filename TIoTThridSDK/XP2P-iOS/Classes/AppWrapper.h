#ifndef __APPWRAPPER_H_
#define __APPWRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define MAX_SIZE_OF_PARAMS 3000

static const char * VIDEOSDKVERSION = "2b7afe4b";

/*
 * type=0:close通知； type=1:日志； type=2:json;
 * native返回给SDK结果：char*
 */
typedef char* (*msg_handle_t)(const char *id, int type, const char* msg);

typedef void (*av_recv_handle_t)(const char *id, uint8_t* recv_buf, size_t recv_len);

void setUserCallbackToXp2p(const char *id, av_recv_handle_t recv_handle, msg_handle_t msg_handle);


__attribute__ ((visibility ("default")))
int getCommandRequestWithSync(const char *id, const char *params, char **buf, size_t *len, uint64_t timeout_us);

__attribute__ ((visibility ("default")))
int getCommandRequestWithAsync(const char *id, const char *params);

__attribute__ ((visibility ("default")))
void *startAvRecvService(const char *id, const char *params);

__attribute__ ((visibility ("default")))
int stopAvRecvService(const char *id, void *req);

__attribute__ ((visibility ("default")))
int startServiceWithXp2pInfo(const char* id, const char *product_id, const char *device_name,
        const char *xp2p_info_attr,  const char* xp2p_info);

__attribute__ ((visibility ("default")))
const char *delegateHttpFlv(const char *id);

__attribute__ ((visibility ("default")))
void *runSendService(const char *id);

__attribute__ ((visibility ("default")))
int stopSendService(const char *id, void *req);

__attribute__ ((visibility ("default")))
int setQcloudApiCred(const char *sec_id, const char *sec_key);

//__attribute__ ((visibility ("default")))
//int setDeviceInfo(const char *id, const char *pro_id, const char *dev_name);
//
//__attribute__ ((visibility ("default")))
//int setXp2pInfoAttributes(const char *attr);

__attribute__ ((visibility ("default")))
int dataSend(const char *id, uint8_t *data, size_t len);

__attribute__ ((visibility ("default")))
void stopService(const char *id);

#ifdef __cplusplus
}
#endif

#endif
