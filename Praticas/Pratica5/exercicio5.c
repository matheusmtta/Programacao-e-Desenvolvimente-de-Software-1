#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int N[10], i=0, z=0, auxh=0, auxl=0;

	for (i=0; i < 10; ++i)
	{
		scanf("%d", &N[i]);

		if(i>=1)
		{
			if(N[i]>=auxh)
			{
				auxh=N[i];
			}

			else if (N[i]<=auxl)
			{
				auxl=N[i];
			}
		}

		else
		{
			auxh=N[i];
			auxl=N[i];
		}

		z+=N[i];
	}

	printf("Maior: %d\n", auxh);
	printf("Menor: %d\n", auxl);
	printf("media: %d\n", z/10);
	printf("soma: %d\n", z);
}