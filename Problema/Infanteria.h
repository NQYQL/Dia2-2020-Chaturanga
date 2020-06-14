#ifndef INFANTERIA
#define INFANTERIA

#include "Pieza.h"

class Infanteria : public Pieza{
	private:
		bool valid(int fil, int col);
	
	public:
		Infanteria(int, int, Pieza***, bool);
};

#endif
