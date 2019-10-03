#include <stdio.h>
#include <stdlib.h>

void sortArray(int *array){

	int i=0;
	int j=0;
	int aux;

		for (i = 0; i < 6; ++i){

			for (j = 0; j < 6; ++j){

				if (array[j] > array[i]){
					
					aux=array[i];
					array[i]=array[j];
					array[j]=aux;
				}
			}
		}
}

int main(){
	
	FILE *file;
	file=fopen("cartelas.txt", "r");

	int *list;
	int count=0;
	int win=1;
	int i=0;
	int j=0;
	int array[6];

	list = (int *) malloc(sizeof(int) * 1000000 * 6);

	while(!feof(file)){

		fscanf(file,"%d %d %d %d %d %d\n", &list[0+count], &list[1+count], &list[2+count], &list[3+count], &list[4+count], &list[5+count]);
		count+=6;
	}

	fclose(file);

	while (i < (1000000 *6)){

			for (j = 0; j < 6; ++j){

					array[j]=list[i+j];
			}

			sortArray(array);

			for (j = 0; j < 6; ++j){

					list[i+j]=array[j];
			}

			i+=6;
	}

	i=0;

	while (i < (1000000 * 6)){

			count=0;

			if ((list[0+i]==6) && (list[1+i]==9) && (list[2+i]==22) && (list[3+i]==23) && (list[4+i]==48) && (list[5+i]==52)){
				printf("A COMBINACAO %d ACERTOU TODOS OS NUMEROS, E VENCEU A LOTERIA!!!\n", i/6);
			}

			if (list[0+i]==6){
				count+=1;
			}

			if (list[1+i]==9){
				count+=1;
			}

			if (list[2+i]==22){
				count+=1;
			}

			if (list[3+i]==23){
				count+=1;
			}

			if (list[4+i]==48){
				count+=1;
			}

			if (list[5+i]==52){
				count+=1;
			}

			if (count==4)
				printf("A COMBINACAOO %d ACERTOU A QUADRA!!!\n", i/6);

			else if (count==5)
				printf("A COMBINACAOO %d ACERTOU A QUINA!!!\n", i/6);

			i+=6;
	}
}