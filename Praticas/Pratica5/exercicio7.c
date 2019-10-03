#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int N=0, i=0, aux=0;

	for (i = 0; i <= 1000; ++i)
	{
		if (i%3==0 || i%5==0)
		{
			aux+=i;
		}
	}

	printf("%d\n", aux);
}