#include <iostream>
#include <string>
#include "Chaturanga.h"

using namespace std;

int main(int argc, char** argv) {
	int resp;
	Chaturanga* juego = new Chaturanga();
	do{
		cout<< endl << endl << "Desea jugar? (1 = si)"<< endl
			<< ":";
		cin >> resp;
		if(resp == 1){
			juego->jugar();
		}else{
			cout << "Gracias por usar el programa!!" << endl;
		}
	}while(resp != 1);
	delete juego;
	return 0;
}
