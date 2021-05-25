#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>


int password = 0;

void treatSignal (int sig)
{
  printf("Recebi %d\n", sig);

  if  (sig == SIGINT)
  {
    password = 1;
  }
  else if (password == 1 && sig == SIGUSR2)
  {
    password++;
  }
  else if (password == 2 && sig == SIGTERM)
  {
    password++;
    printf ("Senha acionada\n");
  }
  else if (password == 3 && sig == SIGUSR1)
  {
    printf (" Tchau\n");
    exit (0);
  } 
  else 
  {
    password = 0;
  }

}



 int main (void)
 {
   signal (SIGINT, treatSignal);
   signal (SIGTERM, treatSignal);
   signal (SIGUSR1, treatSignal);
   signal (SIGUSR2, treatSignal);

   while (1)
   {
     pause();
   }

  return 0;
 }
