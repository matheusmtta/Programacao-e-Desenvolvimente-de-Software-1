#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n)
{
	int fac;

	for(fac = 1; n > 1; n = n - 1)
		fac = fac * n;

	return fac;
}

void main()
{
	int n=0, aux=0, i=0, j=0, fac=0;
	float result=0;

	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
		fac=factorial(i);
		result += 1.0/fac;
		printf("i: %d factorial: %d resultRecorr: %.3f\n", i, fac, result);
	}


	printf("Resultado final: %.3f\n", result);
}