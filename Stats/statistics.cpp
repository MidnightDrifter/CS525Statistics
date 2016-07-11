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
	return omt.getMap();
}

std::vector<int> Statistics::Histogram(int numBins, int upper, int lower)
{
	return std::for_each(data.begin(), data.end(), class Histogram(upper, lower, numBins)).getCounts();

}

