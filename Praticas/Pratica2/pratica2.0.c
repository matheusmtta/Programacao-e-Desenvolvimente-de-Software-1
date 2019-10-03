#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 0.5772156649
#define PI 3.141592
	
	float cauchyPadrao(float x)
	{
		float y;
		y=1/(M_PI*(1+x*x));
		return y;
	}

	float Gumbel(float x, float mi, float beta)
	{
		float y;
		float z;
		z=(x-mi)/beta;
		y=(1/beta)*exp(-(z+exp(-z)));
		return y;
	}

	float Laplace(float x, float mi, float b)
	{
		float y0 = -x+mi;
		float y1 = -fabs(y0)/b;
		float y2 = exp(y1);
		float y3 = 1.0/(2*b);
		float y4 = y3*y2;
		float y = y4;
		return y;
	}

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

	