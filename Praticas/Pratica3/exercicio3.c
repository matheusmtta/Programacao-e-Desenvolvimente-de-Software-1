#include <stdio.h>
#include <stdlib.h>

void main()
{
	float x, y, z;
	float *aux, *ptr;
	scanf("%f %f", &x, &y);

	z = x;

	aux = &x;
	ptr = &y;

	*aux = y;
	*ptr = z;



	printf("x= %f y= %f\n", x, y);

}