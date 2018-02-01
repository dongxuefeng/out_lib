// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MYAMQ_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MYAMQ_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifndef __MYAMQ_H_
#define __MYAMQ_H_

// #ifdef MYAMQ_EXPORTS
// #define MYAMQ_API __declspec(dllexport)
// #else
// #define MYAMQ_API __declspec(dllimport)
// #endif

#define  MYAMQ_API



//��Ϣ�ص�����
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
