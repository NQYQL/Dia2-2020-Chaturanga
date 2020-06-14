#include "Infanteria.h"
#include <cstddef>

Infanteria::Infanteria(int fil, int col, Pieza*** tab, bool jug) : Pieza(fil, col, tab, jug){
	if(jug){
		caracter = 'L';
	}else{
		caracter = 'I';
	}
}

bool Infanteria::valid(int fil, int col){
	if(validDentro(fil, col)){
		int mov = 1;
		if(jugador)
			mov = -1;
		
		if(fil == fila + mov){
			if(col == columna){
				return (tablero[fil][col] == NULL);
			}else if((col == columna + 1) || (col == columna - 1)){
				if(Pieza* p = tablero[fil][col]){
					return (p.getJugador() != jugador);
				}
			}
		}
	}
	return false;
}
