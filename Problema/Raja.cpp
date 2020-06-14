
#include <cstddef>

Raja::Raja(int fil, int col, Pieza*** tab, bool jug){
	if(jug){
		caracter = 'P';
	}else{
		caracter = 'R';
	}
}

bool Raja::valid(int fil, int col){
	if(validDentro(fil, col)){
		
		if(
			(fil == fila + 1 && col == columna + 1) &&
			(fil == fila + 1 && col == columna - 1) &&
			(fil == fila - 1 && col == columna + 1) &&
			(fil == fila - 1 && col == columna - 1) &&
			(fil == fila + 1 && col == columna ) &&
			(fil == fila - 1 && col == columna ) &&
			(fil == fila && col == columna + 1) &&
			(fil == fila && col == columna - 1)
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
