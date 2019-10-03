#include <stdio.h>
#include <stdlib.h>

int powY(int x, int y){
	//printf("x: %d y: %d\n", x, y);
	if (y==0){
		return 1;
	}

	else{ 
		return x*powY(x , y-1);
	}
}

int main(){

	int x=0, y=0, P=0;

	printf("Digite um numero x e y para ser realizada a conta x^y:\n");
	scanf("%d %d", &x, &y);

	P=powY(x, y);
	printf("Potencia x^y: %d\n", P);
}