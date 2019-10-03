#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	
	float valorIMC(float peso, float altura){
		float IMC;
		IMC=peso/(altura*altura);
		return IMC;
	}

	

int main(){

	float peso=0, altura=0, x=0, IMC=0, y=0;
	//parâmetros para Brutus (1.84m - 122kg)
	//parâmetros para Olívia (1.72m - 45kg)
	scanf("%f %f", &peso, &altura);

	IMC= valorIMC(peso, altura);
	printf("IMC = %.2f\n", IMC);

	if (IMC<16)
	{
		y=18.5-IMC;
		x=y*(altura*altura);
		printf("Magreza grave, necessita ganhar: %.1f kg(s)\n", x);
	}

	else if (16<IMC && IMC<17){
		y=18.5-IMC;
		x=y*(altura*altura);
		printf("Magreza moderada, necessita ganhar: %.1f kg(s)\n", x);
	}

	else if (17<IMC && IMC<18.5){
		y=18.5-IMC;
		x=y*(altura*altura);
		printf("Magreza leve, necessita ganhar: %.1f\n kg(s)", x);
	}

	else if (18.5<IMC && IMC<25){
		printf("Invíduo saudável!\n");
	}

	else if (25<IMC && IMC<30){
		y=IMC-25.1;
		x=y*(altura*altura);
		printf("Sobrepeso, necessita perder %.1f\n kg(s)", x);
	}

	else if (30<IMC && IMC<35){
		y=IMC-25.1;
		x=y*(altura*altura);
		printf("Obesidade grau I, necessita perder %.1f\n kg(s)", x);
	}

	else if (35<IMC && IMC<40){
		y=IMC-25.1;
		x=y*(altura*altura);
		printf("Obesidade grau II, necessita perder %.1f\n kg(s)", x);
	}

	else if (IMC>=40){
		y=IMC-25.1;
		x=y*(altura*altura);
		printf("Obesidade grau III, nercessita perder %.1f\n kg(s)", x);
	}



	return 0;
}