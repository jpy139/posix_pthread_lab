/*
 * @Date: 2019-10-05 20:09:51
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-20 17:43:40
 */
#include "main.h"

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