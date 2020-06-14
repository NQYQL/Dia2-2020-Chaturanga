#ifndef MINISTRO
#define MINISTRO

#include "Pieza.h"

class Ministro : public Pieza{
	private:
		bool valid(int fil, int col);
	
	public:
		Ministro(int, int, Pieza***, bool);
};

#endif
