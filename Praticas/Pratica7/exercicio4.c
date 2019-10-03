#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int i=0, aux=0, k=0, j=0;
	float vetor[10], sum=0;

	for (i = 0; i < 10; ++i)
	{
		scanf("%f", &vetor[i]);

		if (vetor[i]>=0)
		{
			sum+=vetor[i];
			//printf("%.2f\n", sum);
		}

		else if(vetor[i]<0)
		{
			printf("negativo(s): %.2f\n", vetor[i]);
		}
	}

	printf("Soma positivos: %.2f\n", sum);
}