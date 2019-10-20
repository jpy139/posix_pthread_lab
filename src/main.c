/*
 * @Date: 2019-10-20 12:22:57
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-20 17:49:17
 */
#include "main.h"

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
void *th_fn(void *arg) 
{ 
    int distance = (int)arg;
    int i = 0;
    // printf("thread 1 entry! arg(%d)\n", distance);

    for (i = 1; i <= distance; i++)
    {
        /* code */
        printf("%lx run %d\n", OS_pthread_self(), i);
        int time = (int)(drand48() * 100000);
        usleep(time);
    }
    
    return (void*)1;
}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
int main() {
    pthread_t th_t1, th_t2;
    unsigned int err = 0;
    printf("==============APP entry!===============\n");


    OS_TaskCreate(&th_t1, NULL, th_fn, (void*)50);
    OS_TaskCreate(&th_t2, NULL, th_fn, (void*)50);

    printf("main thread id: %lx\n", OS_pthread_self());
    OS_pthread_join(th_t1, NULL);
    OS_pthread_join(th_t2, NULL);

    // while (1)
    // {
    //     // sleep(2);
    // }
    
    printf("==============APP complete==============\n");
    return 0;
}   