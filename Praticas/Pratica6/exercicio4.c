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
	int n=0, aux=0, i=0, j=0, fac=1;

	scanf("%d", &n);

	//for(fac = 1; n > 1; n = n - 1)
	//	fac = fac * n;

	fac=factorial(n);

	printf("%d\n", fac);
}