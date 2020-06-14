#ifndef RAJA
#define RAJA

#include "Pieza.h"

class Raja : public Pieza{
	private:
		bool valid(int fil, int col);
	
	public:
		Raja(int, int, Pieza***, bool);
};

#endif
