#pragma once
#include <vector>
//#include "Between.h"
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

