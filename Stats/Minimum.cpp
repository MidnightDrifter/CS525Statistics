#include "Minimum.h"



Minimum::Minimum() : min(std::numeric_limits<int>::max())
{
}


int Minimum::getMin() const { return min; }
void Minimum::operator() (int x)
{ if(x<min)
	{
	min = x;
	}
}

Minimum::~Minimum()
{
}
