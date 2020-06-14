#ifndef CHATURANGA
#define CHATURANGA


class Chaturanga {
	private:
		Pieza*** tablero;
		
		void iniciarTablero();
		bool turno(bool);
		bool validDentro(int, int);
		void print();
		void clean();
	
	public:
		Chaturanga();
		void jugar();
		~Chaturanga();
};

#endif
