typedef struct warrior
{
	int position;
	char *name;
	int atack;
	int defense;
	int glory;
	int health_points;
	int player_id;
	int score;
	int turnScore;
}warrior;

int rolaDados();
void criaGuerreiros(warrior *P, int size);
void statusPlayer(warrior *P, int player);
int gloryBonus(warrior *P);
void fastCombat(warrior *P1, warrior *P2);
void finalCombats(warrior *SM);
void intro();
void battleStatus(int atk, int def, int turn, warrior *P1, warrior *P2);
void resetArray(int *array, int size);
void CgroupPhase(warrior *P, int size, int *array, warrior *arrayNext);
void printGroups(warrior *group, int groupNumber);
void GroupCombat(warrior *group, warrior *nextPhase, int groupNumber);
int fastGloryBonus(warrior *P);
void sortGroup(warrior *group);
void CsemiPhase(warrior *semifinal, int size, int *flagControl4, warrior *finalBattle);
void GrandfinalCombat(warrior *SM);