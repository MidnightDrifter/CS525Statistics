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



class OccuresMoreThan1
{
public:
	OccuresMoreThan1();
	OccuresMoreThan1(const OccuresMoreThan1& o);
	~OccuresMoreThan1();

	void operator() (int x);
	void setMultiplicity(int x);
	void trimMap();
	std::map<int, int> getMap() const;
	//bool isLargerThanMultiplicity(int x) const;


private:
	int mult;
	std::map<int, int> map;

};


class Histogram1
{
public:
	Histogram1();
	Histogram1(const Histogram1& h);
	Histogram1(int u, int l, int n);
	const Histogram1& operator=(const Histogram1& h);
	~Histogram1();

	std::vector<int> getCounts() const;

	void operator() (int x);





private:
	int upper;
	int lower;
	
	int numBins;
	std::vector<int> counts;
};

class Size1
{
public:
	Size1();
	~Size1();

	int getSize1() const;
	void operator() (int x);

private:
	int size;

};


class Minimum1
{
public:
	Minimum1();
	~Minimum1();

	int getMin() const;
	void operator() (int x);

private:
	int min;
};



class Maximum1
{
public:
	Maximum1();
	~Maximum1();

	void operator() (const int x);
	int getMax() const;


private:
	int max;
};


class Average1
{
public:
	Average1();
	~Average1();

	void operator() (const int x);
	float getAverage1() const;
	float getSum() const;
	int getSize() const;
private:
	float sum;
	int size;
};



class Deviation1
{

	/*
	Deviation1() - standard Deviation1 is a measure of how much the data is
	dispersed from the average.
	formula Deviation1( x_1, ... , x_n ) = sqrt ( 1/n * sum ( x_i -a )^2 )
	Where 'a' is the Average.
	Basically Deviation1 is an average of the squares of the distances to the average.

	*/
public:
	Deviation1();
	Deviation1(const Deviation1& d);
	const Deviation1& operator=(const Deviation1& d);
	void setAverage(Average1 a);
	~Deviation1();

	void operator() (int x);
	float getDev() const;

private:
	Average1 avg;
	float sumSquares;
	//float dev;


};




class Statistics {
    private:
        typedef std::vector<int> ContainerType;
        ContainerType data;
		Average1 avg;
		Size1 size;
		Maximum1 max;
		Minimum1 min;
		Deviation1 dev;
		Histogram1 hist;
		OccuresMoreThan1 omt;
		//RemoveIf removeIf;
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
		void DrawHistogramH(int , int , int ) {}
		void DrawHistogramV(int , int , int ) {}

};

template <typename T>
Statistics::Statistics( T const* b, T const* e ) :   data(e-b), avg(), size(), max(), min(), dev(), hist(), omt() {
    std::copy( b, e, data.begin() ); // we can use regular pointers to specify ranges!
}


template <typename Pred>
void Statistics::RemoveIf(Pred p)
{
	data.erase(std::remove_if(data.begin(), data.end(), p), data.end());
}



#endif
