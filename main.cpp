//============================================================================
// Name        : main.cpp
// Author      : Medeiros
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// inclusao das duas principais classes que fazem parte do programa.
#include "interface_Placa.h"
#include "interface_PC.h"

// variavel para ativar uma das saidas da placa para colocar como sinal de entrada
unsigned int ligar = 48;
//#define system = 1; //ou 2

// criando as duas classes interface_pc e interface_placa derivadas da classe virtual interface
int main() {
	
	// a variavel system serve para que o instalador da maquina decida se o programa vai rodar no computador ou na placa.
	// system  = 1 para rodar no computador, e system = 2 para rodar na placa
	int loop = 1, system = 2;
	interface_Placa placa;
	interface_PC maq;
	interface* dp;
	// dp serve como ponteiro da classe virtual que por polimorfismo vai se tornar ou interface_pc ou interface_placa
	if (system == 1){
		dp = &maq;
		while(loop == 1){
			// funcao que exibe as mensagens utilizando filas
			dp->displayAds();
			//for(int iCount = 0; iCount < 1000000; iCount++){ // como a entrada do computador precisa teclar enter
			// funcao que aguarda a entrada do usario          // o "for" nao se aplica aqui
			dp->readKeyboard();							   /
			//}


		}
	}else if (system == 2){ // aqui eh o loop do usario que escolheu rodar o programa na placa
		dp = &placa;
		// funcoes que setam os GPIOs da placa
		gpio_export(ligar); // para energizar os botoes
		placa.setButtons();
		gpio_set_dir(ligar, OUTPUT_PIN);
		gpio_set_value(ligar, HIGH);
		while(loop == 1){
			dp->displayAds(); // mesma funcionalidade para o computador
			for(int iCount = 0; iCount < 5000; iCount++){ // aqui o programa fica aguardando o usario pressionar um botao
				//cout << "3"<<endl;
				dp->readKeyboard();//funcao que fica lendo as entradas da placa
				//cout << "1" << endl;
			}
		}
	}
	gpio_unexport(ligar);
	return 0;
}
