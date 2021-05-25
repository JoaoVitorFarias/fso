#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void dowhatfatherdo()
{
    printf("%d: SOu pai\n", getpid());
    pid_t p;
    p = fork();

    if (p==0)
    {
        dowhatsondo();
    }
    int ret;
    p = wait(&ret);
    printf("Filho %d terminou com %d, tambem vou", p, WEXITSTATUS(ret));
    p = wait(&ret);
    printf("Filho %d terminou com %d, tambem vou", p, WEXITSTATUS(ret));
    exit(0);
}

void dowhatsondo()
{
    printf("%d: Sou o filho e meu pai eh%d\n", getpid(), getpped());
    /*
    if add exit(0) here, the program finish without come to the main, making a zumbie process.
    */
    sleep(5);
    printf("%d: Sou o filho e meu pai eh%d\n", getpid(), getpped());
}

int main (void)
{
     pid_t p;
     p = fork();
     if (p>0)
     {
         dowhatfatherdo();
     }
     else if (p==0)
     {
         dowhatsondo();
     }
     else
     {
        printf("FORK falhou!\n");
     }
     sleep(20);
}