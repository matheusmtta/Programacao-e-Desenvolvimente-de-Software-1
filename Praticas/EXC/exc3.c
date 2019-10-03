#include <stdio.h>
#include <stdlib.h>

int grow(int n){
	if (n==0){
		printf("%d ", n);
		return 1;
	}
	else{
		grow(n-1);
		printf("%d ", n);
	}
}

void main(){	
	int n=0, sum=0;
	scanf("%d", &n);
	grow(n);
}