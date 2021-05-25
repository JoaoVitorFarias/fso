// Compile: gcc file.c -o prog_name -pthread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> // sleep library

void *function(void *a)
{
    printf("Sou uma thread\n");
    while(1);
}

int main (void)
{
    pthread_t tid;
    pthread_create (&tid, NULL, &function, NULL);
    printf("tread criada\n");
    printf("threas principal dormindo um pouco\n");
    sleep(10);
    printf("thread principal consumindo um pouco de CPU\n");
    for (int i=0; i<1000000000; i++)
    {
        getppid();
    }
        printf("threas principal dormindo um pouco\n");
    sleep(10);
    printf("tchau\n");

    return 0;
}