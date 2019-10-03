#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float converse(float x)
	{ //pratica 1a
		int aux=0;
		float result=0;

		aux=x/1;
		result=aux*1.0;
		return result;
	}

	float fractionSteal(float x)
	{ //pratica 1b
		int aux=0;
		float result=0;

		aux=x;
		result=x-aux;
		return result;
	}

	float divide(float a, float b)
	{
		float result=0;

		result=a/b;
		return result;
	}

int main()
{
	int aux=0, p=0, z;
		char auxc;
		float x=0, result1a=0, result1b=0, result1c=0, result1d=0, a=0, b=0, w;

		printf("Digite o numero do exercicio:\n");
		scanf("%d", &p);

		if (p==1)//pratica 1
		{

			printf("Exercicio 1\n");

			printf("1a) e 1b) Digite o numero x:\n");
			scanf(" %f", &x);

			result1a=converse(x);
			result1b=fractionSteal(x);

			printf("Resultado 1a: %.1f\n", result1a);//resultado 1 a
			printf("Resultado 1b: %f\n", result1b);//resultado 1 b

			//1C--------------------------------------------------
			printf("1c) Digite os numeros a e b:\n");
			scanf("%f %f", &a, &b);

			result1c=divide(a, b);
			printf("Resultado 1c: %f\n", result1c);//resultado 1 c

	return 0;
}