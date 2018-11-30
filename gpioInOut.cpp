#include "gpioInOut.h"

// Essa funcao exporta os pinos da placa e tambem fornece a direcao deles.
void gpioInOut::setButtons(){

	Button1GPIO = 3;   // GPIO1_28 = (1x32) + 28 = 60 -- P9-12
	Button2GPIO = 15;   // GPIO0_15 = (0x32) + 15 = 15 -- P9-24
	Button3GPIO = 115;   // GPIO0_31 = (0x32) + 31 = 31 -- P9-13
	Button4GPIO = 27;   // GPIO1_18 = (1x32) + 18 = 50 -- P9-14
	Button5GPIO = 47;   // GPIO1_16 = (1x32) + 16 = 48 -- P9-15
	Button6GPIO = 46;   // GPIO1_19 = (1x32) + 19 = 51 -- P9-16
	Button7GPIO = 26;   // GPIO0_3 = (0x3) + 3 = 3 -- P9-21
	Button8GPIO = 44;   // GPIO0_2 = (0x2) + 2 = 2 -- P9-22

	gpio_export(Button1GPIO);
	gpio_export(Button2GPIO);
	gpio_export(Button3GPIO);
	gpio_export(Button4GPIO);
	gpio_export(Button5GPIO);
	gpio_export(Button6GPIO);
	gpio_export(Button7GPIO);
	gpio_export(Button8GPIO);

	gpio_set_dir(Button1GPIO, INPUT_PIN);
	gpio_set_dir(Button2GPIO, INPUT_PIN);
	gpio_set_dir(Button3GPIO, INPUT_PIN);
	gpio_set_dir(Button4GPIO, INPUT_PIN);
	gpio_set_dir(Button5GPIO, INPUT_PIN);
	gpio_set_dir(Button6GPIO, INPUT_PIN);
	gpio_set_dir(Button7GPIO, INPUT_PIN);
	gpio_set_dir(Button8GPIO, INPUT_PIN);

}
// Essa funcao eh chama pela interface_Placa para monitorar as entradas da placa
int gpioInOut::readButtons(){

	value = LOW;
	gpio_get_value(Button1GPIO, &value);
	if (value == HIGH){
		return 1;
	}
	gpio_get_value(Button2GPIO, &value);
	if (value == HIGH){
		return 2;
	}
	gpio_get_value(Button3GPIO, &value);
	if (value == HIGH){
		return 3;
	}
	gpio_get_value(Button4GPIO, &value);
	if (value == HIGH){
		return 4;
	}
	gpio_get_value(Button5GPIO, &value);
	if (value == HIGH){
		return 5;
	}
	gpio_get_value(Button6GPIO, &value);
	if (value == HIGH){
		return 6;
	}
	gpio_get_value(Button7GPIO, &value);
	if (value == HIGH){
		return 7;
	}
	gpio_get_value(Button8GPIO, &value);
	if (value == HIGH){
		return 8;
	}else{
		return 0;
	}


}
