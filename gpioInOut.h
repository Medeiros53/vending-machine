// Arquivo header com os atributos e metodos da classe gpioInOut
// Esta classe nao esta inclusa no interface_PC
#include <iostream>
#include <string>
#include <unistd.h>
#include "SimpleGPIO.h"
using namespace std;

class gpioInOut {
	// Os seguintes atributos sao as entradas da placa
protected:
	unsigned int Button1GPIO;   // GPIO1_28 = (1x32) + 28 = 60 -- P9-12
	unsigned int Button2GPIO;   // GPIO0_15 = (0x32) + 15 = 15 -- P9-24
	unsigned int Button3GPIO;   // GPIO0_31 = (0x32) + 31 = 31 -- P9-13
	unsigned int Button4GPIO;   // GPIO1_18 = (1x32) + 18 = 50 -- P9-14
	unsigned int Button5GPIO;   // GPIO1_16 = (1x32) + 16 = 48 -- P9-15
	unsigned int Button6GPIO;   // GPIO1_19 = (1x32) + 19 = 51 -- P9-16
	unsigned int Button7GPIO;   // GPIO0_3 = (0x3) + 3 = 3 -- P9-21
	unsigned int Button8GPIO;   // GPIO0_2 = (0x2) + 2 = 2 -- P9-22
	unsigned int value;
public:
	void setButtons();
	int readButtons();
};

