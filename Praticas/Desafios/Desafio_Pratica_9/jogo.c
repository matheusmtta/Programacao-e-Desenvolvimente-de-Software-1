#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"
#include <string.h>
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

void criaGuerreiros(warrior *P, int size){
	for (int i = 0; i < size; ++i){
		P[i].position = 1;
		P[i].atack = rolaDados();
		P[i].defense = rolaDados();
		P[i].glory = rolaDados();
		P[i].health_points = rolaDados()+rolaDados()+rolaDados();
		P[i].player_id = i;
		P[i].score = 0;
	}

}

void statusPlayer(warrior *P, int size)
{
	for (int i = 0; i < size; ++i){
		printf("\n\t>[%d] NOME: %s\n", P[i].player_id, P[i].name);
		printf("\t-Ataque: %d\n", P[i].atack);
		printf("\t-Defesa:	%d\n", P[i].defense);
		printf("\t-Carisma: %d\n", P[i].glory);
		printf("\t-Pontos de vida: %d\n\n", P[i].health_points);
		
		getchar();
	}
}

int fastGloryBonus(warrior *P)
{
	if (P->glory == 18){
		return 3;
	}

	else if (P->glory == 16 || P->glory == 17){
		return 2;
	}

	else if (P->glory == 14 || P->glory == 15){
		return 1;
	}

	else if (P->glory == 6 || P->glory == 7){
		return -1;
	}

	else if (P->glory == 4 || P->glory == 5){
		return -2;
	}

	else if (P->glory == 3){
		return -3;
	}
}

void fastCombat(warrior *P1, warrior *P2)
{
		printf("\n\t[%s x %s]\t", P1->name, P2->name);

		int turn, i=0, x=0, Bglory1, Bglory2, countTurn=1;
		int atk, shield, damage;
		int hp1=0, hp2=0;

		Bglory1 = fastGloryBonus(P1);
		Bglory2 = fastGloryBonus(P2);
		hp1=P1->health_points;
		hp2=P2->health_points;

		turn = rand() % 2;

		while(hp1 > 0 && hp2 > 0){

			if (turn==0){

					atk=rolaDados()+(P1->atack)+Bglory1;

					if (countTurn>20){
						
						atk*=2.0;
					}

					shield=rolaDados()+(P2->defense)+Bglory2;
					damage=atk-shield;

					if(damage>0){
						hp2-=damage;
					}

					turn=1;
				}

			else if (turn==1){
					
					atk=rolaDados()+(P2->atack)+Bglory2;

					if (countTurn>20){

						atk*=2.0;
					}

					shield=rolaDados()+(P1->defense)+Bglory1;
					damage=atk-shield;

					if(damage>0){
						hp1-=damage;
					}

					turn=0;
				}

			countTurn++;
		}

		if (hp1 > hp2){
			
			printf("\t%s venceu, +1 ponto", P1->name);
			P1->score+=1;
			P1->turnScore+=countTurn;
		}

		else if (hp2 > hp1){
			
			printf("\t%s venceu, +1 ponto", P2-> name);
			P2->score+=1;
			P2->turnScore+=countTurn;
		}
}

void intro(){
		printf("\n\n\n\n\t\t\t**BEM-VINDO A ARENA TERMINAL**\n\n");
		
		getchar();
		printf("\t\t>Um lugar temido por muitos...\n\n");
		
		getchar();
		printf("\t\t>Dezesseis guerreiros entram...\t");
		
		getchar();
		printf("\n\n\t\tAPENAS UM SAI...\n");
		
		getchar();

		printf("\n\n\t\t**CRIANDO GUERREIROS**\n\n");
		
		getchar();
}

void battleStatus(int atk, int def, int turn, warrior *P1, warrior *P2){

		if (turn==0){

			printf("\n>%s desferiu um ataque com um poder de %d ponto(s)!!!\n", P1->name, atk);
			printf("\n>%s se defendeu com um escudo de %d ponto(s)!!!\n", P2->name, def);
		}

		else if (turn==1){

			printf("\n>%s desferiu um ataque com um poder de %d ponto(s)!!!\n", P2->name, atk);
			printf("\n>%s se defendeu com um escudo de %d ponto(s)!!!\n", P1->name, def);
		}
}

void resetArray(int *array, int size){

					int i=0;

					for (i = 0; i < size; ++i){
						array[i]=0;
					}
}

void CgroupPhase(warrior *warriors, int size, int *array16, warrior *nextPhase){

					int i=0;
					int position;
					warrior group1[4], group2[4], group3[4], group4[4];
					int listW[16];

					resetArray(listW, 16);

					while (i < 4){	//GROUP 1

							position=rand() % 16;

							if (array16[position]!=1){  
										
									array16[position]=1;
									group1[i]=warriors[position];
									i++;
							}

							else continue;
					}

					i=0;

					while (i < 4){	//GROUP 2

							position=rand() % 16;

							if (array16[position]!=1){  

									array16[position]=1;
									group2[i]=warriors[position];
									i++;
							}

							else continue;
					}

					i=0;

					while (i < 4){    //GROUP 3

							position=rand() % 16;

							if (array16[position]!=1){

									array16[position]=1;
									group3[i]=warriors[position];
									i++;
							}

							else continue;
					}

					i=0;

					while (i < 4){	//GROUP 4

							position=rand() % 16;

							if (array16[position]!=1){

									array16[position]=1;
									group4[i]=warriors[position];
									i++;
							}

							else continue;
					}


					printf(">CRIANDO FASE DE GRUPOS...\n");
					
					getchar();
					printGroups(group1, 1);
					getchar();
					printGroups(group2, 2);
					getchar();
					printGroups(group3, 3);
					getchar();
					printGroups(group4, 4);

					getchar();
					printf("\n______________________________________________________________________________\n");
					printf("\n\n\t\t[GRUPO 1]\n");
					GroupCombat(group1, nextPhase, 1);
					nextPhase[0]=group1[0];

					getchar();
					printf("\n______________________________________________________________________________\n");
					printf("\n\n\t\t[GRUPO 2]\n");
					GroupCombat(group2, nextPhase, 2);
					nextPhase[1]=group2[0];

					getchar();
					printf("\n______________________________________________________________________________\n");
					printf("\n\n\t\t[GRUPO 3]\n");
					GroupCombat(group3, nextPhase, 3);
					nextPhase[2]=group3[0];

					getchar();
					printf("\n______________________________________________________________________________\n");
					printf("\n\n\t\t[GRUPO 4]\n");
					GroupCombat(group4, nextPhase, 4);
					nextPhase[3]=group4[0];
					printf("\n______________________________________________________________________________\n");
					getchar();
}

void printGroups(warrior *group, int groupNumber){

					sortGroup(group);

					int i=0;

					printf("\n\n\n\t   [GRUPO %d]    PONTOS\n", groupNumber);

					for (i = 0; i < 4; ++i){
					
							printf("\t[%d]  %s\t%d\n", i+1, group[i].name, group[i].score);

					}
}



void GroupCombat(warrior *group, warrior *nextPhase, int groupNumber){

					int i=0, j=3;
					warrior *P1, *P2;

					for (i=0; i < 4; i++){
						for (j = 3; j > i; j--){

							P1 = &group[i];
							P2 = &group[j];

							fastCombat(P1, P2);
							
							getchar();
						}
					}

					sortGroup(group);

					printGroups(group, groupNumber);		
}



void finalCombats(warrior *SM)
{
		warrior *P1, *P2;

		P1 = &SM[0];
		P2 = &SM[1];

		printf("\n>Os guerreiros %s e %s entram na arena, a torcida vai a LOUCURA!!!!!!\n", P1->name, P2->name);
		getchar();

		int turn, i=0, x=0, Bglory1, Bglory2, countTurn=1;
		int atk, shield, damage;
		int hp1=0, hp2=0;

		Bglory1 = gloryBonus(P1);
		getchar();
		Bglory2 = gloryBonus(P2);
		hp1=P1->health_points;
		hp2=P2->health_points;
		int again=0;

		getchar();

		turn = rand() % 2;

		while(hp1 > 0 && hp2 > 0){

			printf("\n\n\t**%d TURNO HP(%d/%d)**\t\n\n", countTurn, hp1, hp2);

			if (turn==0){

					atk=rolaDados()+(P1->atack)+Bglory1;

					if (countTurn>10 && again==0){
						
						again=1;
						printf("\n**A LUTA ESTAH MUITO EMOCIONANTE, OS GUERREIROS ENTRAM EM FURIA (2.5x ATK)**\n");
						atk*=1.5;
					}

					shield=rolaDados()+(P2->defense)+Bglory2;
					damage=atk-shield;

					battleStatus(atk, shield, turn, P1, P2);

					if(damage>0){
						printf("\n>%s perdeu %d ponto(s) de vida!!!\n", P2->name, damage);
						hp2-=damage;
					}

					else if(damage<=0){
						printf("\n>%s defendeu o ataque!!!\n", P2->name);
					}

					turn=1;
				}

			else if (turn==1){

					atk=rolaDados()+(P2->atack)+Bglory2;

					if (countTurn>10 && again==0){

						again=1;
						printf("\n**A LUTA ESTAH MUITO EMOCIONANTE, OS GUERREIROS ENTRAM EM FURIA (2.5x ATK)**\n");
						atk*=1.5;
					}

					shield=rolaDados()+(P1->defense)+Bglory1;
					damage=atk-shield;

					battleStatus(atk, shield, turn, P1, P2);

					if(damage>0){
						printf("\n>%s perdeu %d ponto(s) de vida!!!\n", P1->name, damage);
						hp1-=damage;
					}

					else if (damage<=0){
						printf("\n>%s defendeu o ataque!!!\n", P1->name);
					}

					turn=0;
				}

			countTurn++;

			getchar();
		}

		printf("\n\t**A BATALHA TERMINOU**\n\n");
		getchar();

		if (hp1 > hp2){
			
			printf("\n\t***%s VENCEU!!!***\n\n\n", P1->name);
			
			getchar();
		}

		else if (hp2 > hp1){
			
			printf("\n\t***%s VENCEU!!!***\n\n\n", P2->name);
			SM[0] = SM[1];
			getchar();
		}
}


int gloryBonus(warrior *P)
{
		if (P->glory == 18){
			printf("\n>%s eh extremamente carismatico(a) e tem todo o apoio da torcida, recebendo um bonus de +3 no combate.\n", P->name);
			return 3;
		}

		else if (P->glory == 16 || P->glory == 17){
			printf("\n>%s eh muito carismatico(a) e tem o apoio de quase toda a torcida, recebendo um bonus de +2 no combate.\n", P->name);
			return 2;
		}

		else if (P->glory == 14 || P->glory == 15){
			printf("\n>%s eh carismatico(a) e tem o apoio de alguns teorcedores, recebendo um bonus de +1 no combate.\n", P->name);
			return 1;
		}

		else if (P->glory == 6 || P->glory == 7){
			printf("\n>%s eh antipatico(a), e tem alguma torcida contra, recebendo uma penalidade de -1 no combate.\n", P->name);
			return -1;
		}

		else if (P->glory == 4 || P->glory == 5){
			printf("\n>%s eh muito antipatico(a), e tem quase toda a torcida contra, recebendo uma penalidade de -2 no combate.\n", P->name);
			return -2;
		}

		else if (P->glory == 3){
			printf("\n>%s eh extremamente antipatico(a), e tem toda a torcida contra, recebendo uma penalidade de -3 no combate.\n", P->name);
			return -3;
		}

		else{
			printf("\n>%s eh sem graca...\n", P->name);
			}
}


void sortGroup(warrior *group){

		warrior aux;
		int i=0;
		int j=0;

		for(i=0; i<4; i++){

			for(j=3; j > i; j--){

				if (group[i].score <= group[j].score){
					
					aux=group[i];
					group[i]=group[j];
					group[j]=aux;
				}

				else if (group[i].score == group[j].score){

					if (group[i].turnScore <= group[i].turnScore){

						aux=group[i];
						group[i]=group[j];
						group[j]=aux;
					}
				}
			}
		}
}

void CsemiPhase(warrior *semifinal, int size, int *flagControl4, warrior *finalBattle){


					int i=0;
					int position;
					warrior SM1[2], SM2[2];

					while (i < 2){	//GROUP 1

							position=rand() % 4;

							if (flagControl4[position]!=1){  
										
									flagControl4[position]=1;
									SM1[i]=semifinal[position];
									i++;
							}

							else continue;
					}

					i=0;

					while (i < 2){	//GROUP 2

							position=rand() % 4;

							if (flagControl4[position]!=1){  

									flagControl4[position]=1;
									SM2[i]=semifinal[position];
									i++;
							}

							else continue;
					}

					printf("\n\n\t> %s   X   %s <\n", SM1[0].name, SM1[1].name);
					finalCombats(SM1);
					finalBattle[0]=SM1[0];

					getchar();
					printf("\n\n\t> %s   X   %s <\n", SM2[0].name, SM2[1].name);
					finalCombats(SM2);
					finalBattle[1]=SM2[0];
}



void GrandfinalCombat(warrior *SM)
{
		warrior *P1, *P2;

		P1 = &SM[0];
		P2 = &SM[1];

		printf("\n>IRAH COMECAR A GRANDE FINAL DO TORNEIO TERMINAL, QUEM SERAH O GRANDE CAMPEAO ?!\n");
		getchar();
		printf("\n>Os guerreiros %s e %s entram na arena, a torcida vai a LOUCURA!!!!!!\n", P1->name, P2->name);
		getchar();

		int turn, i=0, x=0, Bglory1, Bglory2, countTurn=1;
		int atk, shield, damage;
		int hp1=0, hp2=0;

		Bglory1 = gloryBonus(P1);
		getchar();
		Bglory2 = gloryBonus(P2);
		hp1=P1->health_points;
		hp2=P2->health_points;
		int again=0;

		getchar();

		turn = rand() % 2;

		while(hp1 > 0 && hp2 > 0){

			printf("\n\n\t**%d TURNO HP(%d/%d)**\t\n\n", countTurn, hp1, hp2);

			if (turn==0){

					atk=rolaDados()+(P1->atack)+Bglory1;

					if (countTurn>10 && again==0){
						
						again=1;
						printf("\n**A LUTA ESTAH MUITO EMOCIONANTE, OS GUERREIROS ENTRAM EM FURIA (2.5x ATK)**\n");
						atk*=1.5;
					}

					shield=rolaDados()+(P2->defense)+Bglory2;
					damage=atk-shield;

					battleStatus(atk, shield, turn, P1, P2);

					if(damage>0){
						printf("\n>%s perdeu %d ponto(s) de vida!!!\n", P2->name, damage);
						hp2-=damage;
					}

					else if(damage<=0){
						printf("\n>%s defendeu o ataque!!!\n", P2->name);
					}

					turn=1;
				}

			else if (turn==1){

					atk=rolaDados()+(P2->atack)+Bglory2;

					if (countTurn>10 && again==0){

						again=1;
						printf("\n**A LUTA ESTAH MUITO EMOCIONANTE, OS GUERREIROS ENTRAM EM FURIA (2.5x ATK)**\n");
						atk*=1.5;
					}

					shield=rolaDados()+(P1->defense)+Bglory1;
					damage=atk-shield;

					battleStatus(atk, shield, turn, P1, P2);

					if(damage>0){
						printf("\n>%s perdeu %d ponto(s) de vida!!!\n", P1->name, damage);
						hp1-=damage;
					}

					else if (damage<=0){
						printf("\n>%s defendeu o ataque!!!\n", P1->name);
					}

					turn=0;
				}

			countTurn++;

			getchar();
		}

		printf("\n\t\t**A BATALHA TERMINOU**\n\n");
		getchar();

		if (hp1 > hp2){
			
			printf("\n\t***%s E O GRANDE CAMPEAO DO TORNEIO!!!***\n\n\n", P1->name);
			getchar();
			exit(0);
		}

		else if (hp2 > hp1){
			
			printf("\n\t***%s E O GRANDE CAMPEAO DO TORNEIO!!!***\n\n\n", P2->name);
			getchar();
			exit(0);
		}
}