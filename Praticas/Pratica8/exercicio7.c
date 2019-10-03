#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main(){

    int i, soma = 0, a, j = 1;
    char numeroRomano[MAX];
    fgets(numeroRomano, MAX, stdin);
    int NPC[MAX];

    strupr(numeroRomano);

    for(i = 0; i < MAX; i++){
        if(numeroRomano[i]=='I'){
            a = 1;
        } else if(numeroRomano[i] == 'V'){
            a = 5;
        } else if(numeroRomano[i] == 'X'){
            a = 10;
        } else if(numeroRomano[i] == 'L'){
            a = 50;
        } else if(numeroRomano[i] == 'C'){
            a = 100;
        } else if(numeroRomano[i] == 'D'){
            a = 500;
        } else if(numeroRomano[i] == 'M'){
            a = 1000;
        }

        NPC[i] = a;
    }

    for(i = strlen(numeroRomano); i>0; i--){
        if(NPC[i] > NPC[i-1]){
        NPC[i] = NPC[i] - NPC[i-1];
        NPC[i-1] = 0;
        }
    }

    for(i = 0; i < strlen(numeroRomano)-1; i++){
        soma += NPC[i];
    }

    printf("%d", soma);

return 0;
}
