#include "Deviation.h"
/*
Deviation() - standard deviation is a measure of how much the data is
dispersed from the average.
formula Deviation( x_1, ... , x_n ) = sqrt ( 1/n * sum ( x_i -a )^2 )
Where 'a' is the Average.
Basically deviation is an average of the squares of the distances to the average.

*/


Deviation::Deviation() : avg(), sumSquares(0.f)
{
}

void Deviation::setAverage(Average a)
{
	avg = a;
}

const Deviation& Deviation::operator=(const Deviation& d)
{
	if (this != &d)
	{
		this->avg = d.avg;
		this->sumSquares = d.sumSquares;
	}
	return *this;
}

Deviation::Deviation(const Deviation& d) : avg(d.avg), sumSquares(d.sumSquares) {}

void Deviation::operator() (int x)
{
	sumSquares += powf(x - avg.getAverage(),2);
}

float Deviation::getDev() const
{
	return sqrtf((1.f / avg.getSize()) * sumSquares);
}


Deviation::~Deviation()
{
}
