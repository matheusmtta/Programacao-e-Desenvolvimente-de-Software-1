#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void main()
{
  char string[128];
  int i=0, k=0, x=0;

  gets(string);

  for (i = 0; i < 4; i++) {
    printf("%c", string[i]);
  }
}
