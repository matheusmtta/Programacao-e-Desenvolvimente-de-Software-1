#include <stdio.h>
#include <stdlib.h>

int pown3(int n){
	if (n==1) return 1;
	else return n*n*n+pown3(n-1);
}

void main(){	
	int n=0, sum=0;
	scanf("%d", &n);
	sum=pown3(n);
	printf("%d\n", sum);
}