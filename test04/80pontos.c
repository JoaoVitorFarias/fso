#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc,char *argv[])
{ 
    FILE *arq;
    FILE *arq2;

    int count = 0;
    char a, b;


    for (int i = 1; i < argc; i++)
    {
        for (int j = i+1 ; j < argc; j++)
        {
            arq = fopen( argv[i], "r");
            arq2 = fopen(argv[j], "r");
              
            do {
                a = fgetc(arq);
                b = fgetc(arq2);

                if (a != b)
                {
                    count = 1;
                    break;
                }
            } while (a != EOF && b != EOF);


            if (count == 1)
            {
                printf("%s %s diferentes\n", argv[i], argv[j]);
            }
            else
            {
                printf("%s %s iguais\n", argv[i], argv[j]);
            }
            count = 0;

            fclose(arq);
            fclose(arq2);
        }
    }       
    return 0;
}
