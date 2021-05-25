#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>


int sinal = 0;

void treatSignal (int sig)
{

  if (sig == SIGUSR1)
  {
    printf ("SIGUSR1 eh para aproveitar mais um pouco\n");
  }

  if (sig == SIGALRM && sinal == 2)
  {
    printf ("Os incomodados que se mudem, tchau\n");
    exit (0);
  }
  else if (sig == SIGALRM)
  {
    printf ("Ai que sono, quero dormir mais um pouco\n");
    sinal++;
  }
}


 int main (void)
 {
   signal (SIGALRM, treatSignal);
   signal (SIGUSR1, treatSignal);

   while (1)
   {
     pause();
   }

  return 0;
 }
