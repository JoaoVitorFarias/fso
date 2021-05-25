#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

unsigned int S1 = 0, S2 = 0;
int vetor1 [200000];
int vetor2 [100000];
int result [301];

struct status_thread
{
    unsigned int Bi[301];
    unsigned int Mi[301];
    int v;
    pthread_t tid;
};


void generate()
{
    unsigned int semente;
    semente = S1;
    for(int i = 0; i < 100000; i++ )
    {
        vetor1[i] = rand_r(&semente);
    }
    semente = S2;
    for(int i = 0; i < 100000; i++ )
    {
        vetor2[i] = rand_r(&semente);
    }
}


void *thread_function( void *p)
{
    struct status_thread *a = (struct status_thread*)p;
    
    if(a->v == 1)
    { 
        for (int i = 0; i < 301; i++)
        {
            for(int j=0; j<100000; j++ )
            {
                if (vetor1[j]%a->Mi[i] == a->Bi[i])
                {
                    result[j]++;
                }
            }
        }  
    }
    if(a->v == 2)
    { 
        for (int i = 0; i < 301; i++ )
        {
            for(int j=0; j<100000; j++ )
            {
                if (vetor2[j]%a->Mi[i] == a->Bi[i])
                {  
                    result[j]++;
                  
                }
            }
        }  
    }

}

int main(void)
{

    unsigned int aux = 0;
    scanf("%u", &S1);
    S1 = aux;
    scanf("%u", &aux);
    S2 = aux;
    generate();

    struct status_thread t1, t2;
    int i = 0;

    while (scanf("%u %u", &t1.Mi[i], &t1.Bi[i]) != EOF) 
    {   
        t2.Mi[i] = t1.Mi[i];
        t2.Bi[i] = t1.Bi[i];
        i++;
    } 
  
    t1.v = 1;
    t2.v = 2;

    pthread_create (&t1.tid, NULL, thread_function, (void*)&t1);
    pthread_create (&t2.tid, NULL, thread_function, (void*)&t2);
    pthread_join (t1.tid, NULL);
    pthread_join (t2.tid, NULL);
    
    for (int j = 0; j<301; j++)
    {
        printf("%d\n", result[j]);
    }

    
    return 0;
}