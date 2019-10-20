/*
 * @Date: 2019-10-20 12:22:57
 * @LastEditors: Peiyuan
 * @LastEditTime: 2019-10-21 00:10:07
 */
#include "main.h"

typedef struct
{
    char name[20];
    int time;
    int start;
    int end;
}RaceArg;

void clean_fun(void *arg)
{
    char *s = (char*)arg;
    printf("clean fun arg: %s",s);
}

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
void *th_fn(void *arg) 
{ 
    int i = 0;
    RaceArg *rec = (RaceArg*)arg;

    for (i = rec->start; i <= rec->end; i++)
    {
        /* code */
        // printf("%s run %d\n", rec->name, i);
        usleep(rec->time);
    }
    
    return (void*)1;
}

void *th_fn1(void *arg) 
{ 
    int i = 0;
    RaceArg *rec = (RaceArg*)arg;

    printf("%s running, start:%d, end:%d\n", rec->name, rec->start, rec->end);
    
    return (void*)(rec->start+rec->end);
}

void *th_fn4(void *arg) 
{ 
    int i = 0;
    RaceArg *rec = (RaceArg*)arg;

    printf("%s running, start:%d, end:%d\n", rec->name, rec->start, rec->end);

    pthread_cleanup_push(clean_fun, "fun4 clean func");
    pthread_cleanup_push(clean_fun, "fun4 clean func round 2");
    pthread_cleanup_pop(rec->start);
    pthread_cleanup_pop(rec->start);
    sleep(2);
    return (void*)(rec->start+rec->end);
}
/**
 * @description: 
 * @param {type} 
 * @return: 
 */
int main() {
    printf("==============APP entry!===============\n");
    pthread_t th_t1, th_t2, th_t3, th_t4;
    unsigned int err = 0;
    unsigned short int seed16v[3]= {1, 2, 3}; 
    int *result;
    
    seed48(seed16v);
    
    RaceArg r_a = {"rabbit", (int)(drand48()*10000), 20, 60};
    RaceArg t_a = {"turtle", (int)(drand48()*10000), 10, 50};
    RaceArg jt_a = {"join_test", (int)(drand48()*10000), 30, 70};
    RaceArg ct_a = {"clean_test", (int)(drand48()*10000), 30, 70};
    


    if((err = OS_TaskCreate(&th_t1, NULL, th_fn, (void*)&r_a)) != 0)
        printf("task(%s) create err, err(%x)", r_a.name, err);
    if((err = OS_TaskCreate(&th_t2, NULL, th_fn, (void*)&t_a)) != 0)
        printf("task(%s) create err, err(%x)", r_a.name, err);
    if((err = OS_TaskCreate(&th_t3, NULL, th_fn1, (void*)&jt_a)) != 0)
        printf("task(%s) create err, err(%x)", r_a.name, err);
    if((err = OS_TaskCreate(&th_t4, NULL, th_fn4, (void*)&ct_a)) != 0)
        printf("task(%s) create err, err(%x)", r_a.name, err);

    OS_pthread_join(th_t1, NULL);
    OS_pthread_join(th_t2, NULL);
    OS_pthread_join(th_t3, (void**)&result);
    printf("join test thread return value: %d\n", (int)result);
    OS_pthread_join(th_t4, (void**)&result);

    printf("main thread id: %lx\n", OS_pthread_self());
    
    printf("==============APP complete==============\n");
    return 0;
}   