#include "Maximum.h"



Maximum::Maximum() : max(std::numeric_limits<int>::min())
{
}

int Maximum::getMax() const { return max; }

void Maximum::operator() (const int x)
{
	if(x>max)
	{
		max = x;
	}
}


Maximum::~Maximum()
{
}
