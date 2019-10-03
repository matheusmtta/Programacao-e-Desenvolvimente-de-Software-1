#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int a=0, n=0, aux=0, i=0, j=0, k=1;

	scanf("%d", &n);

	for (i = 1; i < n; ++i)
	{
		a=i;
		while(a>0)
		{
			printf("%d ", k++);
			a--;
		}
		printf("\n");
	}
}