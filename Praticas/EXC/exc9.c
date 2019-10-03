#include <stdio.h>
#include <stdlib.h>

int toBinary(int n){
	printf("%d\n", n);
	if (n==0) return 0;
	else return n%2+10*toBinary(n/=2);
}

void main(){

	int n=0, binary=0;
	scanf("%d", &n);

	toBinary(n);

	printf("%d\n", binary);
}