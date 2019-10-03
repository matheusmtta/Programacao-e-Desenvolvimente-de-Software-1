#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	float n=0, aux=0, result=0, x=0;

	scanf("%f", &n);

	result=1/((n*(n+1))/2);

	printf("%f\n", result);
}