#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	float vetor[5], aux=0, soma=0, media=0;
	int i=0;

	for (i = 0; i < 5; ++i)
	{
		scanf("%f", &vetor[i]);
		soma+=vetor[i];

		if(i==4)//para não usar outro for
		{
			printf("%.1f\n", vetor[0]);
			printf("%.1f\n", vetor[1]);
			printf("%.1f\n", vetor[2]);
			printf("%.1f\n", vetor[3]);
			printf("%.1f\n", vetor[4]);
		}
	}

	media=soma/5;

	printf("media: %.2f\n", media);
}