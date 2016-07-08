#include "Average.h"



Average::Average() : sum(0), size(-1.f)
{
}


float Average::getAverage() const
{
	return sum / size;
}

float Average::getSum() const
{
	return sum;
}

int Average::getSize() const
{
	return size;
}

void Average::operator() (const int x)
{
	sum += x;
}

Average::~Average()
{
}
