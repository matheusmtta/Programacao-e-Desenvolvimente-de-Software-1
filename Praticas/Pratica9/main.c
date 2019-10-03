#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"
#include <unistd.h> 

int main(){
	
	srand(time(NULL));

		intro();

		int player=1;
		int *play;

		play = &player;

		warrior player1, player2;
		warrior *P1, *P2;

		P1 = &player1;
		P2 = &player2;

		criaGuerreiro(P1, play);
		criaGuerreiro(P2, play);


		printf("\n\t*Status Inicial*\n\n");
		statusPlayer(P1);
		statusPlayer(P2);

		sleep(3);

		printf("\n\t*COMBATE*\n\n");
		combat(P1, P2);
}