#include "statistics.h"
#include <numeric> //accumulate
#include <cmath> //sqrt
#include <iterator> //ostream_iterator, back_inserter
#include <iomanip> //setfill setw
#include <iostream> //cout

Statistics::Statistics() : data(), avg(), size(), max(), min(), dev(), hist(), omt()  {}

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
	return std::for_each(data.begin(), data.end(), avg).getAverage1();
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
	// Size o = std::for_each(data.begin, data.end, size);
	
	return std::for_each(data.begin(), data.end(), size).getSize1();
	
	//return o.getSize();
}


std::map<int, int> Statistics::OccuresMoreThan(int multiplicity)
{

	omt.setMultiplicity(multiplicity);
	// OccuresMoreThan;// o = OccuresMoreThan::OccuresMoreThan();
	 OccuresMoreThan1 o = std::for_each(data.begin(), data.end(), omt);
	o.trimMap();
	return o.getMap();
}

std::vector<int> Statistics::Histogram(int numBins, int upper, int lower)
{
	return std::for_each(data.begin(), data.end(),  Histogram1(upper, lower, numBins)).getCounts();

}





Average1::Average1() : sum(0.f), size(0)
{
}


float Average1::getAverage1() const
{
	return sum / size;
}

float Average1::getSum() const
{
	return sum;
}

int Average1::getSize() const
{
	return size;
}

void Average1::operator() (const int x)
{
	sum += x;
	++size;
}

Average1::~Average1()
{
}






Deviation1::Deviation1() : avg(), sumSquares(0.f)
{
}

void Deviation1::setAverage(Average1 a)
{
	avg = a;
}

const Deviation1& Deviation1::operator=(const Deviation1& d)
{
	if (this != &d)
	{
		this->avg = d.avg;
		this->sumSquares = d.sumSquares;
	}
	return *this;
}

Deviation1::Deviation1(const Deviation1& d) : avg(d.avg), sumSquares(d.sumSquares) {}

void Deviation1::operator() (int x)
{
	sumSquares += powf(x - avg.getAverage1(), 2);
}

float Deviation1::getDev() const
{
	return sqrtf((1.f / avg.getSize()) * sumSquares);
}


Deviation1::~Deviation1()
{
}









Histogram1::Histogram1() : upper(-1), lower(-1), numBins(-1), counts()
{
}

Histogram1::Histogram1(const Histogram1& h) : upper(h.upper), lower(h.lower), numBins(h.numBins), counts(h.counts) {}

Histogram1::Histogram1(int l, int u, int n) : upper(u), lower(l), numBins(n), counts(std::vector<int>(numBins, 0))
{

}

std::vector<int> Histogram1::getCounts() const
{
	return counts;
}

const Histogram1& Histogram1::operator=(const Histogram1& h)
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


void Histogram1::operator() (int x)
{



	counts[(x-lower)*numBins / (upper-lower)]++;

	//int curLowerBound = lower;
	////Size of bins:  ceiling(upper - lower / numBins) 
	//int bSize = (upper - lower) / numBins;// = static_cast<int>(ceil(float(upper - lower) / numBins));

	//if ((upper - lower) % numBins != 0)
	//{
	//	bSize++;
	//}


	//int curUpperBound = curLowerBound + bSize;
	////Between b(upper, lower);

	//for (unsigned int i = 0; i < counts.size(); i++)
	//{
	//	if (x >= curLowerBound && x < curUpperBound)
	//	{
	//		counts[i]++;
	//		break;
	//	}

	//	curLowerBound = curUpperBound;
	//	curUpperBound += bSize;
	//}
}

Histogram1::~Histogram1()
{
}








Maximum1::Maximum1() : max(std::numeric_limits<int>::min())
{
}

int Maximum1::getMax() const { return max; }

void Maximum1::operator() (const int x)
{
	if (x>max)
	{
		max = x;
	}
}


Maximum1::~Maximum1()
{
}







Minimum1::Minimum1() : min(std::numeric_limits<int>::max())
{
}


int Minimum1::getMin() const { return min; }
void Minimum1::operator() (int x)
{
	if (x<min)
	{
		min = x;
	}
}

Minimum1::~Minimum1()
{
}








OccuresMoreThan1::OccuresMoreThan1() : mult(-1), map()
{
}


OccuresMoreThan1::OccuresMoreThan1(const OccuresMoreThan1& c) : mult(c.mult), map() { map.insert(c.map.begin(), c.map.end()); }

void OccuresMoreThan1::operator() (int x)
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

void OccuresMoreThan1::setMultiplicity(int x) { mult = x; }

void OccuresMoreThan1::trimMap()
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
std::map<int, int> OccuresMoreThan1::getMap() const { return map; }


OccuresMoreThan1::~OccuresMoreThan1()
{
}







Size1::Size1() : size(0)
{
}

int Size1::getSize1() const { return size; }

void Size1::operator() (int ) { ++size; }


Size1::~Size1()
{
}







