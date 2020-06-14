#include "Caballo.h"
#include <cstddef>

Caballo::Caballo(int fil, int col, Pieza** tab, bool jug){
	if(jug){
		caracter = 'O';
	}else{
		caracter = 'C';
	}
}

bool Caballo::valid(int fil, int col){
	if(validDentro(fil, col)){
		
		if(
			(fil == fila + 1 && col == columna + 2) &&
			(fil == fila + 1 && col == columna - 2) &&
			(fil == fila - 1 && col == columna + 2) &&
			(fil == fila - 1 && col == columna - 2) &&
			(fil == fila + 2 && col == columna + 1) &&
			(fil == fila + 2 && col == columna - 1) &&
			(fil == fila - 2 && col == columna + 1) &&
			(fil == fila - 2 && col == columna - 1)
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
