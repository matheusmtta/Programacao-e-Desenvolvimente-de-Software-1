#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int a=0, n=0, aux=0, i=0, j=0, k=1;

	scanf("%d", &n);

	for (i = 1; i <= n; ++i)
	{
		if (n%i==0)
		{
			aux++;
			printf("n e divisivel por %d\n", i);
		}
	}

	if (aux>2)
	{
		printf("N e um numero composto com %d divisores.\n", aux);
	}

	else if (aux==1)
	{
		printf("N e um numero unitario onde o unico divisor e ele mesmo.\n");
	}

	else if (aux==2)
	{
		printf("N e um numero primo, seus unicos divisores sao N e 1.\n");
	}
}