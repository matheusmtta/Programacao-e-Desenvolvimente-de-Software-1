#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int n=0, higherN=0, lowerN=0;

	while(1)
	{
		scanf("%d", &n);

		if (n<0)
		{
			break;
		}

		else if (n>=0)
		{
			if (n>=higherN)
			{
				higherN=n;
			}

			if (n<=lowerN)
			{
				lowerN=n;
			}
		}
	}

	printf("Maior n: %d\n", higherN);
	printf("Menor n: %d\n", lowerN);
}