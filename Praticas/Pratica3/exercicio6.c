#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int evenOrOdd_plus(unsigned int x)
{
	int newX=0;
	newX =(x | 1);
	return newX;
}

int dddSteal(unsigned int n)
{
	int ddd=0;
	float x=0;
	x=n*1.0;
	ddd=x/100000000;
	return ddd;
}

int evenOrOdd(unsigned int eoo)
{
	unsigned int aux=0, result=0;
	aux=evenOrOdd_plus(eoo);
	result=aux-eoo;
	return result;
}


void main()
{
	int n=0, ddd=0, x=0, modifyX=0, eoo=0, neoo=0;

	printf("6a) Digite um numero com DDD (exemplo: 3125252525)\n");
	scanf("%d", &n);

	ddd=dddSteal(n);
	printf("Resultado: %d\n", ddd);

	printf("6b) Digite um inteiro:\n");
	scanf("%d", &x);

	modifyX=evenOrOdd_plus(x);
	printf("Resultado: %d\n", modifyX);

	printf("6c) Digite um inteiro\n");
	scanf("%d", &eoo);
	neoo=evenOrOdd(eoo);
	printf("%d\n", neoo);

}