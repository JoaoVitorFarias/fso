#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void treatSignal (int sig)
{

}

int main (void)
 {
   signal (SIGUSR1, treatSignal);
   signal (SIGUSR2, treatSignal);

    pause();

    pid_t p;
    p = fork();

    if (p == 0)
    {
        exit(0);
    }else if (p>0){
        pause();
        wait(NULL);
    }

    pause();

  return 0;
 }