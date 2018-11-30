#include "controle.h"

// Funcao construtor da maquina de estados
controle::controle(){
	state = 1;
}

// Aqui eh a implementacao propriamente dita da maquina de estados que corresponde as 49 possiveis possiblidades
// de ocorrencia do programa
int controle::callNextState(int nextState){
	//controle saida;

	switch(state) {
		case(1) : // Nada
			switch(nextState){
				case(1) :
					state = nextState;
					return 1;

				case(2) :
					state = nextState;
					return 2;

				case(3) :
					state = nextState;
					return 3;

				case(4) :
					state = nextState;
					return 4;

				case(5) :
					return 1;

				case(6) :
					return 1;

				case(7) :
					return 1;

			}
			break;
			case(2) : // s025
				switch(nextState){
					case(1) :
						return 2;

					case(2) :
						state = 3;//s050
						return 3;

					case(3) :
						state = 4;//s075
						return 4;

					case(4) :
						state = 6;//s125
						return 6;

					case(5):
						state = 1;//s000
						return 25;

					case(6) :
						return 2;

					case(7) :
						return 2;

				}
			break;
			case(3) : // s050
				switch(nextState){
					case(1) :
						return 3;

					case(2) :
						state = 4;//s075
						return 4;

					case(3) :
						state = 5;//s100
						return 5;

					case(4) :
						state = 7;//s150
						return 7;

					case(5) :
						state = 1;
						return 50;

					case(6) :
						return 3;

					case(7) :
						return 3;

				}
				break;
		case(4) : // s075
			switch(nextState){
				case(1) :
					return 4;

				case(2) :
					state = 5;
					return 5;

				case(3) :
					state = 6;
					return 6;

				case(4) :
					state = 7;
					return 25;

				case(5) :
					state = 1;
					return 75;

				case(6) :
					return 4;

				case(7) :
					return 4;

			}
			break;
		case(5) : // s100
			switch(nextState){
				case(1) :
					return 5;

				case(2) :
					state = 6;
					return 6;

				case(3) :
					state = 7;
					return 7;

				case(4) :
					state = 7;
					return 50;

				case(5) :
					state = 1;
					return 100;

				case(6) :
					return 5;

				case(7) :
					return 5;

			}
			break;
		case(6) : // s125
			switch(nextState){
				case(1) :

					return 5;

				case(2) :
					state = 7;
					return 7;

				case(3) :
					state = 7;
					return 25;

				case(4) :
					state = 7;
					return 75;

				case(5) :
					state = 1;
					return 125;

				case(6) :

					return 6;

				case(7) :

				return 6;

			}
			break;
		case(7) : // s150
			switch(nextState){
				case(1) :

					return 7;

				case(2) :
					state = 7;
					return 25;

				case(3) :
					state = 7;
					return 50;

				case(4) :
					state = 7;
					return 100;

				case(5) :
					state = 1;
					return 150;

				case(6) :
					state = 1;
					return 10;

				case(7) :
					state = 1;
					return 11;

			}
			break;
	}
}


