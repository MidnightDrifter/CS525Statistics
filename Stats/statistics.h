#ifndef STATISTICS_H
#define STATISTICS_H
#include <vector>    //vector
#include <functional>
#include <algorithm> //copy
#include <ostream>   //ostream
#include <istream>   //istream
#include <map>       //map
#include <limits>
//#include "Average.h"
//#include "Size.h"
//#include "Maximum.h"
//#include "Minimum.h"
//#include "Deviation.h"
//#include "Histogram.h"
//#include "OccuresMoreThan.h"
//#include "RemoveIf.h"



class OccuresMoreThan
{
public:
	OccuresMoreThan();
	OccuresMoreThan(const OccuresMoreThan& o);
	~OccuresMoreThan();

	void operator() (int x);
	void setMultiplicity(int x);
	void trimMap();
	std::map<int, int> getMap() const;
	//bool isLargerThanMultiplicity(int x) const;


private:
	int mult;
	std::map<int, int> map;

};


class Histogram
{
public:
	Histogram();
	Histogram(const Histogram& h);
	Histogram(int u, int l, int n);
	const Histogram& operator=(const Histogram& h);
	~Histogram();

	std::vector<int> getCounts() const;

	void operator() (int x);





private:
	int upper;
	int lower;
	int numBins;
	std::vector<int> counts;
};

class Size
{
public:
	Size();
	~Size();

	int getSize() const;
	void operator() (int x);

private:
	int size;

};


class Minimum
{
public:
	Minimum();
	~Minimum();

	int getMin() const;
	void operator() (int x);

private:
	int min;
};



class Maximum
{
public:
	Maximum();
	~Maximum();

	void operator() (const int x);
	int getMax() const;


private:
	int max;
};


class Average
{
public:
	Average();
	~Average();

	void operator() (const int x);
	float getAverage() const;
	float getSum() const;
	int getSize() const;
private:
	float sum;
	int size;
};



class Deviation
{

	/*
	Deviation() - standard deviation is a measure of how much the data is
	dispersed from the average.
	formula Deviation( x_1, ... , x_n ) = sqrt ( 1/n * sum ( x_i -a )^2 )
	Where 'a' is the Average.
	Basically deviation is an average of the squares of the distances to the average.

	*/
public:
	Deviation();
	Deviation(const Deviation& d);
	const Deviation& operator=(const Deviation& d);
	void setAverage(Average a);
	~Deviation();

	void operator() (int x);
	float getDev() const;

private:
	Average avg;
	float sumSquares;
	//float dev;


};




class Statistics {
    private:
        typedef std::vector<int> ContainerType;
        ContainerType data;
		Average avg;
		Size size;
		Maximum max;
		Minimum min;
		Deviation dev;
		Histogram hist;
		OccuresMoreThan omt;
		RemoveIf removeIf;
    public:
        Statistics();
        template <typename T> Statistics( T const* b, T const* e );
        friend std::ostream& operator<<( std::ostream& out, Statistics const& stat );
        friend std::istream& operator>>( std::istream& in, Statistics & stat );

		float Average();
		int Maximum();
		int Minimum();
		int Size();
		float Deviation();

		template <typename Pred>
		void RemoveIf(Pred p);
	
		
		
		std::map<int, int> OccuresMoreThan(int multiplicity);
		std::vector<int> Histogram(int numBins, int lower, int upper);

		//Extra credit
		void DrawHistogramH(int a, int b, int c) {}
		void DrawHistogramV(int a, int b, int c) {}

};

template <typename T>
Statistics::Statistics( T const* b, T const* e ) : data(e-b) {
    std::copy( b, e, data.begin() ); // we can use regular pointers to specify ranges!
}


template <typename Pred>
void Statistics::RemoveIf(Pred p)
{
	data.erase(std::remove_if(data.begin(), data.end(), p), data.end());
}



#endif
