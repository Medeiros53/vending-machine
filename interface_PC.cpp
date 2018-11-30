#include "interface_PC.h"
// uso de template para converter numero em string
template <typename T>
string number2string(T number){
	ostringstream ss;
	ss << number;
	return ss.str();
}
// construtor da classe interface_pc
interface_PC::interface_PC(){
	input = 0;
		iCount = 0;
		output = 0;
		disp = "nada";
		refri1 = 0;
		refri2 = 0;
		min = 0;
		min2 = 0;
}

// funcao que chama chama a maquina de estados quando a entrada eh uma moeda

void interface_PC::setCoin(int coin){
	if (coin == 1){
		output = callNextState(2);
	}else if(coin == 2){
		output = callNextState(3);
	}else if(coin == 3){
		output = callNextState(4);
	}else{
		output = callNextState(1);
	}
	//selectOutput(input);
}
// funcao que chama a maquina de estados quando o botao de devolucao eh acionado
void interface_PC::setDev(){
	output = callNextState(5);
	//selectOutput(input);
}
// funcao que chama a maquina de estados quando um dos botoes dos refrigerantes eh acionado
void interface_PC::setRefri(int refri){
	if (refri == 1){
		output = callNextState(6);
	}else if (refri == 2){
		output = callNextState(7);
	}else{
		output = callNextState(1);
	}
	//selectOutput(input);
}
// aqui eh a funcao que indica quando se tem devolucao de troco ou se tem entrega de refrigerantes
void interface_PC::selectOutput(int output){
	float x, y;

	if (output == 10){
		cout << "entrega refri meet" << endl;
		refri1++;
		disp = "entrega refri meet";
	}else if(output == 11){
		cout << "entrega refri etirps" << endl;
		disp = "entrega refri etirps";
		refri2++;
	}else if(output > 11){
		y = output;
		x = y/100;
		cout << "troco =" << x << endl;
		if (y == 25){
			disp = "troco = 0,25";
		}else if (y == 50){
			disp = "troco = 0,50";
		}else if (y==75){
			disp = "troco = 0,75";
		}else if (y==100){
			disp = "troco = 1,00";
		}else if (y==125){
			disp = "troco 1,25";
		}else if (y==150){
			disp = "troco 1,50";
		}else{
			disp = "nada";
		}

	}else{
		disp = "nada";
	}
}
//funcao que le as entradas da placa para acionar as funcoes que chamam a maquina de estado
string interface_PC::readKeyboard(){
	cin >> input;
	//input = readButtons();
	if (((0 < input)&(input < 4))&(iCount == 0)){
		setCoin(input);
		iCount++;

	}else if (((3 < input)&(input < 6))&(iCount == 0)){
		setRefri(input-3);
		iCount++;
	}else if ((input == 6)&(iCount == 0)){
		setDev();
		iCount++;
	}else if((input == 6)&(iCount == 0)){
		insertNewAds();
		output = 0;
		iCount++;
	}else if((input == 7)&(iCount == 0)){
		transferAds();
		output = 0;
		iCount++;
	}else{
		iCount = 0;


	}
	selectOutput(output);
	output = 0;

// aqui eh salvado o arquivo que contem a quantidade de refrigerantes que foram vendidos no dia
	if(min2 != min){
		min2 = min;
		getNameFile();
		saveFile(refri1, refri2);
	}
	return disp;
}
// Essa funcao chama as propagandas para serem exibidas e o horario eh exibido aleatoriamente
// numa proporcao de 1 pra cada 5 mensagens

string interface_PC::displayAds(){
	string ads;
		int x;

		x = rand()%10;
		cout << x;
		if ((x == 3)||(x == 7)){
			cout << "teste" << endl;
			displayTimeAndDate();
			return ads;
		}else{

		ads = fila1.readFirst();
		cout << ads << endl; //-------------------------------------------rever----------------------------------------------------
		fila1.removeFirst();
		fila1.insertAfterLast(ads);
		return ads;

}
		// Essa funcao automaticamente a data e hora utilizando a funcao friend
		ostream& operator<< (ostream& c, interface_PC tempo){
			c << tempo.hr << ":";
			c << tempo.min << ":";
			c << tempo.sec << "  ";
			c << tempo.day << "/";
			c << tempo.mo << "/";
			c << tempo.yr << "\n";
			return (c);
		}
		// Essa funcao printa manualmente a data e hora do dia
		void interface_PC::displayTimeAndDate(){
			theTime = time(NULL);
			struct tm *aTime = localtime(&theTime);
			day = aTime->tm_mday, mo = aTime->tm_mon, yr = aTime->tm_year, sec = aTime->tm_sec, min = aTime->tm_min, hr = aTime->tm_hour;

			cout << hr << ":";
			cout << min << ":";
			cout << sec << "  ";
			cout << day << "/";
			cout << mo << "/";
			cout << yr << "\n";
		}
		// Essa funcao transforma o dia e o mes numa string para salvar o arquivo em txt
		string interface_PC::getNameFile(){
			string dia, mes;
			dia = number2string(min); //arrumar
			mes = number2string(mo);
			line = "dia_";
			line.append(dia);
			line.append("_mes_");
			line.append(mes);
			line.append(".txt");
			return line;
		}
		// Essa funcao utiliza o ofstream para salvar o arquivo .txt
		void interface_PC::saveFile(int refri1, int refri2){
			ofstream myfile (line.c_str());
			if (myfile.is_open()){
				myfile << "refri1:" << refri1 << "\n";
				myfile << "refri2:" << refri2 << "\n";
				myfile.close();
			}
		}
