// Classe utilizada para fazer a comunicacao entre as duas filas existentes no programa
#ifndef DISPLAYFILAS
#define DISPLAYFILAS
#include "List.h"

class displayFilas {
	protected:
		List fila1;
		List fila2;
	public:
		displayFilas();
		void insertNewAds();
		void transferAds();
		//void excludeAds();
};
#endif

