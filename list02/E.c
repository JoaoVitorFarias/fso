#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaforo;
int vpos[132000];
int S = 0;
int vi = 0;

struct status_thread
{
    int Mi;
    int Mf;
    pthread_t tid;
};


void record(int s)
{
    sem_wait(&semaforo);
    vpos[s] = 1;
    sem_post(&semaforo);
}


void *thread_function(void *param)
{
    struct status_thread *a = (struct status_thread*)param;
    int semente = 1;

    for (int i = a->Mi; i<= a->Mf; i++)
    {
        semente = i;
        for (int j=1; j<100000; j++ )
        {
            rand_r(&semente);
        }
        if (rand_r(&semente)%8 == S)
        {
            record(i);
        }
    }
}

void print_semente(int begin, int end)
{
    for (int i = begin; i<= end; i++)
    {
        if (vpos[i] == 1)
        {
            printf("%d\n", i);
        }
    }

}

int main (void)
{
    int begin = 0, end = 0, aux = 0;

    scanf("%d", &begin);
    scanf("%d", &end);
    scanf("%d", &aux);

    S = aux;
    sem_init(&semaforo, 0, 1);


    struct status_thread t1, t2;
    t1.Mi = begin;
    t1.Mf = (end/2);

    t2.Mi= (end/2) + 1;
    t2.Mf = end;

    pthread_create (&t1.tid, NULL, thread_function, (void*)&t1);
    pthread_create (&t2.tid, NULL, thread_function, (void*)&t2);
    pthread_join (t1.tid, NULL);
    pthread_join (t2.tid, NULL);

    print_semente(begin, end);

    return 0;
}