// classe virtual que serve para se utilizar o polimorfismo das classe interface_pc e interface_maq
#ifndef INTERFACE
#define INTERFACE
#include "headers.h"

class interface{
public:
	virtual string displayAds() = 0;
	virtual string readKeyboard() = 0;
};
#endif
