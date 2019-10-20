/*
 * @Date: 2019-10-05 20:10:04
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-21 00:09:42
 */
#ifndef _THREAD_H
#define _THREAD_H
// void OS_pthread_cleanup_push(void(*rtn)(void*), void* arg);
int OS_pthread_cancel(pthread_t th_hd);
void OS_pthread_exit(void *ret);

pthread_t OS_pthread_self(void);
int OS_pthread_join(pthread_t th_handle, void **retValue);
int OS_TaskCreate(pthread_t *th_handle, pthread_attr_t *th_attr, void *th_fun(void*), void *arg);
#endif // !_THREAD_H