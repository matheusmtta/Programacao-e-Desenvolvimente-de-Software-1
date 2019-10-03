#include <stdio.h>
#include <stdlib.h>
#include "jogob.h"
#include <time.h>
#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

void introGM(){


			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		    printf(  "\t _______     _______     ___    __     __     __     _______ \n");
			printf("\t/ ______|   |  _____|   |   \\   | |   |  |   |  |   |  ___  |\n");
			printf("\t| |_____    |  |___     | |\\ \\  | |   |  |___|  |   | |___| |\n");
			printf("\t| _____ |   |   ___|    | | \\ \\ | |   |   ___   |   |  ___  |\n");
			printf("\t _____| |   |  |____    | |  \\ \\| |   |  |   |  |   | |   | |\n");
			printf("\t/_______|   |_______|   |_|   \\___|   |__|   |__|   |_|   |_|  4FUN\n");

			printf("\n\n\n\n\n");

			printf(">Escolha seu modo de jogo:\n\n");
			printf("\t\t(1) Multiplayer\n");
			printf("\t\t(2) Contra o tempo\n");
			printf("\t\t(3) Qual a sua senha ?\n");
			printf("\t\t(5) Maquina x humano\n");

			printf("\n\n\n\n");

			int gamemode;
			scanf("%d", &gamemode);

			if (gamemode==1){
					gameModeMP();
			}

			else if (gamemode==2){
					gameModeCT();
			}

			else if (gamemode==3){
					gameModeQSS();
			}

			else if (gamemode==4){
					gameMode4FUN();
			}

			else if(gamemode==5){
					gameModeAS();
			}

			else{

				printf(">ERROR: INVALID GAMEMODE\n");
				exit(0);
			}
}


void passwordGenerator(int *password, int limit, int size, int repeat){

			int i=0, j=0;

			if (repeat==0){//false

					password[0] = rand () % limit;

					for (i = 1; i < size; ++i){

						j=0;
						password[i] = rand () % limit;
					
						while(j < i){

							if (password[i]==password[j]){

								password[i] = rand () % limit;
								continue;
							}

							else{

								j++;
							}
						}
					}	
			}

			else if (repeat==1){//true

				for (i = 0; i < size; ++i){

					password[i] = rand () % limit;
				}
			}
}

void gameModeMP(){

			printf("\n\n\n\n\n\n\n\n\n\n\n[TUTORIAL] Modo Multiplayer\n");
			printf("\n\t>Bem-vindo ao jogo senha!\n\n");
			printf(">Ola jogador, nesse modo voce deve escolher os parametros para seu jogo\n");
			printf(" de modo customizado, ou seja, voce deve escolher:\n\n");
			printf("\t1o O tamanho da senha de 2 a 10 digitos\n");
			printf("\t2o A senha para seu amigo tentar acertar, com valores entre 0 e 9\n\n");
			printf(">Durante o jogo e suas respectivas tentativas voce recebera dois tipos de dicas:\n");
			printf("\t(1 coluna) digito certo na posicao correta da combinacao de digitos\n");
			printf("\t(2 coluna) digito certo em uma posicao errada na combinacao de digitos\n\n");
			printf(">O jogo continuara recebendo novas tentativas de senha ate que voce acerte\n");
			printf("a senha secreta, ou ate que voce desista, para isso basta digitar um numero\n");
			printf("negativo em uma das posicoes de sua tentativa.\n\n");
			printf(">Boa sorte :)\n\n");

			sleep(5);

			int size;
			printf(">Escolha O tamanho da senha, entre 2 e 10 digitos:\n");
			scanf("%d", &size);

			if (size < 2 || size > 10){

				while(size < 2 || size > 10){

					printf("\n>Escolha O tamanho da senha:\n");
					scanf("%d", &size);
				}
			}

			int password[size], attempt[size];
			int attemptCount=1;
			int result;
			int tipTrue=0, tipFalse=0;
			int ok;
			int limit=10;

			int skip=0;

			getPassword(password, size);

			printf("\n>Digite uma nova tentativa de %d digitos entre 0 e %d seguindo as dicas,\n\t ateh acertar:\n\n", size, (limit-1));
			printf("\tN\tSenha\tDica\n");

			while(1){

					getAttempt(attempt, size);

					ok=attemptOK(attempt, size, limit);

					if (ok==0){
						
						continue;
					}

					skipProgram(attempt, size); 

					if (skip==1){

							exit(0);
					}

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse); 

					printAttempt(attemptCount, size, attempt, tipTrue, tipFalse);

					attemptCount++;

					if (result==1){

							printf("\n\n>Parabens voce acertou!\n");
							exit(0);
					}

					else if (result==0){

							continue;
					}
			}

}

void gameModeCT(){

			printf("\n\n\n\n\n\n\n\n\n\n\n[TUTORIAL] Contra o tempo!\n");
			printf("\n\t>Bem-vindo ao jogo senha!\n\n");
			printf(">Ola jogador, nesse modo voce deve escolher os parametros para seu jogo\n");
			printf(" de modo customizado, ou seja, voce deve escolher:\n\n");
			printf("\t1o O tamanho da senha de 2 a 10 digitos\n");
			printf("\t2o O conjunto de naturais entre 0 e 9 permitidos na composicao da senha\n");
			printf("\t3o O numero limite de tentativas para acertar a senha\n\n");
			printf(">Durante o jogo e suas respectivas tentativas voce recebera dois tipos de dicas:\n");
			printf("\t(1 coluna) digito certo na posicao correta da combinacao de digitos\n");
			printf("\t(2 coluna) digito certo em uma posicao errada na combinacao de digitos\n\n");
			printf(">O jogo continuara recebendo novas tentativas de senha ate que voce acerte\n");
			printf("a senha secreta, ou ate que voce desista, para isso basta digitar um numero\n");
			printf("negativo em uma das posicoes de sua tentativa.\n\n");
			printf(">Boa sorte :)\n\n");

			sleep(5);

			int size;
			printf(">Escolha O tamanho da senha:\n");
			scanf("%d", &size);

			if (size < 2 || size > 10){

				while(size < 2 || size > 10){

					printf("\n>Escolha O tamanho da senha:\n");
					scanf("%d", &size);
				}
			}

			int limit;
			printf("\n>Escolha o limite dos numeros, de 0 a x, {x E N | 1 < x < 10}\n");
			scanf("%d", &limit);

			if (limit<2 || limit>9){
				
				while(limit <2 || limit >9){

					printf("\n>Escolha o limite dos numeros, de 0 a x, {x E N | 1 < x < 10}\n");
					scanf("%d", &limit);
				}
			}

			limit+=1;

			int limitAtt;
			int choose;
			printf("\n>Digite (1) para escolher o numero de tentativas ou (2) para um numero aleatorio de 10 a 30\n");
			scanf("%d", &choose);

			if (choose==1){

					scanf("%d", &limitAtt);
			}

			else if(choose==2){

					limitAtt = rand () % 31;

					if (limitAtt<10){

							while(limitAtt<10){

								limitAtt = rand () % 31;
							}	
					}
			}


			int password[size], attempt[size];
			int result;
			int tipTrue=0, tipFalse=0;

			int repeat=1;
			int skip=0;
			int ok;

			passwordGenerator(password, limit, size, repeat);

					/*printf("\n>SENHA GERADA:\t");

					for (i = 0; i < size; ++i){

						printf("%d", password[i]);	
					}*/

			printf("\n>Digite uma nova tentativa de %d digitos entre 0 e %d seguindo as dicas,\n\t  ateh acertar:\n\n", size, (limit-1));
			printf("\tN\tSenha\tDica\n");

			while(1){

					getAttempt(attempt, size);

					ok=attemptOK(attempt, size, limit);

					if (ok==0){
						
						continue;
					}

					skipProgram(attempt, size); 

					if (skip==1){

							exit(0);
					}

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse); 

					printAttempt(limitAtt, size, attempt, tipTrue, tipFalse);

					limitAtt--;

					if (result==1){

							printf("Parabens voce acertou!\n");
							exit(0);
					}

					if (limitAtt>0){

							continue;
					}

					else if (limitAtt<=0){

							printf("As tentativas esgotaram\n\n");
							printf("Voce perdeu!\n");
							exit(0);
					}
			}

}


void gameMode4FUN(){

			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t[EASTER EGG] MODO DE JOGO 4fun\n\n\n\n\n\n\n");
			sleep(4);
			printf(":) boa sorte\n\n\n\n");
			sleep(2.5);

			int interaction;
			int aux;
			char name[20];

			printf(">Era uma bela noite no centro de treinamento de soldados IT da UFMG\n\n");
			sleep(3);
			printf(">Voce e apenas um recruta que acaba de inciar sua carreira\n\n");
			sleep(1.5);
			printf(">Escolha seu nome:\n\n");

			fflush(stdin);
			fgets(name, 20, stdin);

			printf("\n\n");

			sleep(1.5);
			printf(">O alarme dispara!!!\n\n");
			sleep(1.5);
			printf(">Explosoes comecam a ocorrer!!!\n\n");
			sleep(1.5);
			printf(">Voce ouve o telefone tocando e observa que esta sozinho\n\n");
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n");

			while(1){

				int count=0;

				printf(">telefone tocando\n\n");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".\n\n");

				printf("\n");

				printf(">Digite 0 para atender:\n\n");
				fflush(stdin);
				scanf("%d", &interaction);
				count++;

				if (count>5){

						printf(">ATENDE LOGO!!!\n\n");
				}

				if (interaction==0){


					break;
				}
			}

			sleep(0.5);
			printf("\n>>> Coronel Clodoveu:\n");
			sleep(1.5);
			printf("\tBoa noite Recruta, %s", name);
			sleep(2.5);
			printf("\tuma bomba foi plantada no seu RSG\n\n");
			sleep(0.5);
			printf("!");
			sleep(0.5);
			printf("!");
			sleep(0.5);
			printf("!\n\n\n");
			printf(">infelizmente estamos sem apoio do esquadrao de monitores antibombas!\n\n");
			sleep(1.5);
			printf(">Apenas voce pode se salvar dessa situac");
			sleep(2.5);
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n\n");
			sleep(1.5);
			printf("<CHIADO NA LIGACAO>\n\n\n");
					printf(">nao\t");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf("sabemos ");
					sleep(0.5);
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".quem est");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(". ");
					sleep(1.5);
					printf("por tras");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					sleep(1.5);
					printf("desse atentad");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".\n\n");
					sleep(0.5);
					sleep(1.5);
					printf(">confiamos");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(". ");
					sleep(0.5);
					printf("no seu potencial");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".\n\n\n");
					sleep(0.5);
		printf("<LIGACAO CAI>\n\n");

			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n");
			sleep(2.5);

			printf("<UMA VOZ DIFERENTE SURGE NA LINHA>\n\n");
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n");
			sleep(1.5);
			printf(">>> Dr. Calculus:\n\n");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n");
			sleep(1.5);
			printf(">Ola recruta %s\n", name);
			sleep(1.5);
			printf("\ta quanto tempo nao e mesmo?\n\n");
			sleep(4);
			printf(">Assim como no seu historico, plantei uma bomba no seu proximo RSG\n\n");
			sleep(4);
			printf(">MAUHAUAHAAHHAHAHAHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHAHAHA\n\n");
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n");
			sleep(0.5);
			printf(">Sei que voce claramente ira falhar na missao dada pelo seu coronel\n\n");
			sleep(2.5);
			printf(">Entao vou te dar algumas variaveis:\n\n");
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n\n");
			sleep(0.5);

					printf(">Escolha o tamanho da senha (3 a 10):\n\n");

					int size;
					fflush(stdin);
					scanf("%d", &size);

					if (size<3 || size>10){
						
							while(size<3 || size>10){

								printf(">E POR ISSO QUE REPROVA! FAZ OS LIMITES TODOS ERRADOS...\n");
								fflush(stdin);
								scanf("%d", &size);
							}
					}


					printf("\n>Valores de 0 a... (escolha um numero limite entre 1 e 9)\n");

					int limit;
					fflush(stdin);
					scanf("%d", &limit);

					if (limit>9 || limit<=0){
						
							while(limit>9 || limit<=0){

								printf(">ERRANDO LIMITE DENOVO ??? TENTE OUTRA VEZ\n");
								fflush(stdin);
								scanf("%d", &limit);
							}
					}

			limit+=1;

			printf("\n\n");

			printf(">MAUAHAUHAHUAHUAHAHAHAHAHHAHAHA\n\n");
			sleep(2.5);
			printf("\n>ainda assim nao sera tao facil, boa sorte!!!\n\n");
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n\n");
			sleep(2.5);
			printf(">ADVINHE A SENHA NOS PADROES ESTABELECIDOS ACIMA:\n\n");
			sleep(4);
			printf("\n\n");	

			fflush(stdin);

			int limitAtt;

			limitAtt = rand() % 31;

						if (limitAtt<10){

							while (limitAtt<5){
								limitAtt = rand() % 21;
							}
						}

			printf(">ESPERE!!!!\n\n");
			sleep(1.5);
			printf(">>> Dr. Calculus:\n\n");
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n");
			sleep(0.5);
			printf("Ja ia me esquecendo\n\n");
			printf(".");
			sleep(0.5);
			printf(".");
			sleep(0.5);
			printf(".\n\n");
			sleep(1.5);
			printf("VOCE TEM APENAS %d RODADAS PARA DESARMAR A BOMBA!!!\n\n", limitAtt);
			printf("!");
			sleep(0.5);
			printf("!");
			sleep(0.5);
			printf("!\n\n");
			sleep(2.5);

			int password[size], attempt[size];
			int attemptCount=1;
			int result;
			int tipTrue=0, tipFalse=0;
			int f;
			int i=0;
			int ok;
	
			int repeat=1;
			int skip=0;

			passwordGenerator(password, limit, size, repeat);

					//printf("\n>SENHA GERADA:\t");

					//for (i = 0; i < size; ++i){

					//	printf("%d", password[i]);	
					//}

					printf("\n\n\n");

			printf("\n>Digite uma nova tentativa de %d digitos entre 0 e %d seguindo as dicas,\n\t  para desarmar a bomba:\n\n", size, (limit-1));
			printf("\tN\tSenha\tDica\n");

			fflush(stdin);

			while(1){

					getAttempt(attempt, size);

					ok=attemptOK(attempt, size, limit);

					if (ok==0){
						
						continue;
					}

					skipProgramv(attempt, size); 

					if (skip==1){

							exit(0);
					}

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse); 

					printAttempt(limitAtt, size, attempt, tipTrue, tipFalse);

					limitAtt--;

					if (result==1){

							printf("\n\n>PARABENS VOCE ACERTOU E DESARMOU A BOMBA");
							sleep(2.5);
							printf("!");
							sleep(0.5);
							printf("!");
							sleep(0.5);
							printf("!\n\n");
							printf(">FOI APROVADO");
							sleep(1.5);
							printf("!");
							sleep(0.5);
							printf("!");
							sleep(0.5);
							printf("!\n\n");
							printf(">E DARA UM PONTO EXTRA PARA QUEM FEZ ESSE CODIGO ENORME KKKKK");
							sleep(4);
							printf("!");
							sleep(0.5);
							printf("!");
							sleep(0.5);
							printf("!\n\n\n");	
							sleep(2.5);
							printf("\t:D Tchau!\n");
							sleep(2.5);
							printf("\n\n\n>Creditos\n");
							printf("\n\t>Diretor: Matheus Aquino\n");
							sleep(2.5);
							printf("\n\t>Producao executiva: Matheus Aquino\n");
							sleep(2.5);
							printf("\n\t>Roteiro: Matheus Aquino\n");
							sleep(2.5);
							printf("\n\t>Direcao de imagem: Matheus Aquino\n");
							sleep(2.5);
							printf("\n\t>Direcao de som: Nao tem som\n");
							sleep(2.5);
							printf("\n\t[Aquinotvision Games]\n");
							sleep(5);
							printf("\n\n\n\n\n\n\n");
							printf("\t.");
							sleep(0.5);
							printf("\t.");
							sleep(0.5);
							printf("\t.\n\n");
							sleep(1.5);
							printf(">>> Dr. Calculus\n");
							printf(".");
							sleep(0.5);
							printf(".");
							sleep(0.5);
							printf(".\n\n");
							sleep(1.5);
							printf(">MUAHAHAHAAHAHAHAHAHAHA\n");
							sleep(5);
							printf("\n\n\n\t>Dr. Calculus retornara.\n");
							printf("\n\n\n");
							fflush(stdin);

							exit(0);
					}

					if (limitAtt>0){

							continue;
					}

					else if (limitAtt<=0){

						printf("\n\n>>> Dr. Calculus:\n\n");
						sleep(1.5);
						printf("!");
						sleep(0.5);
						printf("!");
						sleep(0.5);
						printf("!\n\n");
						printf(">VOCE FALHOU !!! CONCEITO F !!!\n\n");
						sleep(1.5);
						printf(">A BOMBA IRA EXPLODIR\n\n");
						sleep(2.5);
						printf("!");
						sleep(0.5);
						printf("!");
						sleep(0.5);
						printf("!\n\n");
						printf("CABUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUM\n\n");
						sleep(6);
						printf(">MAS O QUE ????\n\n");

						sleep(0.5);
						printf(".");
						sleep(0.5);
						printf(".");
						sleep(0.5);
						printf(".\n\n");

						printf(">O recruta %s sobreviveu a explosao e passara com 60 em Calculus\n\n", name);
						sleep(2.5);
						printf(">E DARA UM PONTO EXTRA POR ESSE CODIGO ENORME KKKKK\n\n\n");
						sleep(2.5);
						printf("\t:D tchau!\n\n");
						sleep(2.5);

						fflush(stdin);

						exit(0);
					}
			}

}

void gameModeQSS(){

			printf("\n\n\n\n\n\n\n\n\n\n\n[TUTORIAL] Qual e a sua senha?\n");
			//printf("\n\t>Bem-vindo ao jogo senha!\n\n");
			printf(">Ola jogador, nesse modo voce deve escolher os parametros para seu jogo\n");
			printf(" de modo customizado, ou seja, voce deve escolher:\n\n");
			printf("\t1o O tamanho da senha de 2 a 10 digitos\n");
			printf("\t2o O conjunto de naturais entre 0 e 9 permitidos na composicao da senha\n");
			printf("\t3o Se serao permitidos elementos repetidos ou nao\n\n");
			printf("> lembre-se, se repeticoes nao forem permitidas, o tamanho da senha deve\n");
			printf("  ser menor ou igual a quantidade de elementos permitidos no conjunto N.\n\n");
			printf(">Durante o jogo e suas respectivas tentativas voce recebera dois tipos de dicas:\n");
			printf("\t(1 coluna) digito certo na posicao correta da combinacao de digitos\n");
			printf("\t(2 coluna) digito certo em uma posicao errada na combinacao de digitos\n\n");
			printf(">O jogo continuara recebendo novas tentativas de senha ate que voce acerte\n");
			printf("a senha secreta, ou ate que voce desista, para isso basta digitar um numero\n");
			printf("negativo em uma das posicoes de sua tentativa.\n\n");
			printf(">Boa sorte :)\n\n");

			sleep(5);

			int size;
			printf(">Escolha O tamanho da senha:\n");
			scanf("%d", &size);

			if (size < 2 || size > 10){

				while(size < 2 || size > 10){

					printf("\n>Escolha O tamanho da senha:\n");
					scanf("%d", &size);
				}
			}

			int limit;
			printf("\n>Escolha o limite dos numeros, de 0 a x, {x E N | 1 < x < 10}\n");
			scanf("%d", &limit);

			if (limit<2 || limit>9){
				
				while(limit <2 || limit >9){

					printf("\n>Escolha o limite dos numeros, de 0 a x, {x E N | 1 < x < 10}\n");
					scanf("%d", &limit);
				}
			}

			limit+=1;

			int repeat;
			printf("\n>Repeticoes de numeros sao permitidas ou nao\n\t1) sim\n\t0) nao\n");
			scanf("%d", &repeat);


			if ((limit) < size && repeat == 0){

				printf("REPETICOES NAO PERMITIDAS:\n\ttamanho precisa ser <= ao limite da cardinalidade do conjunto de elementos em uso\n");

					while((limit) < size && repeat == 0){

							int size;
							printf(">Escolha O tamanho da senha:\n\n");
							scanf("%d", &size);

							int limit;
							printf(">Escolha o limite dos numeros, de 0 a x, {x E N | 2 < x < 10}\n\n");
							scanf("%d", &limit);
					}
			}

			int password[size], attempt[size];
			int result;
			int tipTrue=0, tipFalse=0;
			int attemptCount=0;
			int ok;

			int skip=0;

			passwordGenerator(password, limit, size, repeat);

			printf("\n>Digite uma nova tentativa de %d digitos entre 0 e %d seguindo as dicas,\n\t  ateh acertar:\n\n", size, (limit-1));
			printf("\tN\tSenha\tDica\n");

			while(1){

					getAttempt(attempt, size);

					ok=attemptOK(attempt, size, limit);

					if (ok==0){
						
						continue;
					}

					skipProgram(attempt, size); 

					if (skip==1){

							exit(0);
					}

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse); 

					printAttempt(attemptCount, size, attempt, tipTrue, tipFalse);

					attemptCount++;

					if (result==1){

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

					else if (result==0){

							continue;
					}
			}

}


void gameModeAS(){
			printf("\n\n\n\n\n\n\n\n\n\n\n[TUTORIAL] COMPUTADOR Vs Senha\n");
			printf("\n\t>Bem-vindo ao jogo senha!\n\n");
			printf(">Ola jogador, nesse modo voce deve escolher os parametros para seu jogo\n");
			printf(" de modo customizado, ou seja, voce deve escolher:\n\n");
			printf("\t1o O tamanho da senha de 2 a 10 digitos\n");
			printf("\t2o O conjunto de naturais entre 0 e 9 permitidos na composicao da senha\n");
			printf("\t3o A a senha para seu adversario acertar\n\n");
			printf(">Nesse modo o computador sera seu adversario e tentara acertar a senha aleatoriamente\n\n");
			printf("> Divirta-se :D\n\n");


			sleep(5);

			int size;
			printf(">Escolha O tamanho da senha:\n");
			scanf("%d", &size);

			if (size < 2 || size > 10){

				while(size < 2 || size > 10){

					printf("\n>Escolha O tamanho da senha:\n");
					scanf("%d", &size);
				}
			}

			int limit;
			printf("\n>Escolha o limite dos numeros, de 0 a x, {x E N | 1 < x < 10}\n");
			scanf("%d", &limit);

			if (limit<2 || limit>9){
				
				while(limit <2 || limit >9){

					printf("\n>Escolha o limite dos numeros, de 0 a x, {x E N | 1 < x < 10}\n");
					scanf("%d", &limit);
				}
			}

			limit+=1;

			int password[size], attempt[size];
			int attemptCount=1;
			int result;
			int tipTrue=0, tipFalse=0;
			int ok;
			int i=0;

			printf("\n\n>LEMBRE-SE OS DIGITOS DA SUA SENHA DEVEM ESTAR ENTRE 0 E %d\n\n", (limit-1));

			getPassword(password, size);

			printf("\n>Digite uma nova tentativa de %d digitos entre 0 e %d seguindo as dicas,\n\t  ateh acertar:\n\n", size, (limit-1));

			printf("\tN\tSenha\tDica\n");

			while(1){

					for (i = 0; i < size; ++i){
						
							attempt[i]= rand() % limit;
					}

					result = checkPassword(password, attempt, size, &tipTrue, &tipFalse); 

					printAttempt(attemptCount, size, attempt, tipTrue, tipFalse);

					attemptCount++;

					if (result==1){

							int game;
							printf("\n\nO computador acertou em %d rodadas!\n", attemptCount);
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

					else if (result==0){

							continue;
					}
			}

}


int checkPassword(int *passwordT, int *passwordA, int size, int *countTrue, int *countFalse){

			int controlUp[size], UnderControl[size];
			int i=0, j=0, k=0, aux=0;

			*countTrue=0;
			*countFalse=0;

			for (i = 0; i < size; ++i){

					UnderControl[i]=controlUp[i]=0;
			}

			for (i = 0; i < size; ++i){

					if (passwordT[i]==passwordA[i]){

							UnderControl[i]=1;
							controlUp[i]=1;
							(*countTrue)++;
					}
			}

			for (i = 0; i < size; ++i){

					for (j = 0; j < size; ++j){

							if (passwordA[j]==passwordT[i] && UnderControl[j]!=1 && controlUp[i]!=1){

									(*countFalse)++;
									UnderControl[j]=1;
									controlUp[i]=1;
									continue;
							}
					}
			}

			if ((*countTrue)==size){

					return 1;
			}

			else if ((*countTrue) < size){

					return 0;
			}
}


void getAttempt(int *attempt, int size){

			int i=0, pass=0;

			scanf("%d", &pass);

			for(i = size-1; i >= 0; i--){          
							
				attempt[i]=(pass%10);
				pass /= 10;
			}
}


void getPassword(int *password, int size){

			printf("\n>Digite a senha de %d digitos para seu adversario tentar acertar:\n\n", size);

			int i=0, pass=0;

			scanf("%d", &pass);

			for(i = size-1; i >= 0; i--){          
							
				password[i]=(pass%10);
				pass /= 10;
			}
}


void skipProgram(int *password, int size){ 

			int i=0;

			for (i = 0; i < size; i++){

				if (password[i]<0){
					
					printf("\n\n>Voce desistiu :(\n");
					exit(0);
				}
			}
}

void printAttempt(int attemptCount, int size, int *attempt, int tipTrue, int tipFalse){

			int i=0;

			printf("\t%d\t", attemptCount); 

			for (i = 0; i < size; i++){
								
				printf("%d", attempt[i]);
			}

			printf("\t%d %d\n", tipTrue, tipFalse);
}

int attemptLimit(int attemptCount, int limitAtt){

			if (attemptCount>limitAtt){
				
				return 1;
			}

			else if (attemptCount<=limitAtt){

				return 0;
			}
}

void skipProgramv(int *password, int size){ 

			int i=0;

			for (i = 0; i < size; i++){

				if (password[i]<0){
					
					printf(">VOCE DESISTIU ?\n\n");
					sleep(2.5);
					printf(">VOCE NUNCA PASSARA DESSA MATERIA\n\n");
					printf("!");
					sleep(0.5);
					printf("!");
					sleep(0.5);
					printf("!\n\n");
					sleep(2.5);
					printf(">VOCE VAI FAZER INTEGRAIS PARA SEMPRE\n\n");
					printf("!");
					sleep(0.5);
					printf("!");
					sleep(0.5);
					printf("!\n\n");
					sleep(2.5);
					printf(">MUAHAHAHAHAHAHAAHAHAHHAHAHAHAHAHAHAHA\n\n");
					printf(".");
					sleep(0.5);
					printf(".");
					sleep(0.5);
					printf(".\n\n");
					sleep(2.5);

					fflush(stdin);

					exit(0);
				}
			}
}

int attemptOK(int *attempt, int size, int limit){

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

