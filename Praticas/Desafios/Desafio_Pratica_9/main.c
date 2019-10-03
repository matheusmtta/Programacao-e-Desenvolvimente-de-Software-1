#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"
#include <unistd.h> 
#include <string.h>

int main(){
	
	srand(time(NULL));

		intro();

		int player=1;
		int *play;
		int i=0;
		int flagControl16[16];
		int flagControl4[4];
		warrior semiFinal[4];
		warrior finalBattle[2];
		int resultSM1, resultSM2;
		int f1, f2;

		warrior Warrior;
		warrior *P;

		P = (warrior*) malloc(sizeof(warrior)*16);

		criaGuerreiros(P, 16);

		P[0].name="DANDARA";
		P[1].name="APOLLO";
		P[2].name="ULYSSES";
		P[3].name="AQUILLES";
		P[4].name="BRIENNE";
		P[5].name="HERCULES";
		P[6].name="ANDROMEDA";
		P[7].name="PANDORA";
		P[8].name="IRELIA";
		P[9].name="LEONA";
		P[10].name="DARIUS";
		P[11].name="MAGRELIN";
		P[12].name="ATHENA";
		P[13].name="PERSEU";
		P[14].name="TALYIAH";
		P[15].name="RAGNAR";

		printf("\n\t*Status Inicial*\n\n");

		statusPlayer(P, 16);

		CgroupPhase(P, 16, flagControl16, semiFinal);

		printf("\n\n\t[SEMI-FINAL]\n");

		statusPlayer(semiFinal, 4);

		CsemiPhase(semiFinal, 4, flagControl4, finalBattle);


		printf("\n______________________________________________________________________________\n");
		printf("\n\n\t[GRANDE FINAL]\n");

		statusPlayer(finalBattle, 2);

		printf("\n\n\t> %s   X   %s <\n", finalBattle[0].name, finalBattle[1].name);
		GrandfinalCombat(finalBattle);

		//statusPlayer(P, 16);



		//statusPlayer(P1);
		//statusPlayer(P2);

		//sleep(3);

		//printf("\n\t*COMBATE*\n\n");
		//combat(P1, P2);
}