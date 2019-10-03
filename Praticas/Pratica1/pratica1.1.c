#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	float transation(float inBank){
		float refresh;
		float incrementM = 1.0056;
		refresh=inBank*incrementM;
		return refresh;
	}

int main(){

	float inBank=789.54;

	inBank=transation(inBank)+303.20;
	inBank=transation(inBank)-58.25;
	inBank=transation(inBank);

	
	printf("%.2f\n", inBank);

	return 0;234
}