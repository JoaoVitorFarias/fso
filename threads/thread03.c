// Compile: gcc file.c -o prog_name -pthread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> // sleep library

void *function(void *a)
{
   (*((int*)a))++;
    sleep(2);
    (*((int*)a))++;
    printf("dormindo\n");
    sleep(5);
    printf("acabando\n");
    // exit(0); finish all the threads, not just the one that called
}

int main (void)
{
    pthread_t tid;
    int a = 10;
    printf("a= %d\n", a);
    pthread_create (&tid, NULL, &function, (void*)&a);
    printf("tread criada\n");
    sleep(1);
    printf("a= %d\n", a);
    a++;
    pthread_join(tid, NULL);
    printf("a= %d\n", a);
    return 0;
}