// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 MYAMQ_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// MYAMQ_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifndef __MYAMQ_H_
#define __MYAMQ_H_

// #ifdef MYAMQ_EXPORTS
// #define MYAMQ_API __declspec(dllexport)
// #else
// #define MYAMQ_API __declspec(dllimport)
// #endif

#define  MYAMQ_API



//消息回调函数
#ifdef __cplusplus
extern "C"
{
#endif

typedef void   (WINAPI *MSG_CALLBACK)(const char * msg,void *userdata);
typedef void * myAMQ_HANDLE;

MYAMQ_API myAMQ_HANDLE open_producer(const char *amq_server_ip, const char * queue_name); 
MYAMQ_API void close_producer(myAMQ_HANDLE *);
MYAMQ_API bool init_producer(myAMQ_HANDLE);
MYAMQ_API bool send_msg(myAMQ_HANDLE,const char *msg);

MYAMQ_API myAMQ_HANDLE open_consumer(const char *amq_server_ip, const char * queue_name,MSG_CALLBACK,void * userdata);
MYAMQ_API void start_consumer(myAMQ_HANDLE);
MYAMQ_API void stop_consumer(myAMQ_HANDLE);
MYAMQ_API void close_consumer(myAMQ_HANDLE*);

#ifdef __cplusplus
};
#endif
#endif //__MYAMQ_H_
