#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include <time.h>

void introGM(){
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		    printf(  "\t _______     _______     ___    __     __     __     _______ \n");
			printf("\t/ ______|   |  _____|   |   \\   | |   |  |   |  |   |  ___  |\n");
			printf("\t| |_____    |  |___     | |\\ \\  | |   |  |___|  |   | |___| |\n");
			printf("\t| _____ |   |   ___|    | | \\ \\ | |   |   ___   |   |  ___  |\n");
			printf("\t _____| |   |  |____    | |  \\ \\| |   |  |   |  |   | |   | |\n");
			printf("\t/_______|   |_______|   |_|   \\___|   |__|   |__|   |_|   |_|\n");

			printf("\n\n\n\n");

			printf(">Escolha seu modo de jogo:\n\n");
			printf("\t\t(1) Nivel iniciante\n");
			printf("\t\t(2) Nivel Intermediario\n");
			printf("\t\t(3) Nivel Avancado\n");
			printf("\t\n>Digite 0 para testar.\n");

			printf("\n\n\n\n");

			int gamemode;
			scanf("%d", &gamemode);

			if (gamemode==1){//fácil
					printf("\n\n\n\n\n\n\n\n\n\n\n[TUTORIAL] Modo iniciante\n");
					printf("\n\t>Bem-vindo ao jogo senha!\n\n");
					printf(">Nesse modo o jogo consiste em escolher uma combinacao de 3 numeros entre 0 e 4\n");
					printf("os quais nao podem se repetir em uma mesma combinacao, ou seja, uma senha 001 e\n");
					printf("invalida, uma vez que os numeros precisam ser diferentes entre si.\n\n");
					printf(">Durante o jogo e suas respectivas tentativas voce recebera dois tipos de dicas:\n");
					printf("\t(1 coluna) digito certo na posicao correta da combinacao de digitos\n");
					printf("\t(2 coluna) digito certo em uma posicao errada na combinacao de digitos\n\n");
					printf(">O jogo continuara recebendo novas tentativas de senha ate que voce acerte\n");
					printf("a senha secreta, ou ate que voce desista, para isso basta digitar um numero\n");
					printf("negativo em uma das posicoes de sua tentativa.\n\n");
					printf(">Boa sorte :)\n\n");
					gameMode1();//chama modo fácil
			}

			else if (gamemode==2){//médio
					printf("\n\n\n\n\n\n\n\n\n\n\n[TUTORIAL] Modo Intermediario\n\n");
					printf("\t>Bem-vindo ao jogo senha!\n\n");
					printf(">Nesse modo o jogo consiste em escolher uma combinacao de 4 numeros entre 0 e 5\n");
					printf("os quais podem se repetir em uma mesma combinacao, ou seja, uma senha 0010 e\n");
					printf("valida, uma vez que os numeros nao precisam ser diferentes entre si.\n\n");
					printf(">Durante o jogo e suas respectivas tentativas voce recebera dois tipos de dicas:\n");
					printf("\t(1 coluna) digito certo na posicao correta da combinacao de digitos\n");
					printf("\t(2 coluna) digito certo em uma posicao errada na combinacao de digitos\n\n");
					printf(">O jogo continuara recebendo novas tentativas de senha ate que voce acerte\n");
					printf("a senha secreta, ou ate que voce desista, para isso basta digitar um numero\n");
					printf("negativo em uma das posicoes de sua tentativa.\n\n");
					printf(">Boa sorte :)\n\n");
					gameMode2();//chama modo médio
			}

			else if (gamemode==3){//difícil
					printf("\n\n\n\n\n\n\n\n\n\n\n[TUTORIAL] Modo Avancado\n\n");
					printf("\t>Bem-vindo ao jogo senha!\n\n");
					printf(">Nesse modo o jogo consiste em escolher uma combinacao de 4 numeros entre 0 e 9\n");
					printf("os quais podem se repetir em uma mesma combinacao, ou seja, uma senha 0010 e\n");
					printf("valida, uma vez que os numeros nao precisam ser diferentes entre si.\n\n");
					printf(">Durante o jogo e suas respectivas tentativas voce recebera dois tipos de dicas:\n");
					printf("\t(1 coluna) digito certo na posicao correta da combinacao de digitos\n");
					printf("\t(2 coluna) digito certo em uma posicao errada na combinacao de digitos\n\n");
					printf(">O jogo continuara recebendo novas tentativas de senha ate que voce acerte\n");
					printf("a senha secreta, ou ate que voce desista, para isso basta digitar um numero\n");
					printf("negativo em uma das posicoes de sua tentativa.\n\n");
					printf(">Boa sorte :)\n\n");
					gameMode3();//chama modo difícil
			}

			else if (gamemode==0){//test
					printf("\n\n\n\n\n\n\n\n\n\n\n\t[TUTORIAL] Modo Avancado (TESTE)\n\n");
					printf("\t>Bem-vindo ao jogo senha!\n\n");
					printf(">Nesse modo o jogo consiste em escolher uma combinacao de 4 numeros entre 0 e 9\n");
					printf("os quais podem se repetir em uma mesma combinacao, ou seja, uma senha 0010 e\n");
					printf("valida, uma vez que os numeros nao precisam ser diferentes entre si.\n\n");
					printf(">Durante o jogo e suas respectivas tentativas voce recebera dois tipos de dicas:\n");
					printf("\t(1 coluna) digito certo na posicao correta da combinacao de digitos\n");
					printf("\t(2 coluna) digito certo em uma posicao errada na combinacao de digitos\n\n");
					printf(">O jogo continuara recebendo novas tentativas de senha ate que voce acerte\n");
					printf("a senha secreta, ou ate que voce desista, para isso basta digitar um numero\n");
					printf("negativo em uma das posicoes de sua tentativa.\n\n");
					printf("[OBS] NESTE MODO A SENHA GERADA SERA MOSTRADA PARA POSSIVEIS TESTES.\n");
					printf(">Boa sorte :)\n\n");
					gameModeTest();//chama modo teste, análogo ao modo difícil
			}

			else{

				printf(">ERROR: INVALID GAMEMODE\n");
				exit(0);
			}
}


void passwordGenerator(int *password, int limit, int size, int repeat){

			int i=0, j=0;

			if (repeat==0){//false, os numeros da senha nao podem se repetir

					password[0] = rand () % limit;

					for (i = 1; i < size; ++i){

						j=0;
						password[i] = rand () % limit;//variação aleatoria varia até o limite dado
					
						while(j < i){//controla a possível geração de numeros repetidos dentro do vetor

							if (password[i]==password[j]){

								password[i] = rand () % limit;//variação aleatoria varia até o limite dado
								continue;
							}

							else{

								j++;
							}
						}
					}	
			}

			else if (repeat==1){//true, os numeros da senha podem se repetir

				for (i = 0; i < size; ++i){

					password[i] = rand () % limit;//variação aleatoria varia até o limite dado
				}
			}
}

void gameMode1(){

			int password[3], attempt[3];       
			int attemptCount=1;
			int result;
			int ok;
			int tipTrue=0, tipFalse=0;
	
			int size=3;   //tamanho dos vetores do modo
			int repeat=0; //repetições: false
			int limit=5;  //limite da variação ramdomica do modo
			int skip=0;


			passwordGenerator(password, limit, size, repeat);  //chama a função que gera as senhas

			printf(">Digite uma senha de 3 digitos entre 0 e 4 que nao se repetem\n  seguindo as dicas, ateh acertar:\n\n");
			printf("\tN\tSenha\tDica\n");

			while(1){

					getAttempt(attempt, size);    //recebe um vetor ''vazio'' como parâmetro para ser preenchido com a tentativa do usuário

					ok=attemptOK(attempt, size, limit);   //verifica se a senha está dentro dos parâmeetros estabelecidos por cada modo de jogo

					if (ok==0){
						
						continue;   //caso OK==false, o programa continua sem fazer demais comparações
					}

					skipProgram(attempt, size);  //verifica se há algum numero negativo para uma possível desistência

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse); //checa o resultado da senha, false ou true, e incrementa os endereços de memória das dicas

					printAttempt(attemptCount, size, attempt, tipTrue, tipFalse);  //recebe os parâmetros da senha e as variáveis da rodada e printa para o jogador

					attemptCount++;

					if (result==1){   //caso o resultado da tentativa seja true, o jogador vence e tem a possibilidade de jogar novamente ou dar exit do programar

							int game;
							printf("\n\nParabens voce acertou!\n");
							printf("\n\n>Deseja jogar novamente ?\n");
							printf("\t(1) Sim\n");
							printf("\t(2) Nao\n");

							while(1){

								scanf("%d", &game);

								if (game==1 || game==2){

									if (game==1){

										introGM();
									}

									else if (game==2){

										exit(0);
									}
								}
							}
					}

					else if (result==0){  //caso o resultado tentativa seja false, ogame apenas continua

							continue;
					}
			}

}

void gameMode2(){

			int password[4], attempt[4];
			int attemptCount=1;
			int result;
			int tipTrue=0, tipFalse=0;
	
			int size=4;    //tamanho dos vetores do modo
			int repeat=1;  //repetições: true
			int limit=6;   //limite da variação ramdomica do modo
			int skip=0;
			int ok;

			passwordGenerator(password, limit, size, repeat);  //chama a função que gera as senhas

			printf(">Digite uma senha de 4 digitos entre 0 e 5 que podem se repetir\n  seguindo as dicas, ateh acertar:\n\n");
			printf("\tN\tSenha\tDica\n");

			while(1){

					getAttempt(attempt, size);    //recebe um vetor ''vazio'' como parâmetro para ser preenchido com a tentativa do usuário

					ok=attemptOK(attempt, size, limit);   //verifica se a senha está dentro dos parâmeetros estabelecidos por cada modo de jogo

					if (ok==0){
						
						continue;   //caso OK==false, o programa continua sem fazer demais comparações
					}

					skipProgram(attempt, size);  //verifica se há algum numero negativo para uma possível desistência

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse); //checa o resultado da senha, false ou true, e incrementa os endereços de memória das dicas

					printAttempt(attemptCount, size, attempt, tipTrue, tipFalse);   //recebe os parâmetros da senha e as variáveis da rodada e printa para o jogador

					attemptCount++;

					if (result==1){  //caso o resultado da tentativa seja true, o jogador vence e tem a possibilidade de jogar novamente ou dar exit do programar

							int game;
							printf("\n\nParabens voce acertou!\n");
							printf("\n\n>Deseja jogar novamente ?\n");
							printf("\t(1) Sim\n");
							printf("\t(2) Nao\n");

							while(1){

								scanf("%d", &game);

								if (game==1 || game==2){

									if (game==1){

										introGM();
									}

									else if (game==2){

										exit(0);
									}
								}
							}
					}

					else if (result==0){  //caso o resultado tentativa seja false, ogame apenas continua

							continue;
					}
			}

}

void gameMode3(){

			int password[4], attempt[4];
			int attemptCount=1;
			int result;
			int tipTrue=0, tipFalse=0;
	
			int size=4;    //tamanho dos vetores do modo
			int repeat=1;  //repetições: true
			int limit=10;  //limite da variação ramdomica do modo
			int skip=0;
			int ok;

			passwordGenerator(password, limit, size, repeat);  //chama a função que gera as senhas

			printf(">Digite uma senha de 4 digitos entre 0 e 9 que podem se repetir\n  seguindo as dicas, ateh acertar:\n\n");
			printf("\tN\tSenha\tDica\n");

			while(1){

					getAttempt(attempt, size);      //recebe um vetor ''vazio'' como parâmetro para ser preenchido com a tentativa do usuário

					ok=attemptOK(attempt, size, limit);  //verifica se a senha está dentro dos parâmeetros estabelecidos por cada modo de jogo

					if (ok==0){
						
						continue;  //caso OK==false, o programa continua sem fazer demais comparações
					}

					skipProgram(attempt, size);  //verifica se há algum numero negativo para uma possível desistência

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse);  //checa o resultado da senha, false ou true, e incrementa os endereços de memória das dicas

					printAttempt(attemptCount, size, attempt, tipTrue, tipFalse);   //recebe os parâmetros da senha e as variáveis da rodada e printa para o jogador

					attemptCount++;

					if (result==1){  //caso o resultado da tentativa seja true, o jogador vence e tem a possibilidade de jogar novamente ou dar exit do programar

							int game;
							printf("\n\nParabens voce acertou!\n");
							printf("\n\n>Deseja jogar novamente ?\n");
							printf("\t(1) Sim\n");
							printf("\t(2) Nao\n");

							while(1){

								scanf("%d", &game);

								if (game==1 || game==2){

									if (game==1){

										introGM();
									}

									else if (game==2){

										exit(0);
									}
								}
							}
					}

					else if (result==0){  //caso o resultado tentativa seja false, ogame apenas continua

							continue;
					}
			}

}


void gameModeTest(){

			int password[4], attempt[4];
			int attemptCount=1;
			int result;
			int tipTrue=0, tipFalse=0;
	
			int size=4;    //tamanho dos vetores do modo
			int repeat=1;  //repetições: true
			int limit=10;  //limite da variação ramdomica do modo
			int skip=0;
			int i=0;
			int ok;

			passwordGenerator(password, limit, size, repeat); //chama a função que gera as senhas

			printf(">Digite uma nova tentativa seguindo as dicas, ateh acertar:\n\n");

			printf("\n>SENHA GERADA:\t");

			for (i = 0; i < size; ++i){

				printf("%d", password[i]);	//printa a senha gerada para possíveis testes
			}

			printf("\n\n");

			printf("\tN\tSenha\tDica\n");

			while(1){

					getAttempt(attempt, size); //recebe um vetor ''vazio'' como parâmetro para ser preenchido com a tentativa do usuário

					ok=attemptOK(attempt, size, limit);  //verifica se a senha está dentro dos parâmeetros estabelecidos por cada modo de jogo

					if (ok==0){
						
						continue;   //caso OK==false, o programa continua sem fazer demais comparações
					}

					skipProgram(attempt, size);  //verifica se há algum numero negativo para uma possível desistência

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse);  //checa o resultado da senha, false ou true, e incrementa os endereços de memória das dicas

					printAttempt(attemptCount, size, attempt, tipTrue, tipFalse);   //recebe os parâmetros da senha e as variáveis da rodada e printa para o jogador

					attemptCount++;

					if (result==1){  //caso o resultado da tentativa seja true, o jogador vence e tem a possibilidade de jogar novamente ou dar exit do programar

							int game;
							printf("\n\nParabens voce acertou!\n");
							printf("\n\n>Deseja jogar novamente ?\n");
							printf("\t(1) Sim\n");
							printf("\t(2) Nao\n");

							while(1){

								scanf("%d", &game);

								if (game==1 || game==2){

									if (game==1){

										introGM();
									}

									else if (game==2){

										exit(0);
									}
								}
							}
					}

					else if (result==0){  //caso o resultado tentativa seja false, ogame apenas continua

							continue;
					}
			}

}


int checkPassword(int *password, int *attempt, int size, int *countTrue, int *countFalse){

			int controlUpFlag[size], UnderControlFlag[size]; //vetores auxiliares que controlam as comparações
			int i=0, j=0;

			*countTrue=0;   //zera os contadores de dicas
			*countFalse=0;  //seza os contadores de dicas

			for (i = 0; i < size; ++i){

					UnderControlFlag[i]=controlUpFlag[i]=0;  //zera os vetores auxiliares
			}

			for (i = 0; i < size; ++i){ //verifica digitos certos no locais certo

					if (password[i]==attempt[i]){ 

							UnderControlFlag[i]=1; //adiciona uma ''flag'' true nos vetores auxiliares para que essas posições não sejam verificadas novamentes
							controlUpFlag[i]=1;    //adiciona uma ''flag'' true nos vetores auxiliares para que essas posições não sejam verificadas novamentes
							(*countTrue)++;        //incrementa a variavel tipTrue
					}
			}

			for (i = 0; i < size; ++i){  //verifica digitos iguais em lugares diferentes entre os dois vetores (senha e tentativa)

					for (j = 0; j < size; ++j){

							if (attempt[j]==password[i] && UnderControlFlag[j]!=1 && controlUpFlag[i]!=1){

									(*countFalse)++;       //incrementa a variavel tipFalse
									UnderControlFlag[j]=1; //adiciona uma ''flag'' true nos vetores auxiliares para que essas posições não sejam verificadas novamentes
									controlUpFlag[i]=1;    //adiciona uma ''flag'' true nos vetores auxiliares para que essas posições não sejam verificadas novamentes
							}
					}
			}

			if ((*countTrue)==size){ //retorna 1 caso o resultado esteja correto ou seja, todos as posições estão certas

					return 1;
			}

			else if ((*countTrue) < size){ //retorna 0 caso o resultado esteja incorreto ou seja, algo ainda esta errado na combinação de digitos da senha

					return 0;
			}
}


void getAttempt(int *attempt, int size){  //recebe o tamanho do vetor e um apontador para o vetor ser alterado

			int i=0,j=0 , pass=0;

			scanf("%d", &pass);  //recebe a senha de size digitos (o usuario precisa dar exatamente o numero de digitos que foi pedido)

			for(i = size-1; i >= 0; i--){  //transforma o número int em posições de um vetor        
							
				attempt[i]=(pass%10);
				pass /= 10;
			}
}


void skipProgram(int *password, int size){ //testa a presença de números negativos para uma possível desistência

			int i=0;

			for (i = 0; i < size; i++){

				if (password[i]<0){ //verifica digito a digito
					
					printf("\n\nVoce desistiu :(\n");
					exit(0);
				}
			}
}

void printAttempt(int attemptCount, int size, int *attempt, int tipTrue, int tipFalse){ //printa os parâmetros da senha, tentativa, rodada e as dicas

			int i=0;

			printf("\t%d\t", attemptCount); 

			for (i = 0; i < size; i++){
								
				printf("%d", attempt[i]);
			}

			printf("\t%d %d\n", tipTrue, tipFalse);
}

int attemptOK(int *attempt, int size, int limit){ //testa se a senha está dentro dos parâmetros pré-determinados

			int i=0;
			int error=0;

			for (i = 0; i < size; ++i){
				
				if (attempt[i]>=limit){
						
						error++;
				}
			}

			if (error>0){
				
				printf("\n\n[ERRO]\n>Senha com digito(s) fora do intervalo, digite novamente.\n\n\n");
				return 0;
			}

			else {

				return 1;
			}
}
