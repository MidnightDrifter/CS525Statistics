#include "statistics.h"
#include <numeric> //accumulate
#include <cmath> //sqrt
#include <iterator> //ostream_iterator, back_inserter
#include <iomanip> //setfill setw
#include <iostream> //cout

Statistics::Statistics() : data(), avg(), size(), omt(), max(), min(), dev(), hist(), removeIf() {}

std::ostream& operator<<( std::ostream& out, Statistics const& stat ) {
    std::copy( stat.data.begin(),  stat.data.end(),
               std::ostream_iterator<int>( out, " " ) );
    return out;
}

std::istream& operator>>( std::istream& in, Statistics & stat ) {
    std::copy( std::istream_iterator<int>(in),
               std::istream_iterator<int>(),
               std::back_inserter( stat.data ) );
    return in; 
}



float Statistics::Average()
{
	return std::for_each(data.begin(), data.end(), avg).getAverage();
}

float Statistics::Deviation()
{
	
	dev.setAverage(std::for_each(data.begin(), data.end(), avg));
	//dev = std::for_each(data.begin(), data.end(), dev);
	return std::for_each(data.begin(), data.end(), dev).getDev();
}

int Statistics::Maximum()
{
	return std::for_each(data.begin(), data.end(), max).getMax();
}

int Statistics::Minimum()
{
	return std::for_each(data.begin(), data.end(), min).getMin();
}

int Statistics::Size()
{
	//return data.size();
	//class Size o = std::for_each(data.begin, data.end, size);
	
	return std::for_each(data.begin(), data.end(), size).getSize();
	
	//return o.getSize();
}


std::map<int, int> Statistics::OccuresMoreThan(int multiplicity)
{

	omt.setMultiplicity(multiplicity);
	//class OccuresMoreThan;// o = OccuresMoreThan::OccuresMoreThan();
	class OccuresMoreThan o = std::for_each(data.begin(), data.end(), omt);
	o.trimMap();
	return o.getMap();
}

std::vector<int> Statistics::Histogram(int numBins, int upper, int lower)
{
	return std::for_each(data.begin(), data.end(), class Histogram(upper, lower, numBins)).getCounts();

}





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
	sumSquares += powf(x - avg.getAverage(), 2);
}

float Deviation::getDev() const
{
	return sqrtf((1.f / avg.getSize()) * sumSquares);
}


Deviation::~Deviation()
{
}









Histogram::Histogram() : upper(-1), lower(-1), numBins(-1), counts()
{
}

Histogram::Histogram(const Histogram& h) : upper(h.upper), lower(h.lower), numBins(h.numBins), counts(h.counts) {}

Histogram::Histogram(int l, int u, int n) : lower(l), upper(u), numBins(n), counts(std::vector<int>(numBins, 0))
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
	int bSize = (int)(ceil(float(upper - lower) / numBins));
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








Maximum::Maximum() : max(std::numeric_limits<int>::min())
{
}

int Maximum::getMax() const { return max; }

void Maximum::operator() (const int x)
{
	if (x>max)
	{
		max = x;
	}
}


Maximum::~Maximum()
{
}







Minimum::Minimum() : min(std::numeric_limits<int>::max())
{
}


int Minimum::getMin() const { return min; }
void Minimum::operator() (int x)
{
	if (x<min)
	{
		min = x;
	}
}

Minimum::~Minimum()
{
}








OccuresMoreThan::OccuresMoreThan()
{
}


OccuresMoreThan::OccuresMoreThan(const OccuresMoreThan& c) : mult(c.mult), map() { map.insert(c.map.begin(), c.map.end()); }

void OccuresMoreThan::operator() (int x)
{
	std::map<int, int>::iterator it = map.find(x);
	if (it == map.end())
	{
		map.insert(std::pair<int, int>(x, 1));
	}

	else
	{
		(*it).second++;
	}


}

void OccuresMoreThan::setMultiplicity(int x) { mult = x; }

void OccuresMoreThan::trimMap()
{
	for (std::map<int, int>::iterator it = map.begin(); it != map.end();)
	{
		if ((*it).second <= mult) {
			std::map<int, int>::iterator temp = it;
			temp++;
			map.erase(it);
			it = temp;
		}

		else
		{
			it++;
		}

	}
}
std::map<int, int> OccuresMoreThan::getMap() const { return map; }


OccuresMoreThan::~OccuresMoreThan()
{
}







Size::Size() : size(0)
{
}

int Size::getSize() const { return size; }

void Size::operator() (int x) { ++size; }


Size::~Size()
{
}







