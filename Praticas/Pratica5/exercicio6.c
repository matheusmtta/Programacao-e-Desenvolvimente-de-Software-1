#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int N=0, i=0, aux=0;

	scanf("%d", &N);

	for (i = 1; i <= N; ++i)
	{
		if (N%i==0)
		{
			printf("%d ", i);
			aux++;
		}
	}

	printf("\n");

	if (aux==2)
	{
		printf("%d e primo.\n", N);
	}

	else if (aux!=2)
	{
		printf("%d e composto.\n", N);
	}
}