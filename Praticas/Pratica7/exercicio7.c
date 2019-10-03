#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void main(){

    int n=0, i=0, vetor[100], vetorB[n], aux=0, k=0, j=0;

    srand(time(NULL));

    for (i = 0; i < 100; ++i)
    {
        vetor[i] = rand() % 50;

        if (i>=1)
          {
              for (k = 0; k < i; k++)
              {
                  if (vetor[i]==vetor[k])
                  {
                      printf("%d\t", vetor[i]);
                      break;
                  }
              }
          }  
    } 

    for (i = 0; i < n; ++i)
    {
        printf("posicao(%d): %d\n", i, vetorB[i]);
    }
}