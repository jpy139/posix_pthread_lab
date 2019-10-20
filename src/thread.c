/*
 * @Date: 2019-10-05 20:09:51
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-21 00:09:34
 */
#include "main.h"

// void OS_pthread_cleanup_push(void(*rtn)(void*), void* arg)
// {
//     pthread_cleanup_push(rtn, arg);
// }

int OS_pthread_cancel(pthread_t th_hd)
{
    return pthread_cancel(th_hd);
}

void OS_pthread_exit(void *ret)
{
    return pthread_exit(ret);
}

pthread_t OS_pthread_self(void)
{
    return pthread_self();
}

int OS_pthread_join(pthread_t th_handle, void **retValue)
{
    pthread_join(th_handle, retValue);
    return 0;
}

int OS_TaskCreate(pthread_t *th_phandle, pthread_attr_t *th_attr, void *th_fun(void*), void *arg)
{
    int err = 0;

    if(err = pthread_create(th_phandle, th_attr, th_fun, arg) != 0)
    {
        perror("pthread create error\n");
    }
    return err;
}