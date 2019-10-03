#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int i=0, aux=0, x[100], y=7, z=0;

	while(i<100)
	{
		if (y%7==0)
		{
			x[i]=y;
			//printf("%d\n", i);
			printf("%d\t", x[i]);
			i++;
		}
		y++;
	}
}