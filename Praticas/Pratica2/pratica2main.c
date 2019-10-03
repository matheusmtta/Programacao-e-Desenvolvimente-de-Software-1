#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pratica2.h"


int main(){

	int	f1=0;
	float aux=0, x=0, mi=0, beta=0, z=0, b=0, fx=0;

	printf("Choose one function option:\n");
	printf("(1) Cauchy padrao\n");
	printf("(2) Gumbel\n");
	printf("(3) Laplace\n");

	scanf("%d", &f1);

	if (f1==1)//Cauchy padrao
	{
		printf("Enter the value of x\n");
		scanf("%f", &x);
		fx = cauchyPadrao(x);
	}

	if (f1==2)//Gumbel
	{
		printf("Enter the value of x, MI e BETA:\n");
		scanf("%f %f %f", &x, &mi, &beta);
		fx = Gumbel(x, mi, beta);
	}

	if (f1==3)//Laplace
	{
		printf("Enter the value of x, MI e b\n");
		scanf("%f %f %f", &x, &mi, &b);
		fx = Laplace(x, mi, b);
	}

	printf("Function result: %f\n", fx);


	return 0;
}

	