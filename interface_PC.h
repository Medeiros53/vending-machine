// arquivo header com os atributos e metodos da classe interface_PC
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include "controle.h"
#include "displayFilas.h"
//#include "gpioInOut.h"
#include "interface.h"

class interface_PC:  public displayFilas, public controle, public interface {
protected:
	int input;
		int iCount;
		int output;
		//int rand();
		string disp, line;
		time_t theTime;
		int day, mo, yr, hr, min, sec, min2;
		int refri1, refri2;
public:
	interface_PC();
	void setCoin(int coin);
	void setDev();
	void setRefri(int refri);
	//void getRefri(int getRefri);
	//void getTroco(int troco);
	void selectOutput(int output);
	void displayTimeAndDate();
	friend ostream& operator<< (ostream&,interface_PC);
	string readKeyboard();
	string displayAds();
	string getNameFile();
	void saveFile(int refri1, int refri2);
};
