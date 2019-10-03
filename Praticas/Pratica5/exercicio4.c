#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int N=0, i=0, z=0;

	scanf("%d", &N);

	for (i=0; i <= N; --N)
	{
		if(N%2==0)
		z+=N;
	}

	printf("%d\n", z);
}