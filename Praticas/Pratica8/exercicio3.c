#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void main()
{
  char string[128];
  int i=0, k=0, x=0, vogal=0, consoante=0;

  gets(string);
  x=strlen(string);

  for (i = 0; i < x; i++)
  {
    putchar (toupper(string[i]));
  }

  for (i = 0; i < x ; i++)
  {
    if (string[i]=='A' || string[i]=='E' || string[i]=='I' || string[i]=='O' || string[i]=='U')
    {
      vogal++;
    }

    else
    {
      consoante++;
    }
  }

  printf("\nnumero de vogais: %d\nnumero de consoantes: %d\n", vogal, consoante);
}
