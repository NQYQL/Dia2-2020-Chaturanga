#ifndef CABALLO
#define CABALLO

#include "Pieza.h"

class Caballo : public Pieza{
	private:
		bool valid(int fil, int col);
	
	public:
		Caballo(int, int, Pieza**, bool);
};

#endif
