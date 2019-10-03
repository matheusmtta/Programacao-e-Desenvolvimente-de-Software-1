#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int vetorA[8], i=0;

	for(i=0; i < 8; i++)
	{
		scanf("%d", &vetorA[i]);
	}

	for (i = 7; i >= 0; i--)
	{
		printf("%d\n", vetorA[i]);
	}
}