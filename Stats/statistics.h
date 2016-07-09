#ifndef STATISTICS_H
#define STATISTICS_H
#include <vector>    //vector
#include <algorithm> //copy
#include <ostream>   //ostream
#include <istream>   //istream
#include <map>       //map
#include "Average.h"
#include "Size.h"
#include "Maximum.h"
#include "Minimum.h"
#include "Deviation.h"
#include "Histogram.h"
#include "OccuresMoreThan.h"
#include "RemoveIf.h"



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
		void RemoveIf();
		std::map<int, int> OccuresMoreThan(int multiplicity);
		std::vector<int> Histogram(int numBins, int lower, int upper);

		//Extra credit
		void DrawHistogramH() {}
		void DrawHistogramV() {}

};

template <typename T>
Statistics::Statistics( T const* b, T const* e ) : data(e-b) {
    std::copy( b, e, data.begin() ); // we can use regular pointers to specify ranges!
}

#endif
