/*
 * @Date: 2019-10-19 11:23:52
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-20 00:31:10
 */
#include <main.h>

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
    printf("==============APP entry!===============\n");
    unsigned int th_t1;


    OS_TaskCreate(&th_t1, NULL, th_fn, (void*)50);
    printf("==============APP complete==============\n");
    return 0;
}   