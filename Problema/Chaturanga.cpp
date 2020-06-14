#include "Chaturanga.h"
#include "iostream"
#include <string>

using namespace std;

Chaturanga::Chaturanga(){
	iniciarTablero();
}

void Chaturanga::iniciarTablero(){
	tablero = new Pieza**[8];
	for(int i = 0; i < 8 ; i++){
		tablero[i] = new Pieza*[8];
		for(int j = 0; j < 8 ; j++){
			tablero[i][j] = NULL;
		}
	}
	
	for(int i = 0; i < 8 ; i++){
		tablero[1][i] = new Infanteria(1, i, tablero, false);
		tablero[6][i] = new Infanteria(6, i, tablero, true);
	}
	tablero[0][0] = new Torre(0, 0, tablero, false);
	tablero[0][7] = new Torre(0, 0, tablero, false);
	tablero[7][0] = new Torre(0, 0, tablero, true);
	tablero[7][7] = new Torre(0, 0, tablero, true);
	tablero[0][1] = new Caballo(0, 0, tablero, false);
	tablero[0][6] = new Caballo(0, 0, tablero, false);
	tablero[7][1] = new Caballo(0, 0, tablero, true);
	tablero[7][6] = new Caballo(0, 0, tablero, true);
	tablero[0][2] = new Elefante(0, 0, tablero, false);
	tablero[0][5] = new Elefante(0, 0, tablero, false);
	tablero[7][2] = new Elefante(0, 0, tablero, true);
	tablero[7][5] = new Elefante(0, 0, tablero, true);
	tablero[0][4] = new Ministro(0, 0, tablero, false);
	tablero[7][3] = new Ministro(0, 0, tablero, true);
	tablero[0][3] = new Raja(0, 0, tablero, false);
	tablero[7][4] = new Raja(0, 0, tablero, true);
}

void Chaturanga::jugar(){
	bool jugador = false;
	do{
		jugador = !jugador;
	}while(turno(jugador));
	clean();
	iniciarTablero();
	return;
}

bool Chaturanga::turno(bool jugador){
	print();
	
	bool valido = true;
	do{
		string input = "";
		cout<< endl
			<< "Ingrese coordenadas jugador ";
		if(jugador){
			cout<< "1 (Piezas blancas)";
		}else{
			cout<< "2 (Piezas negras)";
		}
		cout<< endl
			<< ":";
		getline(cin, input);
		
		if(input.length() == 5){
			if (input == "salir"){
				cout << "Gracias por jugar!" << endl;
				return false;
			}else if(input[2] != '-'){
				cout << "Ingrese un formato valido!!" << endl;
				continue;
			}
			int columnaOrigen = input[0] - 'A';
			int filaOrigen = input[1] - '0';
			int columnaDestino = input[2] - 'A';
			int filaDestino = input[3] - '0';
			
			if(validDentro(filaOrigen, columnaOrigen)){
				if(validDentro(filaDestino, columnaDestino)){
					if(Pieza* p = tablero[filaOrigen][columnaOrigen]){
						if(p.getJugador() != jugador){
							if(p.movimiento(filaDestino, columnaDestino)){
								valido = false;
								break;
							}else{
								cout << "Ingrese un movimiento valido!!" << endl;
							}
						}else{
							cout << "Ingrese un origen con una pieza suya!!" << endl;
						}
					}else{
						cout << "Ingrese un origen con una pieza!!" << endl;
					}
				}else{
					cout << "Ingrese valores de destino dentro del tablero porfavor!!" << endl;
				}
			}else{
				cout << "Ingrese valores de origen dentro del tablero porfavor!!" << endl;
			}

		}
	}while(valido);
	return true;
}

bool Chaturanga::validDentro(int fil, int col){
	return (fil >= 0 && fil < 8) && (col >= 0 && col < 8);
}

void Chaturanga::print(){
	cout << "     A  B  C  D  E  F  G  H" << endl << endl;
	for(int i = 0; i < 8; i++ ){
		cout << " " << i << "  ";
		for(int j = 0; j < 8; j++ ){
			if(Pieza* p = tablero[i][j]){
				cout << " " << p.getChar() << " ";
			}else{
				cout << " . ";	
			}
		}
		cout << endl;
	}
}

void Chaturanga::clean(){
	for (int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(Pieza* p = tablero[i][j]){
				delete p;
				p = NULL;
			}
		}
		delete[] tablero[i];
		tablero[i] = NULL;
	}
	delete[] tablero;
	tablero = NULL;
}

Chaturanga::~Chaturanga(){
	clean();
}
