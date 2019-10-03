#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"
#include <unistd.h> 

int rolaDados()
{
	int result=0;
	int dice=0;
	int i=0;

	while(i<3){

		dice = rand() % 7;

		if (dice==0){

			continue;
		}

		else{
			i++;
			result+=dice;
		}
	}

	return result;
}

void criaGuerreiro(warrior *P, int *player)
{
	P->atack = rolaDados();
	P->defense = rolaDados();
	P->glory = rolaDados();
	P->health_points = rolaDados()+rolaDados()+rolaDados();
	P->player_id = *player;

	(*player)+=1;
}

void statusPlayer(warrior *P)
{
	printf("\t>Jogador: %d\n", P->player_id);
	printf("\t-Ataque: %d\n", P->atack);
	printf("\t-Defesa:	%d\n", P->defense);
	printf("\t-Carisma: %d\n", P->glory);
	printf("\t-Pontos de vida: %d\n\n", P->health_points);
}

int gloryBonus(warrior *P)
{
	if (P->glory == 18)
	{
		printf("\n>O guerreiro %d eh extremamente carismatico e tem todo o apoio da torcida, recebendo um bonus de +3 no combate.\n", P->player_id);

		return 3;
	}

	else if (P->glory == 16 || P->glory == 17)
	{
		printf("\n>O guerreiro %d eh muito carismatico e tem o apoio de quase toda a torcida, recebendo um bonus de +2 no combate.\n", P->player_id);

		return 2;
	}

	else if (P->glory == 14 || P->glory == 15)
	{
		printf("\n>O guerreiro %d eh carismatico e tem o apoio de alguns teorcedores, recebendo um bonus de +1 no combate.\n", P->player_id);

		return 1;
	}

	else if (P->glory == 6 || P->glory == 7)
	{
		printf("\n>O guerreiro %d eh antipatico, e tem alguma torcida contra ele, recebendo uma penalidade de -1 no combate.\n", P->player_id);

		return -1;
	}

	else if (P->glory == 4 || P->glory == 5)
	{
		printf("\n>O guerreiro %d eh muito antipatico, e tem quase toda a torcida contra ele, recebendo uma penalidade de -2 no combate.\n", P->player_id);

		return -2;
	}

	else if (P->glory == 3)
	{
		printf("\n>O guerreiro %d eh extremamente antipatico, e tem toda a torcida contra ele, recebendo uma penalidade de -3 no combate.\n", P->player_id);

		return -3;
	}

	else
	printf("\n>O guerreiro %d eh sem graca...\n", P-> player_id);
}

void combat(warrior *P1, warrior *P2)
{
		printf("\n>Os dois guerreiros entram na arena, a torcida vai a LOUCURA!!!!!!\n");

		int turn, i=0, x=0, Bglory1, Bglory2, countTurn=1;
		int atk, shield, damage;

		Bglory1 = gloryBonus(P1);
		Bglory2 = gloryBonus(P2);

		sleep(2);

		turn = rand() % 2;

		while(P1->health_points > 0 && P2->health_points > 0){

			printf("\n\n\t**%d TURNO HP(%d/%d)**\t\n\n", countTurn, P1->health_points, P2->health_points);

			if (turn==0){

					atk=rolaDados()+(P1->atack)+Bglory1;

					if (countTurn>20){
						
						printf("\n\t**A LUTA ESTAH MUITO EMOCIONANTE, OS GUERREIROS ENTRAM EM FURIA (2x ATK)**\n");
						atk*=1.2;
					}

					shield=rolaDados()+(P2->defense)+Bglory2;
					damage=atk-shield;

					battleStatus(atk, shield, turn);

					if(damage>0){
						sleep(2);
						printf("\n>O guerreiro 2 perdeu %d ponto(s) de vida!!!\n", damage);
						P2->health_points-=damage;
					}

					else if(damage<=0){
						sleep(2);
						printf("\n>O guerreiro 2 defendeu o ataque!!!\n", damage);
					}

					turn=1;
				}

			else if (turn==1){
					
					atk=rolaDados()+(P2->atack)+Bglory2;

					if (countTurn>20){

						printf("\n\t**A LUTA ESTAH MUITO EMOCIONANTE, OS GUERREIROS ENTRAM EM FURIA (1.2x ATK)**\n");
						atk*=1.2;
					}

					shield=rolaDados()+(P1->defense)+Bglory1;
					damage=atk-shield;

					battleStatus(atk, shield, turn);

					if(damage>0){
						sleep(2);
						printf("\n>O guerreiro 1 perdeu %d ponto(s) de vida!!!\n", damage);
						P1->health_points-=damage;
					}

					else if (damage<=0){
						sleep(2);
						printf("\n>O guerreiro 1 defendeu o ataque!!!\n");
					}

					turn=0;
				}

			countTurn++;

			sleep(2);
		}

		printf("\n\t**A BATALHA TERMINOU**\n\n");
		sleep(5);

		if (P1->health_points > P2->health_points){
			
			printf("\n\t***O GUERREIRO 1 VENCEU!!!***\n");
		}

		else if (P2->health_points > P1->health_points){
			
			printf("\n\t***O GUERREIRO 2 VENCEU!!!***\n");
		}
}

void intro(){
		printf("\n\n\n\n\t**BEM-VINDO A ARENA TERMINAL**\n\n");
		sleep(2);
		printf(">Um lugar temido por muitos...\n\n");
		sleep(1);
		printf(">Dois guerreiros entram...\t");
		sleep(2);
		printf("APENAS UM SAI...\n");
		sleep(3);

		printf("\n\n\t**CRIANDO GUERREIROS**\n\n");
		sleep(3);
}

void battleStatus(int atk, int def, int turn){

		if (turn==0){

			printf("\n>O Guerreiro 1 desferiu um ataque com um poder de %d ponto(s)!!!\n", atk);
			sleep(2);
			printf("\n>O Guerreiro 2 se defendeu com um escudo de %d ponto(s)!!!\n", def);
		}

		else if (turn==1){

			printf("\n>O Guerreiro 2 desferiu um ataque com um poder de %d ponto(s)!!!\n", atk);
			sleep(2);
			printf("\n>O Guerreiro 1 se defendeu com um escudo de %d ponto(s)!!!\n", def);
		}
}