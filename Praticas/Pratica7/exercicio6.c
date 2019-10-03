#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int n=0, i=0, aux=0, y=0;

	scanf("%d", &n);

	float vetor[n], vetorQ[n];

	for (i = 0; i < n; ++i)
	{
		scanf("%f", &vetor[i]);
		vetorQ[i]=vetor[i]*vetor[i];
	}

	for (i = 0; i < n; ++i)
	{
		printf("%.2f^2 = %.2f\n",vetor[i], vetorQ[i]);
	}
}