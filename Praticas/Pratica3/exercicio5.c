#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long fast_pow_2(int exp)
{
	int i=0;
	i = 1 << exp;
	return i;
}


int	main()
{
	int exp=0, k=0, aux=0, x=0, i=0;

	for (exp = 0; exp <= 32; ++exp)
			{
				i=fast_pow_2(exp);
				printf("2^%d= %lu\n", exp, i);
			}		


	return 0;
}