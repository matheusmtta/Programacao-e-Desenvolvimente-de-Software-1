#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void main()
{
  char string[128];
  int i=0, k=0, x=0, aux=0, pal=0;

  gets(string);
  x=strlen(string);
  aux=x-1;

  printf("%s\n", string);

  char contrario[x];

  for (i = 0; i < x; ++i)
  {
  	contrario[i]=string[aux];
  	aux--;
  }

  aux=x-1;

  //printf("%s\n", contrario);

  for (i = 0; i < x; ++i)
  {
  	if (string[i]==contrario[i])
  	{
	  pal+=1; 	
  	}
  	aux--;
  }

  if (pal==x)
  {
  	printf("%s e um palindromo.\n", string);
  }

  else
  {
  	printf("%s nao e um palindromo.\n", string);
  }

}
