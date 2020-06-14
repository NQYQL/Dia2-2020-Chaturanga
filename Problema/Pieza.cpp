#include "Pieza.h"
#include <cstddef>

Pieza::Pieza(int fil, int col, Pieza*** tab, bool jug){
	fila = fil;
	columna = col;
	tablero = tab;
	jugador = jug;
}

bool Pieza::validDentro(int fil, int col){
	return (fil >= 0 && fil < 8) || (col >= 0 && col < 8);
}

char Pieza::getChar(){
	return caracter;
}

bool Pieza::getJugador(){
	return jugador;
}

bool Pieza::movimiento(int fil, int col){
	if(valid(col, fil)){
		
		if(Pieza* p = tablero[fil][col]){
			delete p;
			tablero[col][fil] = NULL;
		}
		
		tablero[col][fil] = tablero[columna][fila];
		tablero[fila][columna] = NULL;
		fila = fil;
		columna = col;
		return true;
	}
	return false;
}
