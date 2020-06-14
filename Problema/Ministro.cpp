#include "Ministro.h"
#include <cstddef>

Ministro::Ministro(int fil, int col, Pieza*** tab, bool jug){
	if(jug){
		caracter = 'W';
	}else{
		caracter = 'M';
	}
}

bool Ministro::valid(int fil, int col){
	if(validDentro(fil, col)){
		
		if(
			(fil == fila + 1 && col == columna + 1) &&
			(fil == fila + 1 && col == columna - 1) &&
			(fil == fila - 1 && col == columna + 1) &&
			(fil == fila - 1 && col == columna - 1)
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
