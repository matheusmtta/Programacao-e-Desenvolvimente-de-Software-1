#include <stdio.h>

void swap(float *c, float *b)
{
	float aux;
	aux = *c;
	*c=*b;
	*b=aux;
}

void main(){

	float x, y;
	float *c, *b;

	scanf("%f %f", &x, &y);

	c=&x;
	b=&y;

    swap(c, b);

    printf("x= %f\n", x);
    printf("y= %f\n", y);
}
