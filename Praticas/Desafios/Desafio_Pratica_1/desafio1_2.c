#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

	char solido[1000];
	float d=0, h=0, r=0, V=0, l=0, c=0;

	printf("Digite o nome do solido:\n");
	scanf("%c", &solido);

	if (solido[0]=='c')
	{
		printf("Digite o diametro e a altura do cilindro, respetivamente:\n\n");
		fflush(stdin);
		scanf(" %f %f", &d, &h);
		r=d/2;
		V=((r*r)*3.14)*h;
		printf("O volume do cilindro e: %.2f\n", V);
	}

	else if (solido[0]=='p')
	{
		printf("Digite a altura, a largura e o comprimento do paralelepipedo, respetivamente:\n");
		fflush(stdin);
		scanf(" %f %f %f", &h, &l, &c);
		V=h*l*c;
		printf("O volume do paralelepipedo e: %.2f\n", V);
	}

	

	return 0;
}