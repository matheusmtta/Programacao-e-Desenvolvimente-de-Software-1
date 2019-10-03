#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverse(char *x, int size){
	//printf("x: %d y: %d\n", x, y);
	if (size<=1){
		return 0;
	}
	char aux;
	aux=x[0];
	x[0]=x[size-1];
	x[size-1]=aux;
	inverse(&x[1], size-2);
}

int main(){

	char x[100], y[100], P=0;

	printf("Digite uma string\n");
	fgets(x,100,(stdin));

	inverse(x, strlen(x));
	printf("invertida:%s\n", x);
}