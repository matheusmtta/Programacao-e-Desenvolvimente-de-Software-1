#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int vetor[8], i=0, aux=0, k=0, j=0;

	for (i = 0; i < 8; ++i)
	{
		scanf("%d", &vetor[i]);
	}

	printf("Digite dois valores entre 0 e 7:\n");
	scanf("%d %d", &k, &j);

	printf("posicao %d: %d \nposicao %d: %d\n", k, vetor[k], j, vetor[j]);
}