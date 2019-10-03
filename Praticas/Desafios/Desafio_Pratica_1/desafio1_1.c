#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){


int	cod[10], i=0, aux=0, k=10, somacpf=0, dezenar=0, dezena=0, somacpfd=0, unidader=0, unidade=0;

	printf("Digite os 9 digitos do CPF:\n");

	for (i = 0; i < 9; ++i)
	{
		scanf(" %d", &cod[i]);
	}

	for (i = 0; i < 9; ++i)
	{
		aux=cod[i]*k;
		somacpf+=aux;
		k--;
	}

	printf("%d\n", somacpf);

	dezenar=somacpf%11;
	

	if (dezenar==0 || dezenar==1)
	{
		cod[9]=0;
		dezena=cod[9];
	}

	else 
	{
		dezena=11-dezenar;
		cod[9]=dezena;
	}
	
	k=11;

	for (i = 0; i < 10; ++i)
	{
		somacpfd+=cod[i]*k;
		k--;
	}

	unidader=somacpfd%11;

	if (unidader==0 || unidader==1)
	{
		unidade=0;
	}

	else 
	{
		unidade=11-unidader;
	}

	printf("CPF: ");

	for (i = 0; i < 9; ++i)
	{
		printf("%d", cod[i]);
	}

	printf("%d", dezena);
	printf("%d", unidade);

	return 0;
}

	