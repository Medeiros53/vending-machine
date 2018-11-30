// Classe da maquina de estados do programa - fsm
#ifndef CONTROLE
#define CONTROLE

#include <stdlib.h>
#include <iostream>
using namespace std;

class controle{
	int valor;
	int state;
public:
	controle();
	//void inputCoin(int valor);
	//void inputDev();
	//void inputRefri(int option);
	//void outputDev(int valor);
	//void outputRefri(int option);
	int callNextState(int nextState);
};

#endif
