#include "Average.h"



Average::Average() : sum(0.f), size(0)
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
	++size;
}

Average::~Average()
{
}
