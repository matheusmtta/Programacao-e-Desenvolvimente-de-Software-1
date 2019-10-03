#include <stdio.h>
#include <stdlib.h>

int Sum(int *vet, int n){
	if (n<0){
		return 0;
	}
	else{
		return vet[n]+Sum(vet, n-1);
	}
}

void main(){	
	int n;
	int i=0;
	int sum=0;
	int *v;

	printf("Qual sera o tamanho do vetor?\n");
	scanf("%d", &n);

	v = (int *) malloc(n * sizeof(int));

	for (i = 0; i < n; ++i){
		v[i]=1;
		//DEBUG printf("v[%d]=%d\n", i, v[i]);
	}

	sum=Sum(v, n-1);

	printf("%d\n", sum);
}