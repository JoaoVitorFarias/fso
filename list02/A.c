#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int vetor [10000000];
int vetor2 [10000000];

struct status_thread
{
    int *v;
    int size;
    pthread_t tid;
};

struct compare_thread
{
    int begin; //ini
    int end; //fin
    pthread_t tid;
    int result;
};

int compare (const void *a, const void *b)
{
    if (*(int*)a > *(int*)b)
    {
        return 1;
    } 
    if (*(int*)a < *(int*)b) 
    {
        return -1;
    }
    return 0;
}

void *threadFunction(void *p)
{
    struct status_thread *a=(struct status_thread*)p;
    qsort(a->v, a->size, sizeof(int), compare);
}


void *threadCompare(void *p)
{
    struct compare_thread *a=(struct compare_thread*)p;
    for (int i=a->begin; i<a->end; i++)
    {
        if(vetor[i] != vetor2[i])
        {
            a->result=0;
            return NULL;
        }
    }
    a->result=1;
}

int main(void)
{
    int tvetor;
    scanf("%d", &tvetor);
    for (int i=0; i<tvetor; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i=0; i<tvetor; i++)
    {
        scanf("%d", &vetor2[i]);
    }

    struct status_thread t1, t2;
    t1.v = vetor;
    t1.size = tvetor;

    t2.v = vetor2;
    t2.size = tvetor;

    pthread_create (&t1.tid, NULL, threadFunction, (void*)&t1);
    pthread_create (&t2.tid, NULL, threadFunction, (void*)&t2);
    pthread_join (t1.tid, NULL);
    pthread_join (t2.tid, NULL);

    struct compare_thread c1, c2;
    c1.begin = 0;
    c1.end = tvetor/2;

    c2.begin = tvetor/2;
    c2.end = tvetor;

    pthread_create (&c1.tid, NULL, threadCompare, (void*)&c1);
    pthread_create (&c2.tid, NULL, threadCompare, (void*)&c2);
    pthread_join (c1.tid, NULL);
    pthread_join (c2.tid, NULL);

    if (c1.result == 1 && c2.result == 1)
    {
        printf("Mesmos elementos\n");
    }
    else
    {
        printf("Diferentes\n");
    }

    return 0;
}
