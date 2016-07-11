#include "Histogram.h"



Histogram::Histogram() : upper(-1), lower(-1), numBins(-1), counts()
{
}

Histogram::Histogram(const Histogram& h) : upper(h.upper), lower(h.lower), numBins(h.numBins), counts(h.counts){}

Histogram::Histogram(int u, int l, int n) : upper(u), lower(l), numBins(n), counts(std::vector<int>(numBins,0))
{

}

std::vector<int> Histogram::getCounts() const
{
	return counts;
}

const Histogram& Histogram::operator=(const Histogram& h)
{
	if (this != &h)
	{
		this->upper = h.upper;
		this->lower = h.lower;
		this->numBins = h.numBins;
		this->counts = h.counts;
	}
	return *this;
}


void Histogram::operator() (int x)
{
	int curLowerBound = lower;
	//Size of bins:  ceiling(upper - lower / numBins) 
	int bSize = (int)(ceil(float(upper - lower )/ numBins));
	int curUpperBound = curLowerBound + bSize;
	//Between b(upper, lower);

	for (int i = 0; i < counts.size(); i++)
	{
		if (x >= curLowerBound && x < curUpperBound)
		{
			counts[i]++;
			break;
		}

		curLowerBound = curUpperBound;
		curUpperBound += bSize;
	}
}

Histogram::~Histogram()
{
}
