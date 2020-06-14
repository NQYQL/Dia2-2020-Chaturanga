#include "Torre.h"
#include <cstddef>

Torre::Torre(int fil, int col, Pieza** tab, bool jug){
	if(jug){
		caracter = 'Y';
	}else{
		caracter = 'T';
	}
}

bool Torre::valid(int fil, int col){
	if(validDentro(fil, col)){
		
		if(fil == fila){
			int mov = 1;
			if(col < columna)
				mov = -1;
			for(int i = columna + mov; i != col; i += mov){
				if(Pieza* p = tablero[fila][i]){
					return false;
				}
			}
		}else if(col == columna){
			int mov = 1;
			if(fil < fila)
				mov = -1;
			for(int i = fila + mov; i != fil; i += mov){
				if(Pieza* p = tablero[i][columna]){
					return false;
				}
			}
		}else{
			return false;
		}
		if(Pieza* p = tablero[fila][columna]){
			if(p.getJugador() == jugador){
				return false;
			}
		}
		return true;
	}
	return false;
}
