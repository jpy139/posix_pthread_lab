/*
 * @Date: 2019-10-19 11:23:52
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-19 20:38:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
void *th_fn(void *arg) 
{ 
    printf("thread 1 entry!\n");

    sleep(3);
    return (void*)1;
}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
int main() {
    printf("hello world\n");
    pthread_t th_t1;


    pthread_create(&th_t1, NULL, th_fn, (void*)50);
    return 0;
}   