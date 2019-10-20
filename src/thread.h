/*
 * @Date: 2019-10-05 20:10:04
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-20 17:46:22
 */
#ifndef _THREAD_H
#define _THREAD_H
int OS_pthread_join(pthread_t th_handle, void **retValue);
pthread_t OS_pthread_self(void);
int OS_TaskCreate(pthread_t *th_handle, pthread_attr_t *th_attr, void *th_fun(void*), void *arg);
#endif // !_THREAD_H