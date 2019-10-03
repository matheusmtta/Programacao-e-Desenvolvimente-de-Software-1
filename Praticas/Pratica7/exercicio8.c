#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){

    int n=0, i=0, vetor[10], aux=0, k=0;

    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &vetor[i]);

        if (i>=1)
          {
              for (k = 0; k < i; k++)
              {
                  if (vetor[i]==vetor[k])
                  {
                    printf("ERROR: VALOR JA EXISTENTE.\n");
                    i-=1;
                    continue;
                  }
              }
          }  
    } 

    for (i = 0; i < 10; ++i)
    {
        printf("posicao(%d): %d\n", i, vetor[i]);
    }
}