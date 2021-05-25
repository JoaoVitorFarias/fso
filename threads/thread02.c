// Compile: gcc file.c -o prog_name -pthread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> // sleep library

void *function(void *a)
{
   *((int*)a) = 444;
    while(1);
}

int main (void)
{
    pthread_t tid;
    int a = 10;
    printf("a= %d\n", a);
    pthread_create (&tid, NULL, &function, (void*)&a);
    printf("tread criada\n");
    sleep(10); // the wait is necessary for the thread to be created
    printf("a= %d\n", a);
    sleep(10);

    return 0;
}