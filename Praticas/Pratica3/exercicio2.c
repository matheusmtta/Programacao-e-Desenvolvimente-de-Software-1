#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pointerSwap(int *auxp)
	{
		*auxp=3;
	}

	void pointerPlus(int *auxp2)
	{
		*auxp2+=1;
	}

	void pointerPlus_2_fractionSteal(float *auxp3)
	{
		*auxp3+=1;
	}


int main()
{
			int *ptr3, *k;
			char *ptr1; 
			float *ptr2;
			ptr1= &auxc;
			ptr2= &w;
			ptr3= &z;
			
			printf("Resultado 2a:\n");
			printf("Enderecos de memoria:\n");//resultado 2 b
			printf("Char: %p\n", ptr1);
			printf("Float: %p\n", ptr2);
			printf("Int: %p\n", ptr3);

			//2B--------------------------------------------------
			int o=0;
			int *auxp;
			auxp=&o;

			pointerSwap(auxp);
			printf("Resultado 2b: %d\n", o);

			//2C-------------------------------------------------
			int *auxp2;
			int var=0;
			printf("2c) Digite um numero inteiro:\n");
			scanf("%d", &var);

			auxp2=&var;

			pointerPlus(auxp2);
			printf("Resultado 2c: %d", var);//resultado 2c

			//2D-------------------------------------------------
			float var2=0;
			float *auxp3;

			printf("Digite um valor float:\n");
			scanf("%f", &var2);

			if(var2>0)
			{
				var2*=-1;
				auxp3 = &var2;

				while(var2 <= -1)
				{
					pointerPlus_2_fractionSteal(auxp3);
				}

				var2*=-1;

			}

			else if(var2<0)
			{
				auxp3=&var2;

				while(var2 < -1)
				{
					pointerPlus_2_fractionSteal(auxp3);
				}
			}

			printf("Resultado 2d: %f\n", var2);

	return 0;
}