typedef struct warrior
{
	int atack;
	int defense;
	int glory;
	int health_points;
	int player_id;
}warrior;

int rolaDados();
void criaGuerreiro(warrior *P, int *player);
void statusPlayer(warrior *P);
int gloryBonus(warrior *P);
void combat(warrior *P1, warrior *P2);
void intro();
void battleStatus(int atk, int def, int turn);