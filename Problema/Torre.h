#ifndef TORRE
#define TORRE

#include "Pieza.h"

class Torre : public Pieza{
	private:
		bool valid(int fil, int col);
	
	public:
		Torre(int, int, Pieza**, bool);
};

#endif
