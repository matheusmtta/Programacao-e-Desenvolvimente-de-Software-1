#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *file;
	file=fopen("cartelas.txt", "r");

	int *list;
	int count=0;
	int win=1;
	int i=0;

	list = (int *) malloc(sizeof(int) * 1000000 * 6);

	while(!feof(file)){

		fscanf(file,"%d %d %d %d %d %d\n", &list[0+count], &list[1+count], &list[2+count], &list[3+count], &list[4+count], &list[5+count]);
		count+=6;
	}

	fclose(file);

	while (i < (1000000 *6))
	{
		if  ((list[0+i]==6 || list[0+i]==9 || list[0+i]==22  || list[0+i]==23 || list[0+i]==48  || list[0+i]==52) &&
			 (list[1+i]==6 || list[1+i]==9 || list[1+i]==22  || list[1+i]==23 || list[1+i]==48  || list[1+i]==52) &&
			 (list[2+i]==6 || list[2+i]==9 || list[2+i]==22  || list[2+i]==23 || list[2+i]==48  || list[2+i]==52) &&
			 (list[3+i]==6 || list[3+i]==9 || list[3+i]==22  || list[3+i]==23 || list[3+i]==48  || list[3+i]==52) &&
			 (list[4+i]==6 || list[4+i]==9 || list[4+i]==22  || list[4+i]==23 || list[4+i]==48  || list[4+i]==52) &&
			 (list[5+i]==6 || list[5+i]==9 || list[5+i]==22  || list[5+i]==23 || list[5+i]==48  || list[5+i]==52)) {
			
				printf("A cartela vencedora foi a %d\n", win);
			}

		else if ((list[0+i]==4 || list[0+i]==8 || list[0+i]==15  || list[0+i]==16 || list[0+i]==23  || list[1+i]==42) &&
				 (list[1+i]==4 || list[1+i]==8 || list[1+i]==15  || list[1+i]==16 || list[1+i]==23  || list[1+i]==42) &&
				 (list[2+i]==4 || list[2+i]==8 || list[2+i]==15  || list[2+i]==16 || list[2+i]==23  || list[2+i]==42) &&
				 (list[3+i]==4 || list[3+i]==8 || list[3+i]==15  || list[3+i]==16 || list[3+i]==23  || list[3+i]==42) &&
				 (list[4+i]==4 || list[4+i]==8 || list[4+i]==15  || list[4+i]==16 || list[4+i]==23  || list[4+i]==42) &&
				 (list[5+i]==4 || list[5+i]==8 || list[5+i]==15  || list[5+i]==16 || list[5+i]==23  || list[5+i]==42)){

				printf("Cartela com o numero do LOST: %d\n", win);
		}
		win++;
		i+=6;
	}
}