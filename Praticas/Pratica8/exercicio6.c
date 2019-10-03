#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main(){

    int i, n;
    scanf("%d", &n);
    getchar();

    char palavra[MAX], cifra[MAX];
    fgets(palavra, MAX, stdin);


    for(i=0; i<strlen(palavra); i++){
        if((palavra[i]>=65 && palavra[i]<=90) || (palavra[i]>=97 && palavra[i]<=122)){
            palavra[i] += n;
            if(palavra[i]>90 && palavra[i]<97){
                palavra[i] -= 26;
            } else if(palavra[i]>122){
                palavra[i] -= 26 + n;
            }
        }

        printf("%c", palavra[i]);
    }
return 0;
}
