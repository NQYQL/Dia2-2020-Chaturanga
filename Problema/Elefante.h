#ifndef ELEFANTE
#define ELEFANTE

#include "Pieza.h"

class Elefante : public Pieza{
	private:
		bool valid(int fil, int col);
	
	public:
		Elefante(int, int, Pieza***, bool);
};

#endif
