#ifndef PIEZA
#define PIEZA

class Pieza {
	protected:
		Pieza*** tablero;
		int fila;
		int columna;
		char caracter;
		bool jugador;
		
		bool validDentro(int fil, int col);
		virtual bool valid(int fil, int col);
	
	public:
		Pieza(int fil, int col, Pieza*** tab, bool jug);
		bool movimiento(int fil, int col);
		char getChar();
		bool getJugador();

};

#endif
