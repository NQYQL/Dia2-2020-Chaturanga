#include "Elefante.h"
#include <cstddef>

Elefante::Elefante(int fil, int col, Pieza*** tab, bool jug){
	if(jug){
		caracter = '3';
	}else{
		caracter = 'E';
	}
}

bool Elefante::valid(int fil, int col){
	if(validDentro(fil, col)){
		
		if(
			(fil == fila + 2 && col == columna + 2) &&
			(fil == fila + 2 && col == columna - 2) &&
			(fil == fila - 2 && col == columna + 2) &&
			(fil == fila - 2 && col == columna - 2)
		){
			if(Pieza* p = tablero[fil][col]){
				if(p.getJugador() == jugador){
					return false;
				}
			}
			return true;
		}
	}
	return false;
}
