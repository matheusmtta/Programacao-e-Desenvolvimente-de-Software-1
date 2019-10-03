#include <stdio.h>
#include <stdlib.h>

void decresce(int n){
	if (n==-1) exit(0);
	else{
			printf("%d ", n);
			return decresce(n-1);
		}
}

void main(){	
	int n=0, sum=0;
	scanf("%d", &n);
	decresce(n);
}