#include "displayFilas.h"
// Construtor para adiocionar a frase "sem propagandas" no incio do programa
displayFilas::displayFilas(){
	string ads = "Sem_Propagandas";
	
	fila1.insertAfterLast(ads);
}


// Com essa funcao se tem acesso a salvar as novas propagandas inseridas
void displayFilas::insertNewAds(){
	string ads;
	int loop = 0;
	
	while (loop == 0){
	  cout << "Insira a propaganda - (Para finalizar digite finalizar)" << endl;
	  getline(cin,ads);
	  if (ads == "finalizar"){
		  loop = 1;
	    }else{
		  fila2.insertAfterLast(ads);
	    }
    }	
    cout << "Propagandas inseridas" << endl;
}

// Apos ter as propagandas salvas essa funcao permite transferir de uma fila para a outra

void displayFilas::transferAds(){
	int loop = 0;
	string ads;
	
	cout << "Transferindo" << endl;
	while(loop == 0){
		loop = fila1.removeFirst();
	}
	//cout << "saiu do primeiro loop" << endl;
	loop = 0;
	while(loop == 0){
		ads = fila2.readFirst();
		//cout << ads << endl;	
		fila1.insertAfterLast(ads);
		loop = fila2.removeFirst();
		//cout << loop << endl;
	}
	cout << "Transferencia completa" << endl;
}


