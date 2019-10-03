#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

int main(){

    char vetor[MAX], sobrenome[MAX];
    fgets(vetor, MAX, stdin);

    int i, j, pos = 0;
    for(i=0; i<strlen(vetor); i++){
        if(vetor[i]==' '){
            for(j=i; j<strlen(vetor); j++, ++pos){
                sobrenome[pos-1] = vetor[j];
                sobrenome[pos] = '\0';
            }
            vetor[i] = '\0';
            break;
        }
    }

    printf("%s%s", sobrenome, vetor);

return 0;
}
