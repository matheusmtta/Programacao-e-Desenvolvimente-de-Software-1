#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverse(int *x, int size){
	//printf("x: %d y: %d\n", x, y);
	if (size<=1){
		return 0;
	}
	int aux;
	aux=x[0];
	x[0]=x[size-1];
	x[size-1]=aux;
	inverse(&x[1], size-2);
}

int main(){

	int x=0, i=0, aux=0, num=0;
	int *v=0;

	printf("Qual sera o tamanho do seu numero, em digitos (para alocagem de memoria):\n");
	scanf("%d", &num);

	v = (int*)malloc(sizeof(int)*num);

	printf("Digite um numero x de %d elementos:\n", num);
	scanf("%d", &x);

	for (i = num-1; i >= 0; --i){
		v[i]=x%10;
		x/=10;
	}

	printf("Normal:");
	for (i = 0; i < num; ++i){
		printf("%d", v[i]);
	}

	inverse(v, num);

	printf("\nInvertido:");
	for (i = 0; i < num; ++i){
		printf("%d", v[i]);
	}
}