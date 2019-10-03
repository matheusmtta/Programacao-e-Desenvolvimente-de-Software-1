#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void toUpperCase(char *string)
{
  int i=0, aux=0, x=0;

  strlen(string);

  for (i = 0; i < x; ++i)
  {
    if (string[i]>92)
    {
      string[i]-=32;
    }
  }
}

void main()
{
  char string[128];
  int i=0, k=0, x=0, aux=0, pal=0;

  gets(string);
  x=strlen(string);
  
  printf("Usar stupr() - 1\n");
  printf("Usar funcao original - 2\n");

  strupr(string);

  scanf("%d", &aux);

  if (aux==1)
  {
    strupr(string);
  }

  else if(aux==2)
  {
    toUpperCase(string);
  }

  printf("%s\n", string);
}
